#include "overviewpage.h"
#include "ui_overviewpage.h"

#include "clientmodel.h"
#include "walletmodel.h"
#include "bitcoinunits.h"
#include "currencies.h"
#include "optionsmodel.h"
#include "transactiontablemodel.h"
#include "transactionfilterproxy.h"
#include "guiutil.h"
#include "guiconstants.h"
#include "qtquick_controls/cpp/guibannerwidget.h"

#include "CSCPublicAPI/casinocoinwebapi.h"
#include "CSCPublicAPI/casinocoinwebapiparser.h"

#include <QAbstractItemDelegate>
#include <QPainter>
#include <QDebug>

#define DECORATION_SIZE 64
#define NUM_ITEMS 3

class TxViewDelegate : public QAbstractItemDelegate
{
    Q_OBJECT
public:
    TxViewDelegate(): QAbstractItemDelegate(), unit(BitcoinUnits::BTC)
    {

    }

    inline void paint(QPainter *painter, const QStyleOptionViewItem &option,
                      const QModelIndex &index ) const
    {
        painter->save();

        QIcon icon = qvariant_cast<QIcon>(index.data(Qt::DecorationRole));
        QRect mainRect = option.rect;
        QRect decorationRect(mainRect.topLeft(), QSize(DECORATION_SIZE, DECORATION_SIZE));
        int xspace = DECORATION_SIZE + 8;
        int ypad = 6;
        int halfheight = (mainRect.height() - 2*ypad)/2;
        QRect amountRect(mainRect.left() + xspace, mainRect.top()+ypad, mainRect.width() - xspace, halfheight);
        QRect addressRect(mainRect.left() + xspace, mainRect.top()+ypad+halfheight, mainRect.width() - xspace, halfheight);
        icon.paint(painter, decorationRect);

        QDateTime date = index.data(TransactionTableModel::DateRole).toDateTime();
        QString address = index.data(Qt::DisplayRole).toString();
        qint64 amount = index.data(TransactionTableModel::AmountRole).toLongLong();
        bool confirmed = index.data(TransactionTableModel::ConfirmedRole).toBool();
        QVariant value = index.data(Qt::ForegroundRole);
        QColor foreground = option.palette.color(QPalette::Text);
        if(value.canConvert<QBrush>())
        {
            QBrush brush = qvariant_cast<QBrush>(value);
            foreground = brush.color();
        }

        painter->setPen(foreground);
        painter->drawText(addressRect, Qt::AlignLeft|Qt::AlignVCenter, address);

        if(amount < 0)
        {
            foreground = COLOR_NEGATIVE;
        }
        else if(!confirmed)
        {
            foreground = COLOR_UNCONFIRMED;
        }
        else
        {
            foreground = option.palette.color(QPalette::Text);
        }
        painter->setPen(foreground);
        QString amountText = BitcoinUnits::formatWithUnit(unit, amount, true);
        if(!confirmed)
        {
            amountText = QString("[") + amountText + QString("]");
        }
        painter->drawText(amountRect, Qt::AlignRight|Qt::AlignVCenter, amountText);

        painter->setPen(option.palette.color(QPalette::Text));
        painter->drawText(amountRect, Qt::AlignLeft|Qt::AlignVCenter, GUIUtil::dateTimeStr(date));

        painter->restore();
    }

    inline QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
    {
        return QSize(DECORATION_SIZE, DECORATION_SIZE);
    }

    int unit;

};
#include "overviewpage.moc"

OverviewPage::OverviewPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OverviewPage),
    clientModel(0),
    walletModel(0),
    currentBalance(-1),
    currentUnconfirmedBalance(-1),
    currentImmatureBalance(-1),
    txdelegate(new TxViewDelegate()),
	filter(0),
    advertsWidget(0),
    cscWebApiParser( new CasinoCoinWebAPIParser( this ) ),
    cscWebApi( new CasinoCoinWebAPI( this ) )
{
    ui->setupUi(this);
	createAdvertsWidget();

    // Recent transactions
    ui->listTransactions->setItemDelegate(txdelegate);
    ui->listTransactions->setIconSize(QSize(DECORATION_SIZE, DECORATION_SIZE));
    ui->listTransactions->setMinimumHeight(NUM_ITEMS * (DECORATION_SIZE + 2));
    ui->listTransactions->setAttribute(Qt::WA_MacShowFocusRect, false);

    connect(ui->listTransactions, SIGNAL(clicked(QModelIndex)), this, SLOT(handleTransactionClicked(QModelIndex)));
    connect( cscWebApi, SIGNAL( signalResponseReady(const QByteArray&)), cscWebApiParser, SLOT( slotParseAnswer(const QByteArray&)), Qt::UniqueConnection );
    connect( cscWebApi, SIGNAL( signalNetworkError(QNetworkReply::NetworkError,const QUrl)), cscWebApiParser, SLOT( slotNetworkError(QNetworkReply::NetworkError,const QUrl)), Qt::UniqueConnection );
    connect( cscWebApiParser, SIGNAL( signalCoinInfoParsed(JsonCoinInfoParser*)), this, SLOT( updateCoinInfoFromWeb(JsonCoinInfoParser*)), Qt::UniqueConnection );

    // init "out of sync" warning labels
    ui->labelWalletStatus->setText("(" + tr("out of sync") + ")");
    ui->labelTransactionsStatus->setText("(" + tr("out of sync") + ")");

    // start with displaying the "out of sync" warnings
    showOutOfSyncWarning(true);

    // get CoinInfo from the web
    getCoinInfo();
}

void OverviewPage::handleTransactionClicked(const QModelIndex &index)
{
    if(filter)
        emit transactionClicked(filter->mapToSource(index));
}

OverviewPage::~OverviewPage()
{
    delete ui;
}

void OverviewPage::setBalance(qint64 balance, qint64 unconfirmedBalance, qint64 immatureBalance)
{
    int unit = walletModel->getOptionsModel()->getDisplayUnit();
    currentBalance = balance;
    currentUnconfirmedBalance = unconfirmedBalance;
    currentImmatureBalance = immatureBalance;
    ui->labelBalance->setText(BitcoinUnits::formatWithUnit(unit, balance));
    ui->labelUnconfirmed->setText(BitcoinUnits::formatWithUnit(unit, unconfirmedBalance));
    ui->labelImmature->setText(BitcoinUnits::formatWithUnit(unit, immatureBalance));

    // only show immature (newly mined) balance if it's non-zero, so as not to complicate things
    // for the non-mining users
    bool showImmature = immatureBalance != 0;
    ui->labelImmature->setVisible(showImmature);
	ui->labelImmatureText->setVisible(showImmature);
    // set fiat balance
    updateFiatBalance();
}

void OverviewPage::createAdvertsWidget()
{
	advertsWidget = new GUIBannerWidget( this );
	ui->verticalLayoutAdvertWidget->addWidget( advertsWidget->dockQmlToWidget(), Qt::AlignCenter );
	// first load from local files as its faster, than look for new ads in CasinoCoinAPI
//	advertsWidget->PopulateBannerLocally();
	advertsWidget->PopulateBannerFromWeb();
}

void OverviewPage::setClientModel(ClientModel *model)
{
    this->clientModel = model;
    if(model)
    {
        // Show warning if this is a prerelease version
        connect(model, SIGNAL(alertsChanged(QString)), this, SLOT(updateAlerts(QString)));
        updateAlerts(model->getStatusBarWarnings());
    }
}

void OverviewPage::setWalletModel(WalletModel *model)
{
    this->walletModel = model;
    if(model && model->getOptionsModel())
    {
        // Set up transaction list
        filter = new TransactionFilterProxy();
        filter->setSourceModel(model->getTransactionTableModel());
        filter->setLimit(NUM_ITEMS);
        filter->setDynamicSortFilter(true);
        filter->setSortRole(Qt::EditRole);
        filter->sort(TransactionTableModel::Status, Qt::DescendingOrder);

        ui->listTransactions->setModel(filter);
        ui->listTransactions->setModelColumn(TransactionTableModel::ToAddress);

        // Keep up to date with wallet
        setBalance(model->getBalance(), model->getUnconfirmedBalance(), model->getImmatureBalance());
        connect(model, SIGNAL(balanceChanged(qint64, qint64, qint64)), this, SLOT(setBalance(qint64, qint64, qint64)));

        connect(model->getOptionsModel(), SIGNAL(displayUnitChanged(int)), this, SLOT(updateDisplayUnit()));
    }

    // update the display unit, to not use the default ("BTC")
    updateDisplayUnit();
}

void OverviewPage::updateDisplayUnit()
{
    if(walletModel && walletModel->getOptionsModel())
    {
        if(currentBalance != -1)
            setBalance(currentBalance, currentUnconfirmedBalance, currentImmatureBalance);

        // Update txdelegate->unit with the current unit
        txdelegate->unit = walletModel->getOptionsModel()->getDisplayUnit();

        ui->listTransactions->update();
    }
}

void OverviewPage::updateAlerts(const QString &warnings)
{
    this->ui->labelAlerts->setVisible(!warnings.isEmpty());
    this->ui->labelAlerts->setText(warnings);
}

void OverviewPage::showOutOfSyncWarning(bool fShow)
{
    ui->labelWalletStatus->setVisible(fShow);
    ui->labelTransactionsStatus->setVisible(fShow);
}


void OverviewPage::on_pushButtonToggleAdverts_clicked()
{
	if ( ui->verticalLayoutAdvertWidget->itemAt( 0 ) )
	{
		QWidget* pAdvertWidget = ui->verticalLayoutAdvertWidget->itemAt( 0 )->widget();
		if ( pAdvertWidget )
		{
			pAdvertWidget->setVisible( !pAdvertWidget->isVisible() );
			if ( pAdvertWidget->isVisible() )
			{
				ui->pushButtonToggleAdverts->setText( tr( "Hide all advertisements" ) );
			}
			else
			{
				ui->pushButtonToggleAdverts->setText( tr( "Show advertisements" ) );
			}
		}
	}
}

void OverviewPage::getCoinInfo()
{
    if ( cscWebApi )
    {
        cscWebApi->GetCoinInfo();
    }
}

void OverviewPage::updateCoinInfoFromWeb( JsonCoinInfoParser* coinInfoParser )
{
    qDebug() << "CoinInfo ID: " << coinInfoParser->getCoinInfo().find("ID").value().toDouble();
    qDebug() << "CoinInfo InfoTime: " <<coinInfoParser->getCoinInfo().find("InfoTime").value().toString();
    // save the coin information
    coinInformation = coinInfoParser->getCoinInfo();
    // calculate and set the estimated fiat balance
    updateFiatBalance();
}

void OverviewPage::updateFiatBalance()
{
    if(!coinInformation.isEmpty())
    {
        int currency = walletModel->getOptionsModel()->getDisplayFiatCurrency();
        QString conversionCurrency = QString("Price").append(Currencies::name(currency));
        double currencyValue = coinInformation.find(conversionCurrency).value().toDouble();
        double fiatBalance = currentBalance * currencyValue * 0.00000001;
        qDebug() << "updateFiatBalance: " << QString::number(fiatBalance,'f',2);
        ui->labelBalanceFiat->setText(QString::number(fiatBalance,'f',2).append(" ").append(Currencies::name(currency)));
    }
}
