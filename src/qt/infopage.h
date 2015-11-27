#ifndef INFOPAGE_H
#define INFOPAGE_H

#include <QDialog>

class WalletModel;
class ClientModel;
class GUIExchangesWidget;

namespace Ui {
class InfoPage;
}

class InfoPage : public QDialog
{
    Q_OBJECT

public slots:
    /** Set number of connections shown in the UI */
    void setNumConnections(int count);
    /** Set number of blocks shown in the UI */
    void setNumBlocks(int count, int countOfPeers);
    /** Set number of transactions shown in the UI */
    void setNumTransactions(int count);

public:
    explicit InfoPage(QWidget *parent = 0);
    void setWalletModel(WalletModel *model);
    void setClientModel(ClientModel *model);
    ~InfoPage();

private:
    Ui::InfoPage *ui;
    WalletModel *walletModel;
    ClientModel *clientModel;
	GUIExchangesWidget* exchangesWidget;

	void createExchangesWidget();
    double GetNetworkHashRate(int lookup, int height);
};

#endif // INFOPAGE_H
