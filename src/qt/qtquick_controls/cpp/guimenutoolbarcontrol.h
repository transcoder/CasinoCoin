#ifndef GUIMENUTOOLBARCONTROL_H
#define GUIMENUTOOLBARCONTROL_H

#include <QQuickItem>

class GUIMenuToolbarListView;

class GUIMenuToolbarControl : public QQuickItem
{
	Q_OBJECT

	Q_PROPERTY( QString p_strVisitWebsiteText MEMBER m_strVisitWebsiteText NOTIFY signalVisitWebsiteTextChanged )
	Q_PROPERTY( QString p_strWebsiteURL MEMBER m_strWebsiteURL NOTIFY signalWebsiteURLChanged )

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

	Q_INVOKABLE void initializeMenuToolbarView( GUIMenuToolbarListView* a_pView );
	GUIMenuToolbarListView* GetMenuToolbarView() const { return m_pMenuToolbarView; }

	void setVisitWebsiteText( QString a_strNewText );
	void setWebsiteURL( QString a_strNewText );

	QString GetVisitWebsiteText() const { return m_strVisitWebsiteText; }
	QString GetWebsiteURL() const { return m_strWebsiteURL; }

public slots:

signals:
	void signalCurrentItemIndexChanged();
	void signalVisitWebsiteTextChanged();
	void signalWebsiteURLChanged();
	void signalOurWebsiteURLClicked();

private:
	GUIMenuToolbarListView* m_pMenuToolbarView;
	QString m_strVisitWebsiteText;
	QString m_strWebsiteURL;

	void connectListViewSignals();

private slots:
	void slotCurrentItemIndexChanged();
};

#endif // GUIMENUTOOLBARCONTROL_H
