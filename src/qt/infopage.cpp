#include "infopage.h"
#include "ui_infopage.h"
#include "walletmodel.h"
#include "clientmodel.h"
#include "bitcoinrpc.h"
#include <QDateTime>
#include "bitcoinunits.h"
#include "main.h"

#include "qtquick_controls/cpp/guiexchangeswidget.h"

using namespace std;

InfoPage::InfoPage(QWidget *parent) :
    QDialog(parent),
	ui(new Ui::InfoPage),
	exchangesWidget( 0 )
{
    ui->setupUi(this);
//    ui->casinoInfoBox->setVisible(false);
//    ui->newsItemsBox->setVisible(false);

	createExchangesWidget();
}

void InfoPage::setWalletModel(WalletModel *model)
{
    this->walletModel = model;
    if(model)
    {
        // subscribe to transaction changes
        connect(model, SIGNAL(numTransactionsChanged(int)), this, SLOT(setNumTransactions(int)));
        setNumTransactions(model->getNumTransactions());
    }
}

void InfoPage::setClientModel(ClientModel *model)
{
    this->clientModel = model;
    if(model)
    {
        // Subscribe to information, replies, messages, errors
        connect(model, SIGNAL(numConnectionsChanged(int)), this, SLOT(setNumConnections(int)));
        connect(model, SIGNAL(numBlocksChanged(int,int)), this, SLOT(setNumBlocks(int,int)));
        setNumConnections(model->getNumConnections());
        setNumBlocks(model->getNumBlocks(), model->getNumBlocksOfPeers());
    }
}

void InfoPage::setNumConnections(int count)
{
    ui->txtConnections->setText(QString::number(count));
}

void InfoPage::setNumBlocks(int count, int countOfPeers)
{
    ui->txtBlockHeight->setText(QString::number(count));
    // block height changed so update all possible values as well
    if(clientModel)
    {
        ui->txtLastBlockTime->setText(clientModel->getLastBlockDate().toString());
        ui->txtDifficulty->setText(QString::number(GetDifficulty()));
        ui->txtCoinSupply->setText(BitcoinUnits::formatWithUnit(BitcoinUnits::BTC, GetTotalCoinSupply(count, false)));
        double megaHash = GetNetworkHashRate(-1, count) / 1000000;
        ui->txtHashRate->setText(QString::number(megaHash,'f',0).append(" MHash/sec"));
    }
}

void InfoPage::setNumTransactions(int count)
{
    ui->txtTransactionCount->setText(QString::number(count));
}

double InfoPage::GetNetworkHashRate(int lookup, int height) {
    CBlockIndex *pb = pindexBest;

    if (height >= 0 && height < nBestHeight)
        pb = FindBlockByHeight(height);

    if (pb == NULL || !pb->nHeight)
        return 0;

    // If lookup is -1, then use blocks since last difficulty change.
    if (lookup <= 0)
        lookup = pb->nHeight % 2016 + 1;

    // If lookup is larger than chain, then set it to chain length.
    if (lookup > pb->nHeight)
        lookup = pb->nHeight;

    CBlockIndex *pb0 = pb;
    int64 minTime = pb0->GetBlockTime();
    int64 maxTime = minTime;
    for (int i = 0; i < lookup; i++) {
        pb0 = pb0->pprev;
        int64 time = pb0->GetBlockTime();
        minTime = std::min(time, minTime);
        maxTime = std::max(time, maxTime);
    }

    // In case there's a situation where minTime == maxTime, we don't want a divide by zero exception.
    if (minTime == maxTime)
        return 0;

    uint256 workDiff = pb->nChainWork - pb0->nChainWork;
    int64 timeDiff = maxTime - minTime;
    double workDiffDouble = workDiff.getdouble();
    return workDiffDouble / timeDiff;
}

InfoPage::~InfoPage()
{
	delete ui;
}

void InfoPage::createExchangesWidget()
{
	exchangesWidget = new GUIExchangesWidget( this );
	exchangesWidget->slotPopulateExchangesFromWeb();
	ui->verticalLayoutExchanges->addWidget( exchangesWidget->dockQmlToWidget() );
}
