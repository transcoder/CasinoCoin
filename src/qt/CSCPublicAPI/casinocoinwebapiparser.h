#ifndef CASINOCOINWEBAPIPARSER_H
#define CASINOCOINWEBAPIPARSER_H

#include <QObject>

#include "jsonactivepromotionsparser.h"
#include "jsonsingleactivepromotion.h"

class CasinoCoinWebAPIParser : public QObject
{
	Q_OBJECT
public:
	explicit CasinoCoinWebAPIParser( QObject* a_pParent = 0 );


signals:
	void signalActivePromotionsParsed( JsonActivePromotionsParser* a_pActivePromotions );
//	void signalActiveCasinosParsed( JsonActiveCasinosParser* a_pActivePromotions );
//	void signalActiveExchangesParsed( JsonActiveExchangesParser* a_pActivePromotions );
//	void signalActiveNewsItemsParsed( JsonActiveNewsItemsParser* a_pActivePromotions );

public slots:
	void slotParseAnswer( const QByteArray& a_rJsonFile );

private:
	void ParsePromotions( const QJsonObject& a_rJsonPromotions );
	void ParseCasinos	( const QJsonObject& a_rJsonCasinos );
	void ParseExchanges	( const QJsonObject& a_rJsonExchanges );
	void ParseNewsItems	( const QJsonObject& a_rJsonNewsItems );
};

#endif // CASINOCOINWEBAPIPARSER_H
