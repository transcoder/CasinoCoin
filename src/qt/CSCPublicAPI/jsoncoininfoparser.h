#ifndef JSONCOININFOPARSER_H
#define JSONCOININFOPARSER_H

#include <QJsonObject>
#include <QJsonValue>

class JsonCoinInfoParser : public QJsonObject
{
public:
    JsonCoinInfoParser();
    JsonCoinInfoParser( const QJsonObject& a_rOther );
    virtual ~JsonCoinInfoParser(){}

    const QJsonObject& getCoinInfo() const;

private:
    QJsonObject coinInfoObject;
};

#endif // JSONCOININFOPARSER_H
