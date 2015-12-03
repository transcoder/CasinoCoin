#include "qmllistitem.h"

#include <QDebug>

QmlListItem::QmlListItem( QObject* a_pParent )
	: ListItemInterface( a_pParent )
{
	// Nothing
}

QmlListItem::QmlListItem( QVariant a_role1
						  , QObject* a_pParent
						  )
	: ListItemInterface( a_pParent )
{
	m_aDataHash[ROLE_1] = a_role1;
}

QmlListItem::QmlListItem( QVariant a_role1
						  , QVariant a_role2
						  , QObject* a_pParent
						  )
	: ListItemInterface( a_pParent )
{
	m_aDataHash[ROLE_1] = a_role1;
	m_aDataHash[ROLE_2] = a_role2;
}

QmlListItem::QmlListItem( QVariant a_role1
						  , QVariant a_role2
						  , QVariant a_role3
						  , QObject* a_pParent
						  )
	: ListItemInterface( a_pParent )
{
	m_aDataHash[ROLE_1] = a_role1;
	m_aDataHash[ROLE_2] = a_role2;
	m_aDataHash[ROLE_3] = a_role3;
}

QmlListItem::QmlListItem( QVariant a_role1
						  , QVariant a_role2
						  , QVariant a_role3
						  , QVariant a_role4
						  , QObject* a_pParent
						  )
	: ListItemInterface( a_pParent )
{
	m_aDataHash[ROLE_1] = a_role1;
	m_aDataHash[ROLE_2] = a_role2;
	m_aDataHash[ROLE_3] = a_role3;
	m_aDataHash[ROLE_4] = a_role4;
}

QmlListItem::QmlListItem( QVariant a_role1
						  , QVariant a_role2
						  , QVariant a_role3
						  , QVariant a_role4
						  , QVariant a_role5
						  , QObject* a_pParent
						  )
	: ListItemInterface( a_pParent )
{
	m_aDataHash[ROLE_1] = a_role1;
	m_aDataHash[ROLE_2] = a_role2;
	m_aDataHash[ROLE_3] = a_role3;
	m_aDataHash[ROLE_4] = a_role4;
	m_aDataHash[ROLE_5] = a_role5;
}

QmlListItem::QmlListItem( QVariant a_role1
						  , QVariant a_role2
						  , QVariant a_role3
						  , QVariant a_role4
						  , QVariant a_role5
						  , QVariant a_role6
						  , QObject* a_pParent
						  )
	: ListItemInterface( a_pParent )
{
	m_aDataHash[ROLE_1] = a_role1;
	m_aDataHash[ROLE_2] = a_role2;
	m_aDataHash[ROLE_3] = a_role3;
	m_aDataHash[ROLE_4] = a_role4;
	m_aDataHash[ROLE_5] = a_role5;
	m_aDataHash[ROLE_6] = a_role6;
}

QmlListItem::QmlListItem( QVariant a_role1
						  , QVariant a_role2
						  , QVariant a_role3
						  , QVariant a_role4
						  , QVariant a_role5
						  , QVariant a_role6
						  , QVariant a_role7
						  , QObject* a_pParent
						  )
	: ListItemInterface( a_pParent )
{
	m_aDataHash[ROLE_1] = a_role1;
	m_aDataHash[ROLE_2] = a_role2;
	m_aDataHash[ROLE_3] = a_role3;
	m_aDataHash[ROLE_4] = a_role4;
	m_aDataHash[ROLE_5] = a_role5;
	m_aDataHash[ROLE_6] = a_role6;
	m_aDataHash[ROLE_7] = a_role7;
}

QmlListItem::QmlListItem( QVariant a_role1
						  , QVariant a_role2
						  , QVariant a_role3
						  , QVariant a_role4
						  , QVariant a_role5
						  , QVariant a_role6
						  , QVariant a_role7
						  , QVariant a_role8
						  , QObject* a_pParent
						  )
	: ListItemInterface( a_pParent )
{
	m_aDataHash[ROLE_1] = a_role1;
	m_aDataHash[ROLE_2] = a_role2;
	m_aDataHash[ROLE_3] = a_role3;
	m_aDataHash[ROLE_4] = a_role4;
	m_aDataHash[ROLE_5] = a_role5;
	m_aDataHash[ROLE_6] = a_role6;
	m_aDataHash[ROLE_7] = a_role7;
	m_aDataHash[ROLE_8] = a_role8;
}

QmlListItem::QmlListItem( QVariant a_role1
						  , QVariant a_role2
						  , QVariant a_role3
						  , QVariant a_role4
						  , QVariant a_role5
						  , QVariant a_role6
						  , QVariant a_role7
						  , QVariant a_role8
						  , QVariant a_role9
						  , QObject* a_pParent
						  )
	: ListItemInterface( a_pParent )
{
	m_aDataHash[ROLE_1] = a_role1;
	m_aDataHash[ROLE_2] = a_role2;
	m_aDataHash[ROLE_3] = a_role3;
	m_aDataHash[ROLE_4] = a_role4;
	m_aDataHash[ROLE_5] = a_role5;
	m_aDataHash[ROLE_6] = a_role6;
	m_aDataHash[ROLE_7] = a_role7;
	m_aDataHash[ROLE_8] = a_role8;
	m_aDataHash[ROLE_9] = a_role9;
}

QmlListItem::QmlListItem( const QmlListItem& a_rOther )
	: ListItemInterface( a_rOther.parent() )
	, m_aDataHash( a_rOther.m_aDataHash )
{
	// Nothing
}

QmlListItem::~QmlListItem()
{
	// Nothing
}

QVariant QmlListItem::GetData( int a_iRole ) const
{
	return m_aDataHash[static_cast<ERoles>( a_iRole )];
}

bool QmlListItem::SetData( int a_iRole, QVariant a_variantData )
{

	if ( m_aDataHash[static_cast<ERoles>( a_iRole )] != a_variantData )
	{
		m_aDataHash[static_cast<ERoles>( a_iRole )] = a_variantData;
		return true;
	}
	return false;
}

QHash<int, QByteArray> QmlListItem::RoleNames() const
{
	QHash<int, QByteArray> aRoleNames;
	aRoleNames[ROLE_1]		= "m_role1";
	aRoleNames[ROLE_2]		= "m_role2";
	aRoleNames[ROLE_3]		= "m_role3";
	aRoleNames[ROLE_4]		= "m_role4";
	aRoleNames[ROLE_5]		= "m_role5";
	aRoleNames[ROLE_6]		= "m_role6";
	aRoleNames[ROLE_7]		= "m_role7";
	aRoleNames[ROLE_8]		= "m_role8";
    aRoleNames[ROLE_9]		= "m_role9";
	return aRoleNames;
}

