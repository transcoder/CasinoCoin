#ifndef GUIBANNERCONTROL_H
#define GUIBANNERCONTROL_H

#include <QQuickItem>

#include "../../CSCPublicAPI/jsonactivepromotionsparser.h"

class GUIBannerListView;

class GUIBannerControl : public QQuickItem
{
	Q_OBJECT
public:
	GUIBannerControl( QQuickItem* a_pParent = 0 );
	virtual ~GUIBannerControl();

	Q_INVOKABLE void InitializeAdvertsView( GUIBannerListView* a_pView );
	GUIBannerListView* GetAdvertsView() const { return m_pAdvertsView; }

public slots:
	void slotPopulateListView( JsonActivePromotionsParser* a_pActivePromotions );

signals:

public slots:

private:
	GUIBannerListView* m_pAdvertsView;
};

#endif // GUIBANNERCONTROL_H
