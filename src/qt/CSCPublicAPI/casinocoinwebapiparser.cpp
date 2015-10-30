#include "casinocoinwebapiparser.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>

#include <QDebug>

CasinoCoinWebAPIParser::CasinoCoinWebAPIParser( QObject* a_pParent )
	: QObject(a_pParent)
{
}

void CasinoCoinWebAPIParser::slotParseAnswer( const QByteArray& a_rJsonFile )
{
	QJsonParseError oError;
	QJsonDocument jsonDoc = QJsonDocument::fromJson( a_rJsonFile, &oError );
	if ( oError.error == QJsonParseError::NoError )
	{
		QJsonObject docAsObject = jsonDoc.object();
		if ( docAsObject.find( "Result" ).value().isObject() )
		{
			QJsonObject jsonObjectResult = docAsObject.find( "Result" ).value().toObject();
			if ( jsonObjectResult.find( "ActivePromotions" ).value().isArray() )
			{
				ParsePromotions( docAsObject );
			}
			else if ( jsonObjectResult.find( "ActiveNewsItems" ).value().isArray() )
			{
				ParseNewsItems( docAsObject );
			}
			else if ( jsonObjectResult.find( "ActiveCasinos" ).value().isArray() )
			{
				ParseCasinos( docAsObject );
			}
			else if ( jsonObjectResult.find( "ActiveExchanges" ).value().isArray() )
			{
				ParseExchanges( docAsObject );
			}
		}
	}
}

void CasinoCoinWebAPIParser::ParsePromotions( const QJsonObject& a_rJsonPromotions )
{
	qDebug() << "ParsePromotions";
	emit signalActivePromotionsParsed( new JsonActivePromotionsParser( a_rJsonPromotions ) );
}

void CasinoCoinWebAPIParser::ParseCasinos( const QJsonObject& a_rJsonCasinos )
{
	qDebug() << "Coming soon - ParseCasinos";
	qDebug() << a_rJsonCasinos;
}

void CasinoCoinWebAPIParser::ParseExchanges( const QJsonObject& a_rJsonExchanges )
{
	qDebug() << "Coming soon - ParseExchanges";
	qDebug() << a_rJsonExchanges;
}

void CasinoCoinWebAPIParser::ParseNewsItems( const QJsonObject& a_rJsonNewsItems )
{
	qDebug() << "Coming soon - ParseNewsItems";
	qDebug() << a_rJsonNewsItems;
}
