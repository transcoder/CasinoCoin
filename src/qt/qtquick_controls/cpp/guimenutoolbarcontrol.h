#ifndef GUIMENUTOOLBARCONTROL_H
#define GUIMENUTOOLBARCONTROL_H

#include <QQuickItem>

class GUIMenuToolbarListView;

class GUIMenuToolbarControl : public QQuickItem
{
	Q_OBJECT
	Q_ENUMS( EMenuToolbarItemTypes )
public:

	enum EMenuToolbarItemTypes
	{ OVERVIEW
	, SEND
	, RECEIVE
	, TRANSACTIONS
	, CONTACTS
	, REDEEM_PRYPTO
	, INFO
	};

	GUIMenuToolbarControl( QQuickItem* a_pParent = 0 );
	virtual ~GUIMenuToolbarControl();

	Q_INVOKABLE void InitializeMenuToolbarView( GUIMenuToolbarListView* a_pView );
	GUIMenuToolbarListView* GetMenuToolbarView() const { return m_pMenuToolbarView; }

public slots:

signals:
	void signalCurrentItemIndexChanged();
public slots:

private:
	GUIMenuToolbarListView* m_pMenuToolbarView;

	void ConnectListViewSignals();
private slots:
	void slotCurrentItemIndexChanged();
};

#endif // GUIMENUTOOLBARCONTROL_H
