#include "qmlbannerlistmodel.h"

#include "qmlbannerlistitem.h"

#include "../../CSCPublicAPI/jsonactivepromotionsparser.h"
#include "../../CSCPublicAPI/jsonsingleactivepromotion.h"

#include <QDebug>

QmlBannerListModel::QmlBannerListModel( QObject* a_pParent )
	: QmlListModel( new QmlBannerListItem( 0 ), a_pParent )
{
}

QmlBannerListModel::QmlBannerListModel
								( const JsonActivePromotionsParser& a_rActivePromotions
								, QObject* a_pParent
								)
	: QmlListModel( new QmlBannerListItem( 0 ), a_pParent )
{
	foreach( const JsonSingleActivePromotion& rPromotion, a_rActivePromotions.GetPromotions() )
	{
		append( new QmlBannerListItem( rPromotion, this ) );
	}
}

QmlBannerListModel::~QmlBannerListModel()
{

}
