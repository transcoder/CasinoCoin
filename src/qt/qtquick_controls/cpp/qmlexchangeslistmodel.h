#ifndef QMLEXCHANGESLISTMODEL_H
#define QMLEXCHANGESLISTMODEL_H

#include "qmllistmodel.h"

class QmlExchangesListItem;
class JsonActiveExchangesParser;

class QmlExchangesListModel : public QmlListModel
{
	Q_OBJECT
public:
	explicit QmlExchangesListModel( QObject* a_pParent = 0 );
	explicit QmlExchangesListModel
						( const JsonActiveExchangesParser& a_rActiveExchanges
						, QObject* a_pParent = 0
						);
	virtual ~QmlExchangesListModel();																			/** Destructor **/

signals:

public slots:

};

#endif // QMLEXCHANGESLISTMODEL_H
