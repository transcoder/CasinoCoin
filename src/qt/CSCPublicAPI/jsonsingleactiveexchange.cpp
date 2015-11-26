#include "jsonsingleactiveexchange.h"

#include <QFile>
#include <QImage>
#include <QDir>

#include <QDebug>

JsonSingleActiveExchange::JsonSingleActiveExchange()
{

}

JsonSingleActiveExchange::JsonSingleActiveExchange( const QJsonObject& a_rOther )
	: QJsonObject( a_rOther )
{
    m_strImageName = find( "exchange_name" ).value().toString().remove( getRestrictedCharacters() );
    storeImage();
    m_strExchangeName = find( "exchange_name" ).value().toString().remove( getRestrictedCharacters() );
    m_strAccessUrl = find( "access_url" ).value().toString();
    m_strDescription = find( "description" ).value().toString();
    m_dblLastBidPriceBTC = find( "last_bid_price_btc" ).value().toDouble();
    m_dblLastAskPriceBTC = find( "last_ask_price_btc" ).value().toDouble();
    m_dblLastPriceBTC = find( "last_price_btc" ).value().toDouble();
    m_dblVolume24H = find( "volume24h" ).value().toDouble();
    m_strLastUpdateTime = find( "last_update_time" ).value().toString();
}

QRegExp JsonSingleActiveExchange::getRestrictedCharacters()
{
	return QRegExp( "[<,>|\\:()&;#?*% ]" );
}

void JsonSingleActiveExchange::storeImage()
{
	if ( find( "image_mime_type" ).value().toString().split( "/" ).first().contains( "image" ) )
	{
        QByteArray binaryData = QByteArray::fromBase64( find( "exchange_image" ).value().toString().toLocal8Bit() );
        m_oExchangeImage = QImage::fromData( binaryData );
	}
}

