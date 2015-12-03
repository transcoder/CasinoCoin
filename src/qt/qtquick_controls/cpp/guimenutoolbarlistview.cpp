#include "guimenutoolbarlistview.h"

#include "qmlmenutoolbarmodel.h"
#include "qmlmenutoolbaritem.h"

GUIMenuToolbarListView::GUIMenuToolbarListView( QQuickItem* a_pParent )
	: QQuickItem( a_pParent )
	, m_pModel( 0 )
{
}

void GUIMenuToolbarListView::Clear()
{
	if ( m_pModel )
	{
		m_pModel->clear();
	}
}

void GUIMenuToolbarListView::OnClicked( int a_iItemIndex )
{
	if ( m_pModel )
	{
		m_pModel->SetCurrentItemIndex( a_iItemIndex );
	}
}

GUIMenuToolbarListView::~GUIMenuToolbarListView()
{
	if ( m_pModel )
	{
		delete m_pModel;
		m_pModel = 0;
	}
}

void GUIMenuToolbarListView::SetModel( QmlMenuToolbarModel* a_pModel )
{
	if ( m_pModel )
	{
		delete m_pModel;
	}
	m_pModel = a_pModel;
	emit signalModelChanged();
}


