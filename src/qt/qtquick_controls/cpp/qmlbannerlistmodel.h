#ifndef QMLBANNERLISTMODEL_H
#define QMLBANNERLISTMODEL_H

#include "qmllistmodel.h"

class QmlBannerListItem;
class JsonActivePromotionsParser;

class QmlBannerListModel : public QmlListModel
{
	Q_OBJECT
public:
	explicit QmlBannerListModel( QObject* a_pParent = 0 );
	explicit QmlBannerListModel
						( const JsonActivePromotionsParser& a_rActivePromotions
						, QObject* a_pParent = 0
						);
	virtual ~QmlBannerListModel();																			/** Destructor **/

signals:

public slots:

};

#endif // QMLBANNERLISTMODEL_H
