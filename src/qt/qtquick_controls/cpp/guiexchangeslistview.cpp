#include "guiexchangeslistview.h"

#include "qmlexchangeslistitem.h"
#include "qmlexchangeslistmodel.h"
#include "qmllistmodel.h"

#include <QDesktopServices>
#include <QUrl>

GUIExchangesListView::GUIExchangesListView( QQuickItem* a_pParent )
	: QQuickItem( a_pParent )
	, m_pModel( 0 )
{
}

void GUIExchangesListView::clear()
{
	if ( m_pModel )
	{
		m_pModel->clear();
	}
}

void GUIExchangesListView::onClicked( int a_iItemIndex )
{
	if ( m_pModel )
	{
		QString strUrl = m_pModel->GetData( a_iItemIndex, QmlExchangesListItem::ROLE_DESTINATION_URL ).toString();
		QDesktopServices::openUrl( QUrl( strUrl ) );
	}
}

GUIExchangesListView::~GUIExchangesListView()
{
	if ( m_pModel )
	{
		delete m_pModel;
		m_pModel = 0;
	}
}

void GUIExchangesListView::setModel( QmlExchangesListModel* a_pModel )
{
	if ( m_pModel )
	{
		delete m_pModel;
	}
	m_pModel = a_pModel;
	emit signalModelChanged();
}
