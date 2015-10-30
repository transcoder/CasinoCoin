#include "guibannerlistview.h"

#include "qmlbannerlistitem.h"
#include "qmlbannerlistmodel.h"
#include "qmllistmodel.h"

#include <QDesktopServices>
#include <QUrl>

GUIBannerListView::GUIBannerListView( QQuickItem* a_pParent )
	: QQuickItem( a_pParent )
	, m_pModel( 0 )
{
}

void GUIBannerListView::Clear()
{
	if ( m_pModel )
	{
		m_pModel->clear();
	}
}

void GUIBannerListView::OnClicked( int a_iItemIndex )
{
	if ( m_pModel )
	{
		QString strUrl = m_pModel->GetData( a_iItemIndex, QmlBannerListItem::ROLE_DESTINATION_URL ).toString();
		QDesktopServices::openUrl( QUrl( strUrl ) );
	}
}

GUIBannerListView::~GUIBannerListView()
{
	if ( m_pModel )
	{
		delete m_pModel;
		m_pModel = 0;
	}
}

void GUIBannerListView::SetModel( QmlBannerListModel* a_pModel )
{
	if ( m_pModel )
	{
		delete m_pModel;
	}
	m_pModel = a_pModel;
	emit signalModelChanged();
}
