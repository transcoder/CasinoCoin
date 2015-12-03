#include "qmlimageprovider.h"

#include <QDebug>

QmlImageProvider::QmlImageProvider()
	: QQuickImageProvider( QQuickImageProvider::Image )
{
}

void QmlImageProvider::AddToImagePool( QString a_strImageID, const QImage& a_rImage )
{
	m_aImagePool.insert( a_strImageID, a_rImage );
}

void QmlImageProvider::AddToImagePool( const QMap<QString, QImage>& a_aImages )
{
	QMapIterator<QString,QImage> iter( a_aImages );
	while( iter.hasNext() )
	{
		iter.next();
		AddToImagePool( iter.key(), iter.value() );
	}
}

QImage QmlImageProvider::requestImage( const QString& a_rImageID, QSize* a_pSize, const QSize& a_rRequestedSize )
{
	Q_UNUSED( a_rRequestedSize );
	QImage oImage( m_aImagePool.value( a_rImageID ) );
	if ( a_pSize )
	{
		a_pSize->setWidth( oImage.width() );
		a_pSize->setHeight( oImage.height() );
	}
	return oImage;
}
