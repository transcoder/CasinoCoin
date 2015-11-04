#ifndef QMLMENUTOOLBARMODEL_H
#define QMLMENUTOOLBARMODEL_H

#include "qmllistmodel.h"

class QmlMenuToolbarItem;

class QmlMenuToolbarModel : public QmlListModel
{
	Q_OBJECT
public:
	explicit QmlMenuToolbarModel( QObject* a_pParent = 0 );
	virtual ~QmlMenuToolbarModel();																			/** Destructor **/
};

#endif // QMLMENUTOOLBARMODEL_H
