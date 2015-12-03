#include "jsonsingleactivepromotion.h"

#include <QFile>
#include <QImage>
#include <QDir>

#include <QDebug>

JsonSingleActivePromotion::JsonSingleActivePromotion()
{

}

JsonSingleActivePromotion::JsonSingleActivePromotion( const QJsonObject& a_rOther )
	: QJsonObject( a_rOther )
{
	m_strImageName = find( "promotion_title" ).value().toString().remove( GetRestrictedCharacters() );
	StoreImage();
}

QRegExp JsonSingleActivePromotion::GetRestrictedCharacters()
{
	return QRegExp( "[<,>|\\:()&;#?*% ]" );
}

void JsonSingleActivePromotion::StoreImage()
{
	if ( find( "image_mime_type" ).value().toString().split( "/" ).first().contains( "image" ) )
	{
		QByteArray binaryData = QByteArray::fromBase64( find( "promotion_image" ).value().toString().toLocal8Bit() );
		m_oAdvertImage = QImage::fromData( binaryData );
	}
}

