#include "jsoncoininfoparser.h"
#include <QDebug>

JsonCoinInfoParser::JsonCoinInfoParser()
{

}

JsonCoinInfoParser::JsonCoinInfoParser( const QJsonObject& apiResult )
    : QJsonObject( apiResult )
{
    qDebug() << "JsonCoinInfoParser: " << apiResult.begin().key();
    if ( apiResult.find( "Result" ).value().isObject() )
    {
        if ( apiResult.find( "Result" ).value().toObject().find( "CoinInfo" ).value().isObject() )
        {
            coinInfoObject = apiResult.find( "Result" ).value().toObject().find( "CoinInfo" ).value().toObject();
        }
        else
        {
            qDebug()<<"JsonCoinInfoParser first key: " << apiResult.find( "Result" ).value().toObject().begin().key();
        }
    }
}

const QJsonObject& JsonCoinInfoParser::getCoinInfo() const
{
    return coinInfoObject;
}
