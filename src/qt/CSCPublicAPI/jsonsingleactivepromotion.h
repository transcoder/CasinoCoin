#ifndef JSONSINGLEACTIVEPROMOTION_H
#define JSONSINGLEACTIVEPROMOTION_H

#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>

class JsonSingleActivePromotion : public QJsonObject
{
public:
	JsonSingleActivePromotion();
	JsonSingleActivePromotion( const QJsonObject& a_rOther );
	virtual ~JsonSingleActivePromotion(){}

	QString GetImagePath() const;

private:
	QString GetImageRelativePath() const;
	QString StoreImage();
};

#endif // JSONSINGLEACTIVEPROMOTION_H
