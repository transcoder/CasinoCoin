#include "qmlexchangeslistmodel.h"

#include "qmlexchangeslistitem.h"

#include "../../CSCPublicAPI/jsonactiveexchangesparser.h"
#include "../../CSCPublicAPI/jsonsingleactiveexchange.h"

#include <QDebug>

QmlExchangesListModel::QmlExchangesListModel( QObject* a_pParent )
	: QmlListModel( new QmlExchangesListItem( 0 ), a_pParent )
{
}

QmlExchangesListModel::QmlExchangesListModel
								( const JsonActiveExchangesParser& a_rActiveExchanges
								, QObject* a_pParent
								)
	: QmlListModel( new QmlExchangesListItem( 0 ), a_pParent )
{
	foreach( const JsonSingleActiveExchange& rExchange, a_rActiveExchanges.GetExchanges() )
	{
		append( new QmlExchangesListItem( rExchange, this ) );
	}
}

QmlExchangesListModel::~QmlExchangesListModel()
{

}
