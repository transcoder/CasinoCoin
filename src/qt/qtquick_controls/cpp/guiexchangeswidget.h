#ifndef GUIEXCHANGESWIDGET_H
#define GUIEXCHANGESWIDGET_H

#include <QWidget>
#include <QNetworkReply>

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

	void PopulateExchangesFromWeb();
	void PopulateExchangesLocally();

private:
	void registerCustomQmlTypes();

	GUIExchangesControl* m_pExchangesControl;

	CasinoCoinWebAPIParser* m_pWebApiParserTemporary;
	CasinoCoinWebAPI*		m_pWebApiTemporary;
	QmlImageProvider*		m_pQmlImageProvider;
private slots:
	void slotPopulateFromWeb( JsonActiveExchangesParser* a_pExchangesParser );

};

#endif // GUIEXCHANGESWIDGET_H
