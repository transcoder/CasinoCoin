#include "qmlmenutoolbarmodel.h"

#include "qmlmenutoolbaritem.h"
#include <QDebug>

QmlMenuToolbarModel::QmlMenuToolbarModel( QObject* a_pParent )
	: QmlListModel( new QmlMenuToolbarItem(), a_pParent )
{
}

QmlMenuToolbarModel::~QmlMenuToolbarModel()
{

}

