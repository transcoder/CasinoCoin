#include "qmlbannerlistitem.h"

#include <QDebug>

QmlBannerListItem::QmlBannerListItem(QString a_strImageSource, QString a_strDestinationUrl, QString a_strDescription, QObject* a_pParent )
	: QmlListItem( QVariant( a_strImageSource ), QVariant( a_strDestinationUrl ), QVariant( a_strDescription ), a_pParent )
{
}

QmlBannerListItem::QmlBannerListItem( const JsonSingleActivePromotion& a_rCasinoDescription, QObject* a_pParent )
	: QmlListItem( QVariant( a_rCasinoDescription.GetImagePath() ), a_rCasinoDescription.find( "access_url" ).value().toVariant(), a_rCasinoDescription.find( "description" ).value().toVariant(), a_pParent )
{
}

QmlBannerListItem::QmlBannerListItem( QObject* a_pParent )
	: QmlListItem( QVariant( "" ), QVariant( "" ), QVariant( "" ), a_pParent )
{
}

QmlBannerListItem::~QmlBannerListItem()
{

}

QHash<int, QByteArray> QmlBannerListItem::RoleNames() const
{
	QHash<int, QByteArray> aRoleNames;
	aRoleNames[ROLE_IMAGE_SOURCE]		= "m_imageSource";
	aRoleNames[ROLE_DESTINATION_URL]	= "m_destinationUrl";
	aRoleNames[ROLE_DESCRIPTION]		= "m_description";
	return aRoleNames;
}
