#ifndef GUIBANNERWIDGET_H
#define GUIBANNERWIDGET_H

#include <QWidget>
#include <QNetworkReply>

class CasinoCoinWebAPIParser;
class CasinoCoinWebAPI;
class GUIBannerControl;

class GUIBannerWidget : public QWidget
{
	Q_OBJECT

public:
	GUIBannerWidget(QWidget *parent = 0);
	~GUIBannerWidget();

	QWidget* dockQmlToWidget();

	void PopulateBannerFromWeb();
	void PopulateBannerLocally();

private:
	void registerCustomQmlTypes();

	GUIBannerControl* m_pBannerControl;

	CasinoCoinWebAPIParser* m_pWebApiParserTemporary;
	CasinoCoinWebAPI*		m_pWebApiTemporary;

private slots:
	void slotNetworkError( QNetworkReply::NetworkError a_eError );
};

#endif // GUIBANNERWIDGET_H
