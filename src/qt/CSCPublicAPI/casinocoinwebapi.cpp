#include "casinocoinwebapi.h"

#include <QSsl>

const QString CasinoCoinWebAPI::s_strServerAddress = "http://119.81.188.59/";
const QString CasinoCoinWebAPI::s_strServerEndpoint = "CSCPublicAPI";

CasinoCoinWebAPI::CasinoCoinWebAPI( QObject*a_pParent )
	: QObject(a_pParent )
{
	connect( &m_oNetworkAccessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(slotParseNetworkResponse(QNetworkReply*)));
}

void CasinoCoinWebAPI::GetActivePromotions()
{
	Get( s_strServerAddress + "/" + s_strServerEndpoint + "/ActivePromotions" );
}

void CasinoCoinWebAPI::GetActiveCasinos()
{
	Get( s_strServerAddress + "/" + s_strServerEndpoint + "/ActiveCasinos" );
}

void CasinoCoinWebAPI::GetActiveNewsItems()
{
	Get( s_strServerAddress + "/" + s_strServerEndpoint + "/ActiveNewsItems" );
}

void CasinoCoinWebAPI::GetActiveExchanges()
{
	Get( s_strServerAddress + "/" + s_strServerEndpoint + "/ActiveExchanges" );
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
		emit signalNetworkError( finished->error() );
		return;
	}

   QByteArray data = finished->readAll();
	emit signalResponseReady( data );
}
