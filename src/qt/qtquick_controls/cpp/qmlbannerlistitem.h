#ifndef QMLBANNERLISTITEM_H
#define QMLBANNERLISTITEM_H

#include "qmllistitem.h"
#include "../../CSCPublicAPI/jsonsingleactivepromotion.h"

class QmlBannerListItem : public QmlListItem
{
	Q_OBJECT
public:
	enum EBannerRoles																			/**  User-specific model roles **/
	{ ROLE_IMAGE_SOURCE							= ROLE_1
	, ROLE_DESTINATION_URL						= ROLE_2
	, ROLE_DESCRIPTION							= ROLE_3
	};

	explicit QmlBannerListItem
					( QString a_strImageSource
					, QString a_strDestinationUrl
					, QString a_strDescription
					, QObject *a_pParent = 0
					);
	explicit QmlBannerListItem	( const JsonSingleActivePromotion& a_rCasinoDescription
								, QObject *a_pParent = 0
								);
	explicit QmlBannerListItem( QObject *a_pParent = 0 );
	virtual ~QmlBannerListItem();

	virtual QHash<int, QByteArray> RoleNames() const;									/** Define class-specific roles **/

signals:

public slots:

};

#endif // QMLBANNERLISTITEM_H
