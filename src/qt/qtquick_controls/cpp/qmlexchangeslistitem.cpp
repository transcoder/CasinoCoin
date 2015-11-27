#include "qmlexchangeslistitem.h"

#include <QDebug>

QmlExchangesListItem::QmlExchangesListItem(QString a_strImageSource, QString a_strDestinationUrl, QString a_strExchangesName, double a_dBidPrice, double a_dAskPrice, double a_dLastPrice, QString a_strDescription, QObject* a_pParent )
	: QmlListItem	( QVariant( a_strImageSource )
					, QVariant( a_strDestinationUrl )
					, QVariant( a_strExchangesName )
					, QVariant( GetFormattedPrice( a_dBidPrice ) )
					, QVariant( GetFormattedPrice( a_dAskPrice ) )
					, QVariant( GetFormattedPrice( a_dLastPrice ) )
					, QVariant( a_strDescription )
					, a_pParent
					)
{
}

QmlExchangesListItem::QmlExchangesListItem( const JsonSingleActiveExchange& a_rExchangeDescription, QObject* a_pParent )
	: QmlListItem	( QVariant( a_rExchangeDescription.getImageName() )
					, QVariant( a_rExchangeDescription.getAccessUrl() )
					, QVariant( a_rExchangeDescription.getExchangeName() )
					, QVariant( GetFormattedPrice( a_rExchangeDescription.getLastBidPriceBTC() ) )
					, QVariant( GetFormattedPrice( a_rExchangeDescription.getLastAskPriceBTC() ) )
					, QVariant( GetFormattedPrice( a_rExchangeDescription.getLastPriceBTC() ) )
					, QVariant( a_rExchangeDescription.getDescription() )
					, a_pParent
					)
{
}

QmlExchangesListItem::QmlExchangesListItem( QObject* a_pParent )
	: QmlListItem( QVariant( "" ), QVariant( "" ), QVariant( "" ), QVariant( "" ), QVariant( "" ), QVariant( "" ), QVariant( "" ), a_pParent )
{
}

QmlExchangesListItem::~QmlExchangesListItem()
{

}

QHash<int, QByteArray> QmlExchangesListItem::RoleNames() const
{
	QHash<int, QByteArray> aRoleNames;
	aRoleNames[ROLE_IMAGE_SOURCE]		= "m_imageSource";
	aRoleNames[ROLE_DESTINATION_URL]	= "m_destinationUrl";
	aRoleNames[ROLE_EXCHANGE_NAME]		= "m_exchangeName";
	aRoleNames[ROLE_BID_PRICE]			= "m_bidPrice";
	aRoleNames[ROLE_ASK_PRICE]			= "m_askPrice";
	aRoleNames[ROLE_LAST_PRICE]			= "m_lastPrice";
	aRoleNames[ROLE_DESCRIPTION]		= "m_description";
	return aRoleNames;
}

QString QmlExchangesListItem::GetFormattedPrice(double a_dPrice)
{
	return QString::number( a_dPrice, 'f', 8 );
}
