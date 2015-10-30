#ifndef LISTITEMINTERFACE_H
#define LISTITEMINTERFACE_H

#include <QObject>

class ListItemInterface : public QObject
{
	Q_OBJECT
public:

	ListItemInterface( QObject* a_pParent = 0 ) : QObject( a_pParent ){}	/** Constructor **/
	virtual ~ListItemInterface() {}										/** Destructor **/

	virtual QVariant GetData( int a_iRole ) const = 0;					/** Data Accesor **/
	virtual bool SetData( int a_iRole, QVariant a_variantData ) = 0;	/** Sets given value at specified role **/
	virtual QHash<int, QByteArray> RoleNames() const = 0;				/** User roles in model **/
};

#endif // LISTITEMINTERFACE_H
