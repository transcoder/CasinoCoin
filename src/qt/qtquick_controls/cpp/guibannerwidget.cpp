#include "guibannerwidget.h"

#include <QHBoxLayout>
#include <QCheckBox>
#include <QtQuick/QQuickView>

// qml
#include "guibannercontrol.h"
#include "guibannerlistview.h"
#include "qmlbannerlistmodel.h"
#include "qmlbannerlistitem.h"
#include "qmlimageprovider.h"

// web
#include "../../CSCPublicAPI/casinocoinwebapi.h"
#include "../../CSCPublicAPI/casinocoinwebapiparser.h"

GUIBannerWidget::GUIBannerWidget(QWidget *parent)
	: QWidget(parent)
	, m_pBannerControl( 0 )
	, m_pWebApiParserTemporary( new CasinoCoinWebAPIParser( this ) )
	, m_pWebApiTemporary( new CasinoCoinWebAPI( this ) )
	, m_pQmlImageProvider( 0 )
{
	registerCustomQmlTypes();
	connect( m_pWebApiTemporary, SIGNAL( signalResponseReady(const QByteArray&)), m_pWebApiParserTemporary, SLOT( slotParseAnswer(const QByteArray&)), Qt::UniqueConnection );
	connect( m_pWebApiTemporary, SIGNAL( signalNetworkError(QNetworkReply::NetworkError,const QUrl)), m_pWebApiParserTemporary, SLOT( slotNetworkError(QNetworkReply::NetworkError,const QUrl)), Qt::UniqueConnection );
	connect( m_pWebApiParserTemporary, SIGNAL( signalActivePromotionsParsed(JsonActivePromotionsParser*)), this, SLOT( slotPopulateFromWeb(JsonActivePromotionsParser*)), Qt::UniqueConnection );
}

GUIBannerWidget::~GUIBannerWidget()
{

}

void GUIBannerWidget::registerCustomQmlTypes()
{
	qmlRegisterType<GUIBannerControl>("CasinoCoinControls", 1, 0, "GUIBannerControl" );
	qmlRegisterType<GUIBannerListView>("CasinoCoinControls", 1, 0, "GUIBannerListView" );
	qmlRegisterType<QmlBannerListModel>("CasinoCoinControls", 1, 0, "QmlBannerListModel" );
}

QWidget* GUIBannerWidget::dockQmlToWidget()
{
	QQuickView* pBannerWindow = new QQuickView;
	pBannerWindow->setSource( QUrl( QStringLiteral( "qrc:/qml/qtquick_controls/qml/QmlGUIBannerWindow.qml" ) ) );
	QQmlEngine* pEngine = pBannerWindow->engine();
	if ( pEngine )
	{
		m_pQmlImageProvider = new QmlImageProvider();
		pEngine->addImageProvider( "advertImages", m_pQmlImageProvider );
	}
	QWidget* pPlaceHolder = QWidget::createWindowContainer( pBannerWindow, this );
	pPlaceHolder->setMinimumSize( 445, 120 );
	pPlaceHolder->setMaximumSize( 445, 120 );
	pPlaceHolder->setStyleSheet( "background-color: rgb(242, 241, 240);");
	QQuickItem* pRootObject = pBannerWindow->rootObject();
	if ( pRootObject )
	{
		m_pBannerControl = pRootObject->findChild<GUIBannerControl*>();
		if ( m_pBannerControl )
		{
			m_pBannerControl->setWidth( ( 115 * 3 ) + ( 4 * 10 ) + 60 );
			m_pBannerControl->setHeight( 115 );
		}
	}

	return pPlaceHolder;
}

void GUIBannerWidget::PopulateBannerFromWeb()
{
	if ( m_pWebApiTemporary )
	{
		m_pWebApiTemporary->GetActivePromotions();
	}
}

void GUIBannerWidget::slotPopulateFromWeb( JsonActivePromotionsParser* a_pPromotionsParser )
{
	if ( a_pPromotionsParser )
	{
		a_pPromotionsParser->AddImagesToPool( m_pQmlImageProvider );
	}
	if ( m_pBannerControl )
	{
		m_pBannerControl->slotPopulateListView( a_pPromotionsParser );
	}
}
