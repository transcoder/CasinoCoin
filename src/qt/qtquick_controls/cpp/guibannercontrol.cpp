#include "guibannercontrol.h"
#include "guibannerlistview.h"
#include "qmlbannerlistmodel.h"
#include "qmlbannerlistitem.h"

GUIBannerControl::GUIBannerControl( QQuickItem* a_pParent )
	: QQuickItem( a_pParent )
	, m_pAdvertsView( 0 )
{
}

GUIBannerControl::~GUIBannerControl()
{
	if ( m_pAdvertsView )
	{
		delete m_pAdvertsView;
		m_pAdvertsView = 0;
	}
}

void GUIBannerControl::InitializeAdvertsView( GUIBannerListView* a_pView )
{
	if ( a_pView )
	{
		if ( m_pAdvertsView )
		{
			delete m_pAdvertsView;
		}
		m_pAdvertsView = a_pView;
	}
}

void GUIBannerControl::slotPopulateListView( JsonActivePromotionsParser* a_pActivePromotions )
{
	if ( m_pAdvertsView && a_pActivePromotions )
	{
		QmlBannerListModel* pAdvertsModel = new QmlBannerListModel( *a_pActivePromotions );
		m_pAdvertsView->setModel( pAdvertsModel );
		delete a_pActivePromotions;
		a_pActivePromotions = 0;
	}
}

