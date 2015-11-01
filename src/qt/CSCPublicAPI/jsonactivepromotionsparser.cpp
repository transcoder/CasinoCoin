#include "jsonactivepromotionsparser.h"
#include "../qtquick_controls/cpp/qmlimageprovider.h"

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
					m_aActivePromotions.append( JsonSingleActivePromotion( singleCasinoDescriptor.toObject() ) );
				}
			}
		}
	}
}

const QList<JsonSingleActivePromotion>& JsonActivePromotionsParser::GetPromotions() const
{
	return m_aActivePromotions;
}

QList<JsonSingleActivePromotion>& JsonActivePromotionsParser::GetPromotions()
{
	return m_aActivePromotions;
}

void JsonActivePromotionsParser::AddImagesToPool( QmlImageProvider* a_pImageProvider )
{
	if ( a_pImageProvider )
	{
		foreach( JsonSingleActivePromotion oPromotion, m_aActivePromotions )
		{
			a_pImageProvider->AddToImagePool( oPromotion.GetImageName(), oPromotion.GetAdvertImage() );
		}
	}
}
