#include "casinocoinwebapi.h"

#include <QSsl>
#include <QDebug>

const QString CasinoCoinWebAPI::s_strServerAddress = "http://api.csc.dig0.com/";
const QString CasinoCoinWebAPI::s_strServerEndpoint = "CSCPublicAPI";

CasinoCoinWebAPI::CasinoCoinWebAPI( QObject*a_pParent )
	: QObject(a_pParent )
{
	connect( &m_oNetworkAccessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(slotParseNetworkResponse(QNetworkReply*)));
}

void CasinoCoinWebAPI::GetActivePromotions()
{
	Get( s_strServerAddress + s_strServerEndpoint + "/ActivePromotions" );
}

void CasinoCoinWebAPI::GetActiveCasinos()
{
	Get( s_strServerAddress + s_strServerEndpoint + "/ActiveCasinos" );
}

void CasinoCoinWebAPI::GetActiveNewsItems()
{
	Get( s_strServerAddress + s_strServerEndpoint + "/ActiveNewsItems" );
}

void CasinoCoinWebAPI::GetActiveExchanges()
{
	Get( s_strServerAddress + s_strServerEndpoint + "/ActiveExchanges" );
}

void CasinoCoinWebAPI::GetCoinInfo()
{
    Get( s_strServerAddress + s_strServerEndpoint + "/CoinInfo" );
}

void CasinoCoinWebAPI::Get( const QString& a_rUrl )
{
	QUrl oUrl ( a_rUrl );
	QNetworkRequest oNetworkRequest ( oUrl );
	m_oNetworkAccessManager.get( oNetworkRequest );
}

void CasinoCoinWebAPI::slotParseNetworkResponse( QNetworkReply *finished )
{
	if ( finished->error() != QNetworkReply::NoError )
	{
		// A communication error has occurred
        qDebug() << "API Network Error: " << finished->errorString();
		emit signalNetworkError( finished->error(), finished->request().url() );
		return;
	}

	QByteArray data = finished->readAll();
	emit signalResponseReady( data );
}
