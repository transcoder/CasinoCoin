#ifndef JSONACTIVEPROMOTIONSPARSER_H
#define JSONACTIVEPROMOTIONSPARSER_H

#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QList>

#include "jsonsingleactivepromotion.h"

class QmlImageProvider;

class JsonActivePromotionsParser : public QJsonObject
{
public:
	JsonActivePromotionsParser();
	JsonActivePromotionsParser( const QJsonObject& a_rOther );
	virtual ~JsonActivePromotionsParser(){}

	const QList<JsonSingleActivePromotion>& GetPromotions() const;
	QList<JsonSingleActivePromotion>& GetPromotions();

	void AddImagesToPool( QmlImageProvider* a_pImageProvider );

private:
	void ResolvePromotionsArray();

	QList<JsonSingleActivePromotion> m_aActivePromotions;
};

#endif // JSONACTIVEPROMOTIONSPARSER_H
