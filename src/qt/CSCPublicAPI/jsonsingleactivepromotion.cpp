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
	StoreImage();
}

QString JsonSingleActivePromotion::GetImagePath() const
{
	return QString( "file://" + QDir::currentPath() + "/" + GetImageRelativePath() );
}

QString JsonSingleActivePromotion::GetImageRelativePath() const
{
	return QString( "adverts/" + find( "promotion_title" ).value().toString().remove( " " ) + "." + find( "image_mime_type" ).value().toString().split( "/" ).last() );
}

QString JsonSingleActivePromotion::StoreImage()
{
	QString strReturn = QString();
	if ( find( "image_mime_type" ).value().toString().split( "/" ).first().contains( "image" ) )
	{
		QString strFileName = GetImageRelativePath();
		QByteArray binaryData = QByteArray::fromBase64( find( "promotion_image" ).value().toString().toLocal8Bit() );

		if ( !QDir( "adverts" ).exists() )
		{
			QDir().mkdir( "adverts" );
		}
		QFile imageOutputFile( strFileName );
		QImage outputImage = QImage::fromData( binaryData, "JPEG" );
		if ( imageOutputFile.open( QIODevice::WriteOnly | QIODevice::Truncate ) )
		{
			outputImage.save( &imageOutputFile, 0 );
			imageOutputFile.close();
			strReturn = strFileName;
		}
	}
	return strReturn;
}

