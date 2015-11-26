#include "jsonactiveexchangesparser.h"
#include "../qtquick_controls/cpp/qmlimageprovider.h"

#include <QDebug>

JsonActiveExchangesParser::JsonActiveExchangesParser()
{

}

JsonActiveExchangesParser::JsonActiveExchangesParser( const QJsonObject& a_rOther )
	: QJsonObject( a_rOther )
{
    ResolveExchangesArray();
}

void JsonActiveExchangesParser::ResolveExchangesArray()
{
	if ( find( "Result" ).value().isObject() )
	{
        if ( find( "Result" ).value().toObject().find( "ActiveExchanges" ).value().isArray() )
		{
            QJsonArray arrayOfExchangeDescriptors( find( "Result" ).value().toObject().find( "ActiveExchanges" ).value().toArray() );
            foreach( QJsonValue singleExchangeDescriptor, arrayOfExchangeDescriptors )
			{
                if ( singleExchangeDescriptor.isObject() )
				{
                    m_aActiveExchanges.append( JsonSingleActiveExchange( singleExchangeDescriptor.toObject() ) );
				}
			}
		}
	}
}

const QList<JsonSingleActiveExchange>& JsonActiveExchangesParser::GetExchanges() const
{
    return m_aActiveExchanges;
}

QList<JsonSingleActiveExchange>& JsonActiveExchangesParser::GetExchanges()
{
    return m_aActiveExchanges;
}

void JsonActiveExchangesParser::AddImagesToPool( QmlImageProvider* a_pImageProvider )
{
	if ( a_pImageProvider )
	{
        foreach( JsonSingleActiveExchange oExchange, m_aActiveExchanges )
		{
            a_pImageProvider->AddToImagePool( oExchange.getImageName(), oExchange.getExchangeImage() );
		}
	}
}
