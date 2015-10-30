#ifndef JSONACTIVEPROMOTIONSPARSER_H
#define JSONACTIVEPROMOTIONSPARSER_H

#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QList>

#include "jsonsingleactivepromotion.h"

class JsonActivePromotionsParser : public QJsonObject
{
public:
	JsonActivePromotionsParser();
	JsonActivePromotionsParser( const QJsonObject& a_rOther );
	virtual ~JsonActivePromotionsParser(){}

	const QList<JsonSingleActivePromotion>& GetPromotions() const;
	QList<JsonSingleActivePromotion>& GetPromotions();
private:

	void ResolvePromotionsArray();

	QList<JsonSingleActivePromotion> m_aActiveCasinos;
};

#endif // JSONACTIVEPROMOTIONSPARSER_H
