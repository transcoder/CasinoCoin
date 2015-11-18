#ifndef CASINOCOINWEBAPI_H
#define CASINOCOINWEBAPI_H

#include <QObject>

#include <QNetworkAccessManager>
#include <QNetworkReply>

class CasinoCoinWebAPI : public QObject
{
	Q_OBJECT
public:
	explicit CasinoCoinWebAPI( QObject* a_pParent = 0 );
	virtual ~CasinoCoinWebAPI(){}

	void GetActivePromotions();
	void GetActiveCasinos();
	void GetActiveNewsItems();
	void GetActiveExchanges();
    void GetCoinInfo();

	static const QString s_strServerAddress;
	static const QString s_strServerEndpoint;

signals:
	void signalResponseReady( const QByteArray& a_rJsonFile );
	void signalNetworkError
				( QNetworkReply::NetworkError a_eError
				, const QUrl a_rFailedUrl
				);

public slots:
	void slotParseNetworkResponse( QNetworkReply *finished );

private:
	void Get( const QString& a_rUrl );

	QNetworkAccessManager m_oNetworkAccessManager;
};

#endif // CASINOCOINWEBAPI_H
