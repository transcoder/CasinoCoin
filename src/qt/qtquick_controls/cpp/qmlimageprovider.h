#ifndef QMLIMAGEPROVIDER_H
#define QMLIMAGEPROVIDER_H

#include <QQuickPaintedItem>
#include <QImage>
#include <QPainter>

class QmlImageProvider : public QQuickPaintedItem
{
	Q_OBJECT

	Q_PROPERTY( QImage p_oImage MEMBER m_oImage NOTIFY signalImageChanged )
public:
	explicit QmlImageProvider( QQuickItem* a_pParent = 0 );
	explicit QmlImageProvider( const QImage& a_rImage, QQuickItem* a_pParent = 0 );

	void SetImage( const QImage& a_rImage );
	virtual void paint( QPainter* a_pPainter );
	void paintImage( const QImage& a_rImage, QPainter* a_pPainter );
signals:
	void signalImageChanged();
private:
	QImage m_oImage;
};

#endif // QMLIMAGEPROVIDER_H
