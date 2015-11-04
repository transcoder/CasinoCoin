#include "guimenutoolbarwidget.h"

#include "guimenutoolbarcontrol.h"
#include "guimenutoolbarlistview.h"
#include "qmlmenutoolbarmodel.h"
#include "qmlmenutoolbaritem.h"

#include "qmlimageprovider.h"
#include "gui20_skin.h"

#include <QQuickView>
#include <QQmlContext>

GUIMenuToolbarWidget::GUIMenuToolbarWidget( QWidget *a_pParent )
	: QWidget( a_pParent )
	, m_pToolbarControl( 0 )
	, m_pQmlImageProvider( 0 )
{
	registerCustomQmlTypes();
}

GUIMenuToolbarWidget::~GUIMenuToolbarWidget()
{
	if ( m_pQmlImageProvider )
	{
		delete m_pQmlImageProvider;
		m_pQmlImageProvider = 0;
	}
	if( m_pToolbarControl )
	{
		delete m_pToolbarControl;
		m_pToolbarControl = 0;
	}
}

void GUIMenuToolbarWidget::registerCustomQmlTypes()
{
	qmlRegisterType<GUIMenuToolbarControl>("CasinoCoinControls", 1, 0, "GUIMenuToolbarControl" );
	qmlRegisterType<GUIMenuToolbarListView>("CasinoCoinControls", 1, 0, "GUIMenuToolbarListView" );
	qmlRegisterType<QmlMenuToolbarModel>("CasinoCoinControls", 1, 0, "QmlMenuToolbarModel" );
}

void GUIMenuToolbarWidget::slotCurrentItemChanged()
{
	if ( m_pToolbarControl )
	{
		GUIMenuToolbarListView* pListView = m_pToolbarControl->GetMenuToolbarView();
		if ( pListView )
		{
			QmlMenuToolbarModel* pModel = pListView->GetModel();
			if ( pModel )
			{
				emit signalItemClicked( static_cast<GUIMenuToolbarControl::EMenuToolbarItemTypes>( pModel->GetData( pModel->GetCurrentItemIndex(), QmlMenuToolbarItem::ROLE_INTERNAL_TYPE ).toInt() ) );
			}
		}
	}
}

QWidget* GUIMenuToolbarWidget::dockQmlToWidget()
{
	QQuickView* pMenuToolbarWindow = new QQuickView;
	QQmlContext* pContext = pMenuToolbarWindow->rootContext();
	if ( pContext )
	{
		pContext->setContextProperty( "GUI20Skin", &GUI20Skin::Instance() );
	}
	QQmlEngine* pEngine = pMenuToolbarWindow->engine();
	if ( pEngine )
	{
		m_pQmlImageProvider = new QmlImageProvider();
		pEngine->addImageProvider( "mainToolBarImages", m_pQmlImageProvider );
	}
	pMenuToolbarWindow->setSource( QUrl( QStringLiteral( "qrc:/qml/qtquick_controls/qml/QmlGUIMenuToolbarWindow.qml" ) ) );
	QQuickItem* pRootObject = pMenuToolbarWindow->rootObject();
	if ( pRootObject )
	{
		m_pToolbarControl = pRootObject->findChild<GUIMenuToolbarControl*>();
		if ( m_pToolbarControl )
		{
			connect( m_pToolbarControl, SIGNAL( signalCurrentItemIndexChanged() ), this, SLOT( slotCurrentItemChanged() ), Qt::UniqueConnection );
		}
	}
	QWidget* pPlaceHolder = QWidget::createWindowContainer( pMenuToolbarWindow, this );
	if ( pPlaceHolder )
	{
		pPlaceHolder->setMinimumHeight( 82 );
	}
	return pPlaceHolder;
}

void GUIMenuToolbarWidget::SetCurrentItemType( GUIMenuToolbarControl::EMenuToolbarItemTypes a_eType )
{
	if ( m_pToolbarControl )
	{
		GUIMenuToolbarListView* pListView = m_pToolbarControl->GetMenuToolbarView();
		if ( pListView )
		{
			QmlMenuToolbarModel* pModel = pListView->GetModel();
			if ( pModel )
			{
				pModel->SetCurrentItemIndex( pModel->GetItemIndex( QmlMenuToolbarItem::ROLE_INTERNAL_TYPE, QVariant( a_eType ) ) );
			}
		}
	}
}

