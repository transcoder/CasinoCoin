#ifndef JSONSINGLEACTIVEPROMOTION_H
#define JSONSINGLEACTIVEPROMOTION_H

#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>

#include <QImage>

class JsonSingleActivePromotion : public QJsonObject
{
public:
	JsonSingleActivePromotion();
	JsonSingleActivePromotion( const QJsonObject& a_rOther );
	virtual ~JsonSingleActivePromotion(){}

	QString GetImageName() const{ return m_strImageName; }
	QImage GetAdvertImage() const { return m_oAdvertImage; }
private:
	void StoreImage();

	static QRegExp GetRestrictedCharacters();

	QString m_strImageName;
	QImage m_oAdvertImage;

};

#endif // JSONSINGLEACTIVEPROMOTION_H
