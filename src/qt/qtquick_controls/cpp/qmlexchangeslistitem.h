#ifndef QMLEXCHANGESLISTITEM_H
#define QMLEXCHANGESLISTITEM_H

#include "qmllistitem.h"
#include "../../CSCPublicAPI/jsonsingleactiveexchange.h"

class QmlExchangesListItem : public QmlListItem
{
	Q_OBJECT
public:
	enum EExchangesRoles																			/**  User-specific model roles **/
	{ ROLE_IMAGE_SOURCE							= ROLE_1
	, ROLE_DESTINATION_URL						= ROLE_2
	, ROLE_EXCHANGE_NAME						= ROLE_3
	, ROLE_BID_PRICE							= ROLE_4
	, ROLE_ASK_PRICE							= ROLE_5
	, ROLE_LAST_PRICE							= ROLE_6
	, ROLE_DESCRIPTION							= ROLE_7
    , ROLE_VOLUME24H                            = ROLE_8
    , ROLE_LAST_UPDATE_TIME                     = ROLE_9
	};

	explicit QmlExchangesListItem
					( QString a_strImageSource
					, QString a_strDestinationUrl
					, QString a_strExchangesName
					, double a_dBidPrice
					, double a_dAskPrice
					, double a_dLastPrice
					, QString a_strDescription
                    , double a_dVolume24H
                    , QString a_strLastUpdateTime
					, QObject *a_pParent = 0
					);
	explicit QmlExchangesListItem	( const JsonSingleActiveExchange& a_rExchangeDescription
								, QObject *a_pParent = 0
								);
	explicit QmlExchangesListItem( QObject *a_pParent = 0 );
	virtual ~QmlExchangesListItem();

	virtual QHash<int, QByteArray> RoleNames() const;									/** Define class-specific roles **/

signals:

public slots:

private:
    QString getFormattedPrice( double a_dPrice );
    QString getFormattedDateTime( QString isoDateTime);
};

#endif // QMLEXCHANGESLISTITEM_H
