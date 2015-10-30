#include "jsonactivepromotionsparser.h"

#include <QDebug>

JsonActivePromotionsParser::JsonActivePromotionsParser()
{

}

JsonActivePromotionsParser::JsonActivePromotionsParser( const QJsonObject& a_rOther )
	: QJsonObject( a_rOther )
{
	ResolvePromotionsArray();
}

void JsonActivePromotionsParser::ResolvePromotionsArray()
{
	if ( find( "Result" ).value().isObject() )
	{
		if ( find( "Result" ).value().toObject().find( "ActivePromotions" ).value().isArray() )
		{
			QJsonArray arrayOfCasinoDescriptors( find( "Result" ).value().toObject().find( "ActivePromotions" ).value().toArray() );
			foreach( QJsonValue singleCasinoDescriptor, arrayOfCasinoDescriptors )
			{
				if ( singleCasinoDescriptor.isObject() )
				{
					m_aActiveCasinos.append( JsonSingleActivePromotion( singleCasinoDescriptor.toObject() ) );
				}
			}
		}
	}
}

const QList<JsonSingleActivePromotion>& JsonActivePromotionsParser::GetPromotions() const
{
	return m_aActiveCasinos;
}

QList<JsonSingleActivePromotion>& JsonActivePromotionsParser::GetPromotions()
{
	return m_aActiveCasinos;
}
