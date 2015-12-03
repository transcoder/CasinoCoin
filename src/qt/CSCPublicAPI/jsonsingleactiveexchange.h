#ifndef JSONSINGLEACTIVEEXCHANGE_H
#define JSONSINGLEACTIVEEXCHANGE_H

#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>

#include <QImage>

class JsonSingleActiveExchange : public QJsonObject
{
public:
    JsonSingleActiveExchange();
    JsonSingleActiveExchange( const QJsonObject& a_rOther );
    virtual ~JsonSingleActiveExchange(){}

    QString getImageName() const{ return m_strImageName; }
    QImage  getExchangeImage() const { return m_oExchangeImage; }
    QString getExchangeName() const{ return m_strExchangeName; }
    QString getAccessUrl() const{ return m_strAccessUrl; }
    QString getDescription() const{ return m_strDescription; }
    double  getLastBidPriceBTC() const{ return m_dblLastBidPriceBTC; }
    double  getLastAskPriceBTC() const{ return m_dblLastAskPriceBTC; }
    double  getLastPriceBTC() const{ return m_dblLastBidPriceBTC; }
    double  getVolume24H() const{ return m_dblVolume24H; }
    QString getLastUpdateTime() const{ return m_strLastUpdateTime; }

private:
    void storeImage();

    static QRegExp getRestrictedCharacters();

	QString m_strImageName;
    QImage m_oExchangeImage;
    QString m_strExchangeName;
    QString m_strAccessUrl;
    QString m_strDescription;
    double m_dblLastBidPriceBTC;
    double m_dblLastAskPriceBTC;
    double m_dblLastPriceBTC;
    double m_dblVolume24H;
    QString m_strLastUpdateTime;

};

#endif // JSONSINGLEACTIVEEXCHANGE_H
