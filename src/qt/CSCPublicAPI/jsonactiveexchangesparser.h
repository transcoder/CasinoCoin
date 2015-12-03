#ifndef JSONACTIVEEXCHANGESPARSER_H
#define JSONACTIVEEXCHANGESPARSER_H

#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QList>

#include "jsonsingleactiveexchange.h"

class QmlImageProvider;

class JsonActiveExchangesParser : public QJsonObject
{
public:
    JsonActiveExchangesParser();
    JsonActiveExchangesParser( const QJsonObject& a_rOther );
    virtual ~JsonActiveExchangesParser(){}

    const QList<JsonSingleActiveExchange>& GetExchanges() const;
    QList<JsonSingleActiveExchange>& GetExchanges();

    void AddImagesToPool( QmlImageProvider* a_pImageProvider );

private:
    void ResolveExchangesArray();

    QList<JsonSingleActiveExchange> m_aActiveExchanges;
};

#endif // JSONACTIVEEXCHANGESPARSER_H
