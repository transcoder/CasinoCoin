#ifndef GUIEXCHANGESWIDGET_H
#define GUIEXCHANGESWIDGET_H

#include <QWidget>
#include <QNetworkReply>
#include <QTimer>

class CasinoCoinWebAPIParser;
class CasinoCoinWebAPI;
class GUIExchangesControl;
class QmlImageProvider;
class JsonActiveExchangesParser;

class GUIExchangesWidget : public QWidget
{
	Q_OBJECT

public:
	GUIExchangesWidget( QWidget *parent = 0) ;
	~GUIExchangesWidget();

	QWidget* dockQmlToWidget();

	void PopulateExchangesLocally();

public slots:
	void slotPopulateExchangesFromWeb();

private:
	void registerCustomQmlTypes();
	void SetupRefreshTimer();

	GUIExchangesControl* m_pExchangesControl;

	CasinoCoinWebAPIParser* m_pWebApiParserTemporary;
	CasinoCoinWebAPI*		m_pWebApiTemporary;
	QmlImageProvider*		m_pQmlImageProvider;
	QTimer					m_timerRefresh;
private slots:
	void slotPopulateFromWeb( JsonActiveExchangesParser* a_pExchangesParser );

};

#endif // GUIEXCHANGESWIDGET_H
