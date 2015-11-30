#include "guiexchangeswidget.h"

#include <QHBoxLayout>
#include <QCheckBox>
#include <QQuickView>
#include <QQmlContext>

#include "gui20_skin.h"

// qml
#include "guiexchangescontrol.h"
#include "guiexchangeslistview.h"
#include "qmlexchangeslistmodel.h"
#include "qmlexchangeslistitem.h"
#include "qmlimageprovider.h"

// web
#include "../../CSCPublicAPI/casinocoinwebapi.h"
#include "../../CSCPublicAPI/casinocoinwebapiparser.h"


GUIExchangesWidget::GUIExchangesWidget(QWidget *parent)
	: QWidget(parent)
	, m_pExchangesControl( 0 )
	, m_pWebApiParserTemporary( new CasinoCoinWebAPIParser( this ) )
	, m_pWebApiTemporary( new CasinoCoinWebAPI( this ) )
	, m_pQmlImageProvider( 0 )
{
	registerCustomQmlTypes();
	connect( m_pWebApiTemporary, SIGNAL( signalResponseReady(const QByteArray&)), m_pWebApiParserTemporary, SLOT( slotParseAnswer(const QByteArray&)), Qt::UniqueConnection );
	connect( m_pWebApiTemporary, SIGNAL( signalNetworkError(QNetworkReply::NetworkError,const QUrl)), m_pWebApiParserTemporary, SLOT( slotNetworkError(QNetworkReply::NetworkError,const QUrl)), Qt::UniqueConnection );
	connect( m_pWebApiParserTemporary, SIGNAL( signalActiveExchangesParsed(JsonActiveExchangesParser*)), this, SLOT( slotPopulateFromWeb(JsonActiveExchangesParser*)), Qt::UniqueConnection );

	SetupRefreshTimer();
	m_timerRefresh.start();
}

GUIExchangesWidget::~GUIExchangesWidget()
{
	// member objects are moved to qml engine and it manages their instances
}

void GUIExchangesWidget::registerCustomQmlTypes()
{
	qmlRegisterType<GUIExchangesControl>("CasinoCoinControls", 1, 0, "GUIExchangesControl" );
	qmlRegisterType<GUIExchangesListView>("CasinoCoinControls", 1, 0, "GUIExchangesListView" );
	qmlRegisterType<QmlExchangesListModel>("CasinoCoinControls", 1, 0, "QmlExchangesListModel" );
}

void GUIExchangesWidget::SetupRefreshTimer()
{
	m_timerRefresh.setSingleShot( false );
	m_timerRefresh.setInterval( 1000 * 60 );
	connect( &m_timerRefresh, SIGNAL( timeout() ), this, SLOT( slotPopulateExchangesFromWeb() ), Qt::UniqueConnection );
}

QWidget* GUIExchangesWidget::dockQmlToWidget()
{
	QQuickView* pExchangesWindow = new QQuickView;
	QWidget* pPlaceHolder = 0;
	if ( pExchangesWindow )
	{
		QQmlContext* pContext = pExchangesWindow->rootContext();
		if ( pContext )
		{
			pContext->setContextProperty( "GUI20Skin", &GUI20Skin::Instance() );
		}
		QQmlEngine* pEngine = pExchangesWindow->engine();
		if ( pEngine )
		{
			m_pQmlImageProvider = new QmlImageProvider();
			pEngine->addImageProvider( "exchangesImages", m_pQmlImageProvider );
		}
		pExchangesWindow->setSource( QUrl( QStringLiteral( "qrc:/qml/qtquick_controls/qml/QmlGUIExchangesWindow.qml" ) ) );
		QQuickItem* pRootObject = pExchangesWindow->rootObject();
		if ( pRootObject )
		{
			m_pExchangesControl = pRootObject->findChild<GUIExchangesControl*>();
			if ( m_pExchangesControl )
			{
			}
		}
		pPlaceHolder = QWidget::createWindowContainer( pExchangesWindow, this );
		if ( pPlaceHolder )
		{
            pPlaceHolder->setMinimumSize( 500, 200 );
			pPlaceHolder->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );
		}
	}

	return pPlaceHolder;
}

void GUIExchangesWidget::slotPopulateExchangesFromWeb()
{
	if ( m_pWebApiTemporary )
	{
		m_pWebApiTemporary->GetActiveExchanges();
	}
}

void GUIExchangesWidget::slotPopulateFromWeb( JsonActiveExchangesParser* a_pExchangesParser )
{
	if ( a_pExchangesParser )
	{
		a_pExchangesParser->AddImagesToPool( m_pQmlImageProvider );
	}
	if ( m_pExchangesControl )
	{
		m_pExchangesControl->slotPopulateListView( a_pExchangesParser );
	}
}

