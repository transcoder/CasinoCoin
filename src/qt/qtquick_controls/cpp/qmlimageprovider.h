#ifndef QMLIMAGEPROVIDER_H
#define QMLIMAGEPROVIDER_H

#include <QQuickImageProvider>
#include <QImage>

class QmlImageProvider : public QQuickImageProvider
{
public:
	explicit QmlImageProvider();

	void AddToImagePool( QString a_strImageID, const QImage& a_rImage );
	void AddToImagePool( const QMap<QString,QImage>& a_aImages );

	virtual QImage	requestImage
					( const QString& a_rImageID
					, QSize* a_pSize
					, const QSize& a_rRequestedSize
					);
signals:

public slots:

private:
	QMap<QString,QImage> m_aImagePool;
};

#endif // QMLIMAGEPROVIDER_H
