#include "guiexchangescontrol.h"
#include "guiexchangeslistview.h"
#include "qmlexchangeslistmodel.h"
#include "qmlexchangeslistitem.h"

GUIExchangesControl::GUIExchangesControl( QQuickItem* a_pParent )
	: QQuickItem( a_pParent )
	, m_pExchangesView( 0 )
{
}

GUIExchangesControl::~GUIExchangesControl()
{
	if ( m_pExchangesView )
	{
		delete m_pExchangesView;
		m_pExchangesView = 0;
	}
}

void GUIExchangesControl::initializeExchangesView( GUIExchangesListView* a_pView )
{
	if ( a_pView )
	{
		if ( m_pExchangesView )
		{
			delete m_pExchangesView;
		}
		m_pExchangesView = a_pView;
	}
}

void GUIExchangesControl::slotPopulateListView( JsonActiveExchangesParser* a_pActiveExchanges )
{
	if ( m_pExchangesView && a_pActiveExchanges )
	{
		QmlExchangesListModel* pExchangesModel = new QmlExchangesListModel( *a_pActiveExchanges );
		m_pExchangesView->setModel( pExchangesModel );
		delete a_pActiveExchanges;
		a_pActiveExchanges = 0;
	}
}

