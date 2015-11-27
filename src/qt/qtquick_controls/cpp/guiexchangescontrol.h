#ifndef GUIEEXCHANGESCONTROL_H
#define GUIEEXCHANGESCONTROL_H

#include <QQuickItem>

#include "../../CSCPublicAPI/jsonactiveexchangesparser.h"

class GUIExchangesListView;

class GUIExchangesControl : public QQuickItem
{
	Q_OBJECT
public:
	GUIExchangesControl( QQuickItem* a_pParent = 0 );
	virtual ~GUIExchangesControl();

	Q_INVOKABLE void InitializeExchangesView( GUIExchangesListView* a_pView );
	GUIExchangesListView* GetExchangesView() const { return m_pExchangesView; }

public slots:
	void slotPopulateListView( JsonActiveExchangesParser* a_pActiveExchanges );

signals:

public slots:

private:
	GUIExchangesListView* m_pExchangesView;
};

#endif // GUIEEXCHANGESCONTROL_H
