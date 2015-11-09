#ifndef GUIMENUTOOLBARWIDGET_H
#define GUIMENUTOOLBARWIDGET_H

#include <QWidget>
#include "guimenutoolbarcontrol.h"

class QmlImageProvider;

class GUIMenuToolbarWidget : public QWidget
{
	Q_OBJECT
public:

	explicit GUIMenuToolbarWidget( QWidget* a_pParent = 0 );
	virtual ~GUIMenuToolbarWidget();

	QWidget* dockQmlToWidget();

	void SetCurrentItemType( GUIMenuToolbarControl::EMenuToolbarItemTypes a_eType );
signals:
	void signalItemClicked( GUIMenuToolbarControl::EMenuToolbarItemTypes a_eType );
public slots:

private:
	void registerCustomQmlTypes();

	GUIMenuToolbarControl*	m_pToolbarControl;
	QmlImageProvider*		m_pQmlImageProvider;

private slots:
	void slotCurrentItemChanged();
	void slotOurWebsiteURLClicked();
};

#endif // GUIMENUTOOLBARWIDGET_H
