#ifndef OVERVIEWPAGE_H
#define OVERVIEWPAGE_H

#include <QWidget>
#include <QJsonObject>

namespace Ui {
    class OverviewPage;
}
class ClientModel;
class WalletModel;
class TxViewDelegate;
class TransactionFilterProxy;
class GUIBannerWidget;
class CasinoCoinWebAPIParser;
class CasinoCoinWebAPI;
class JsonCoinInfoParser;

QT_BEGIN_NAMESPACE
class QModelIndex;
QT_END_NAMESPACE

/** Overview ("home") page widget */
class OverviewPage : public QWidget
{
    Q_OBJECT

public:
    explicit OverviewPage(QWidget *parent = 0);
    ~OverviewPage();

    void setClientModel(ClientModel *clientModel);
    void setWalletModel(WalletModel *walletModel);
    void showOutOfSyncWarning(bool fShow);

public slots:
    void setBalance(qint64 balance, qint64 unconfirmedBalance, qint64 immatureBalance);

signals:
    void transactionClicked(const QModelIndex &index);

private:
    Ui::OverviewPage *ui;
    ClientModel *clientModel;
    WalletModel *walletModel;
    qint64 currentBalance;
    qint64 currentUnconfirmedBalance;
    qint64 currentImmatureBalance;

    TxViewDelegate *txdelegate;
    TransactionFilterProxy *filter;

	GUIBannerWidget* advertsWidget;
	/** Create widget to populate adverts */
	void createAdvertsWidget();
    /** Get the CoinInfo from REST service */
    CasinoCoinWebAPIParser* cscWebApiParser;
    CasinoCoinWebAPI* cscWebApi;
    void getCoinInfo();
    QJsonObject coinInformation;

private slots:
    void updateDisplayUnit();
    void handleTransactionClicked(const QModelIndex &index);
    void updateAlerts(const QString &warnings);
    void updateCoinInfoFromWeb( JsonCoinInfoParser* coinInfoParser );
    void updateFiatBalance(int currency);
    void updateDisplayPromotions(bool checked);
};

#endif // OVERVIEWPAGE_H
