#ifndef QMLMENUTOOLBARITEM_H
#define QMLMENUTOOLBARITEM_H

#include "qmllistitem.h"

class QmlMenuToolbarItem : public QmlListItem
{
	Q_OBJECT
	Q_ENUMS( EMenuToolbarRoles )

public:
	enum EMenuToolbarRoles																/**  User-specific model roles **/
	{ ROLE_TEXT									= ROLE_1
	, ROLE_DESCRIPTION							= ROLE_2
	, ROLE_IMAGE_HOVER_SOURCE					= ROLE_3
	, ROLE_IMAGE_NORMAL_SOURCE					= ROLE_4
	, ROLE_INTERNAL_TYPE						= ROLE_5
	};

	explicit QmlMenuToolbarItem
					( QString a_strText
					, QString a_strDescription
					, QString a_strImageHoverSource
					, QString a_strImageNormalSource
					, int a_iType
					, QObject *a_pParent = 0
					);

	explicit QmlMenuToolbarItem( QObject *a_pParent = 0 );
	virtual ~QmlMenuToolbarItem();

	virtual QHash<int, QByteArray> RoleNames() const;									/** Define class-specific roles **/

};

#endif // QMLMENUTOOLBARITEM_H
