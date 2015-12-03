#ifndef CASINOCOINWEBAPIPARSER_H
#define CASINOCOINWEBAPIPARSER_H

#include <QObject>

#include "jsonactivepromotionsparser.h"
#include "jsonsingleactivepromotion.h"
#include "jsoncoininfoparser.h"
#include "jsonactiveexchangesparser.h"
#include "jsonsingleactiveexchange.h"

#include <QNetworkReply>

class CasinoCoinWebAPIParser : public QObject
{
	Q_OBJECT
public:
	explicit CasinoCoinWebAPIParser( QObject* a_pParent = 0 );


signals:
	void signalActivePromotionsParsed( JsonActivePromotionsParser* a_pActivePromotions );
    void signalCoinInfoParsed( JsonCoinInfoParser* a_pCoinInfo );
//	void signalActiveCasinosParsed( JsonActiveCasinosParser* a_pActivePromotions );
    void signalActiveExchangesParsed( JsonActiveExchangesParser* a_pActiveExchanges );
//	void signalActiveNewsItemsParsed( JsonActiveNewsItemsParser* a_pActivePromotions );

public slots:
	void slotParseAnswer( const QByteArray& a_rJsonFile );
	void slotNetworkError
				( QNetworkReply::NetworkError a_eError
				, const QUrl a_rFailedUrl
				);
private:
	void ParsePromotions( const QJsonObject& a_rJsonPromotions );
	void ParseCasinos	( const QJsonObject& a_rJsonCasinos );
	void ParseExchanges	( const QJsonObject& a_rJsonExchanges );
	void ParseNewsItems	( const QJsonObject& a_rJsonNewsItems );
    void ParseCoinInfo ( const QJsonObject& a_rJsonCoinInfo );

	QByteArray ReadFile( QString a_strSourcePath );
	void StoreFile( QString a_strDestinationPath, const QByteArray& a_rJsonFile );
};

#endif // CASINOCOINWEBAPIPARSER_H
