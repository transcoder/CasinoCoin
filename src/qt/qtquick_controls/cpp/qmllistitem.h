#ifndef QMLLISTITEM_H
#define QMLLISTITEM_H

// Qt
#include <QVariant>
#include <QColor>
#include <QHash>

// ptcommon
#include "listiteminterface.h"

class QmlListItem : public ListItemInterface
{
	Q_OBJECT

public:

	enum ERoles																			/**  User-specific model roles **/
	{ ROLE_1									= Qt::UserRole + 1
	, ROLE_2									= Qt::UserRole + 2
	, ROLE_3									= Qt::UserRole + 3
	, ROLE_4									= Qt::UserRole + 4
	, ROLE_5									= Qt::UserRole + 5
	, ROLE_6									= Qt::UserRole + 6
	, ROLE_7									= Qt::UserRole + 7
	, ROLE_8									= Qt::UserRole + 8
	, ROLE_9									= Qt::UserRole + 9
	, ROLE_10									= Qt::UserRole + 10
	, ROLE_LAST									= Qt::UserRole + 11
	};

	explicit QmlListItem( QObject* a_pParent = 0 );										/** Default Constructor **/

	explicit QmlListItem( QVariant a_role1
						  , QObject* a_pParent = 0
						);																/** Constructor with first role filled **/
	explicit QmlListItem( QVariant a_role1
						  , QVariant a_role2
						  , QObject* a_pParent = 0
						);																/** Contstructor with first two roles filled **/
	explicit QmlListItem( QVariant a_role1
						  , QVariant a_role2
						  , QVariant a_role3
						  , QObject* a_pParent = 0
						);																/** Contstructor with first three roles filled **/
	explicit QmlListItem( QVariant a_role1
						  , QVariant a_role2
						  , QVariant a_role3
						  , QVariant a_role4
						  , QObject* a_pParent = 0
						);																/** Contstructor with first four roles filled **/
	explicit QmlListItem( QVariant a_role1
						  , QVariant a_role2
						  , QVariant a_role3
						  , QVariant a_role4
						  , QVariant a_role5
						  , QObject* a_pParent = 0
						);																/** Contstructor with first five roles filled **/
	explicit QmlListItem( QVariant a_role1
						  , QVariant a_role2
						  , QVariant a_role3
						  , QVariant a_role4
						  , QVariant a_role5
						  , QVariant a_role6
						  , QObject* a_pParent = 0
						);																/** Contstructor with first six roles filled **/
	explicit QmlListItem( QVariant a_role1
						  , QVariant a_role2
						  , QVariant a_role3
						  , QVariant a_role4
						  , QVariant a_role5
						  , QVariant a_role6
						  , QVariant a_role7
						  , QObject* a_pParent = 0
						);																/** Contstructor with first seven roles filled **/
	explicit QmlListItem( QVariant a_role1
						  , QVariant a_role2
						  , QVariant a_role3
						  , QVariant a_role4
						  , QVariant a_role5
						  , QVariant a_role6
						  , QVariant a_role7
						  , QVariant a_role8
						  , QObject* a_pParent = 0
						);																/** Contstructor with first eight roles filled **/
	explicit QmlListItem( QVariant a_role1
						  , QVariant a_role2
						  , QVariant a_role3
						  , QVariant a_role4
						  , QVariant a_role5
						  , QVariant a_role6
						  , QVariant a_role7
						  , QVariant a_role8
						  , QVariant a_role9
						  , QObject* a_pParent = 0
						);																/** Contstructor with first nine roles filled **/

	QmlListItem( const QmlListItem& a_rOther );											/** Copy constructor **/
	virtual ~QmlListItem();																/** Destructor **/

	virtual QVariant GetData( int a_iRole ) const;										/** Retrieve role-specific data from class **/
	virtual bool SetData( int a_iRole, QVariant a_variantData );						/** Sets given value at specified role **/
	virtual QHash<int, QByteArray> RoleNames() const;									/** Define class-specific roles **/

private:
	QHash<ERoles, QVariant> m_aDataHash;												/** Container keeping all item-specific roles **/
};

#endif // QMLLISTITEM_H
