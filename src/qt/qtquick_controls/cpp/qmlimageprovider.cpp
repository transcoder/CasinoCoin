#include "qmlimageprovider.h"

QmlImageProvider::QmlImageProvider( QQuickItem* a_pParent )
	: QQuickPaintedItem( a_pParent )
{

}

QmlImageProvider::QmlImageProvider( const QImage& a_rImage, QQuickItem* a_pParent )
	: QQuickPaintedItem( a_pParent )
	, m_oImage( a_rImage )
{
}

void QmlImageProvider::SetImage( const QImage& a_rImage )
{
	if ( a_rImage != m_oImage )
	{
		m_oImage = QImage( a_rImage );
		emit signalImageChanged();
	}
}

void QmlImageProvider::paint( QPainter* a_pPainter )
{
	if ( a_pPainter )
	{
		a_pPainter->drawImage( QPoint( 0, 0 ), m_oImage );
	}
}

void QmlImageProvider::paintImage( const QImage& a_rImage, QPainter* a_pPainter )
{
	SetImage( a_rImage );
	if ( a_pPainter )
	{
		a_pPainter->drawImage( QPoint( 0, 0 ), m_oImage );
	}
}
