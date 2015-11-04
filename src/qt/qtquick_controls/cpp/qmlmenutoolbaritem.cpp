#include "qmlmenutoolbaritem.h"

#include <QDebug>

QmlMenuToolbarItem::QmlMenuToolbarItem
								( QString a_strText
								, QString a_strDescription
								, QString a_strImageHoverSource
								, QString a_strImageNormalSource
								, int a_iType
								, QObject *a_pParent
								)
	: QmlListItem( QVariant( a_strText ), QVariant( a_strDescription ), QVariant( a_strImageHoverSource ), QVariant( a_strImageNormalSource ), QVariant( a_iType ), a_pParent )
{
}

QmlMenuToolbarItem::QmlMenuToolbarItem( QObject* a_pParent )
	: QmlListItem( QVariant( "" ), QVariant( "" ), QVariant( "" ), QVariant( "" ), QVariant( -1 ), a_pParent )
{
}

QmlMenuToolbarItem::~QmlMenuToolbarItem()
{

}

QHash<int, QByteArray> QmlMenuToolbarItem::RoleNames() const
{
	QHash<int, QByteArray> aRoleNames;
	aRoleNames[ROLE_TEXT]					= "m_text";
	aRoleNames[ROLE_DESCRIPTION]			= "m_description";
	aRoleNames[ROLE_IMAGE_HOVER_SOURCE]		= "m_imageHoverSource";
	aRoleNames[ROLE_IMAGE_NORMAL_SOURCE]	= "m_imageNormalSource";
	aRoleNames[ROLE_INTERNAL_TYPE]			= "m_internalType";
	return aRoleNames;
}

