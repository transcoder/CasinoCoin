#include "qmlexchangeslistitem.h"

#include <QDebug>
#include <QDateTime>

QmlExchangesListItem::QmlExchangesListItem(QString a_strImageSource,
                                           QString a_strDestinationUrl,
                                           QString a_strExchangesName,
                                           double a_dBidPrice,
                                           double a_dAskPrice,
                                           double a_dLastPrice,
                                           QString a_strDescription,
                                           double a_dVolume24H,
                                           QString a_strLastUpdateTime,
                                           QObject* a_pParent )
	: QmlListItem	( QVariant( a_strImageSource )
					, QVariant( a_strDestinationUrl )
					, QVariant( a_strExchangesName )
                    , QVariant( getFormattedPrice( a_dBidPrice ) )
                    , QVariant( getFormattedPrice( a_dAskPrice ) )
                    , QVariant( getFormattedPrice( a_dLastPrice ) )
					, QVariant( a_strDescription )
                    , QVariant( QString::number(a_dVolume24H) )
                    , QVariant( getFormattedDateTime(a_strLastUpdateTime) )
					, a_pParent
					)
{
}

QmlExchangesListItem::QmlExchangesListItem( const JsonSingleActiveExchange& a_rExchangeDescription, QObject* a_pParent )
	: QmlListItem	( QVariant( a_rExchangeDescription.getImageName() )
					, QVariant( a_rExchangeDescription.getAccessUrl() )
					, QVariant( a_rExchangeDescription.getExchangeName() )
                    , QVariant( getFormattedPrice( a_rExchangeDescription.getLastBidPriceBTC() ) )
                    , QVariant( getFormattedPrice( a_rExchangeDescription.getLastAskPriceBTC() ) )
                    , QVariant( getFormattedPrice( a_rExchangeDescription.getLastPriceBTC() ) )
					, QVariant( a_rExchangeDescription.getDescription() )
                    , QVariant( QString::number(a_rExchangeDescription.getVolume24H()) )
                    , QVariant( getFormattedDateTime( a_rExchangeDescription.getLastUpdateTime() ) )
					, a_pParent
					)
{
}

QmlExchangesListItem::QmlExchangesListItem( QObject* a_pParent )
    : QmlListItem( QVariant( "" ), QVariant( "" ), QVariant( "" ), QVariant( "" ), QVariant( "" ), QVariant( "" ), QVariant( "" ), QVariant( "" ), QVariant( "" ), a_pParent )
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
    aRoleNames[ROLE_VOLUME24H]		    = "m_volume24H";
    aRoleNames[ROLE_LAST_UPDATE_TIME]	= "m_lastUpdateTime";
	return aRoleNames;
}

QString QmlExchangesListItem::getFormattedPrice(double a_dPrice)
{
	return QString::number( a_dPrice, 'f', 8 );
}

QString QmlExchangesListItem::getFormattedDateTime( QString isoDateTime)
{
    QDateTime datetime = QDateTime::fromString(isoDateTime, Qt::ISODate);
    return datetime.toString("dd-MM-yyyy HH:mm:ss");
}
