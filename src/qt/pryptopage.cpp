#include "pryptopage.h"
#include "ui_pryptopage.h"
#include "walletmodel.h"
#include "addresstablemodel.h"
#include <QSsl>
#include <QMessageBox>
#include <QDebug>
#include <QListIterator>

const QString PryptoPage::strAPIEndpoint = "https://prypto.com/merchants/api/";
const QString PryptoPage::strMerchantToken = "35616ab118fa557b77fdac78ef09d5632d302609";
const QString PryptoPage::strAddressLabel = "Prypto Cards";

PryptoPage::PryptoPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PryptoPage)
{
    ui->setupUi(this);
    connect( &networkAccessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(parseAPINetworkResponse(QNetworkReply*)) );
    connect( this, SIGNAL(apiResponseReady(QByteArray)), this, SLOT(showAPIResult(QByteArray)) );
    connect( this, SIGNAL(apiNetworkError(QNetworkReply::NetworkError)), this, SLOT(showAPINetworkError(QNetworkReply::NetworkError)) );
    connect( &networkAccessManager, SIGNAL(sslErrors(QNetworkReply*, const QList<QSslError> & )), this, SLOT(sslErrorHandler(QNetworkReply*, const QList<QSslError> & )));
}

void PryptoPage::setWalletModel(WalletModel *model)
{
    this->walletModel = model;
}

void PryptoPage::on_butRedeem_clicked()
{
    if((ui->txtPryptoCode->text().length() == 0) ||
       (ui->txtSecurityCode->text().length() == 0))
    {
        QMessageBox msgBox;
        msgBox.setText("Both Prypto code and Security code must be entered.");
        msgBox.exec();
    }
    else
    {
        // Show Busy Indicator
        busyDialog = new QProgressDialog(this);
        busyDialog->setWindowModality(Qt::WindowModal);
        busyDialog->setLabelText("Calling Prypto Services ...");
        busyDialog->setCancelButton(0);
        busyDialog->setRange(0,0);
        busyDialog->setMinimumDuration(0);
        busyDialog->show();
        // get wallet address for redeem action
        QString pryptoWalletAddress = walletModel->getAddressTableModel()->addressForLabel(strAddressLabel);
        // create new if empty
        if(pryptoWalletAddress == "")
        {
            pryptoWalletAddress = walletModel->getAddressTableModel()->addRow(AddressTableModel::Receive, strAddressLabel, "");
        }
        // call service
        QUrl url ( strAPIEndpoint );
        QUrlQuery query;
        query.addQueryItem("T", "RX");
        query.addQueryItem("TKN", strMerchantToken);
        query.addQueryItem("COIN", "CSC");
        query.addQueryItem("PC", ui->txtPryptoCode->text());
        query.addQueryItem("SC", ui->txtSecurityCode->text());
        query.addQueryItem("RX", pryptoWalletAddress);
        url.setQuery(query.query());
        QNetworkRequest networkRequest ( url );
        networkAccessManager.get( networkRequest );
     }
}

void PryptoPage::parseAPINetworkResponse( QNetworkReply *finished )
{
    if ( finished->error() != QNetworkReply::NoError )
    {
        // A communication error has occurred
        qDebug() << "API Network Error: " << finished->errorString() << " URL: " << finished->url();
        busyDialog->cancel();
        emit apiNetworkError( finished->error());
        return;
    }
    QByteArray data = finished->readAll();
    qDebug() << "API data: " << data;
    busyDialog->cancel();
    emit apiResponseReady( data );
}

void PryptoPage::sslErrorHandler(QNetworkReply* qnr, const QList<QSslError> & errlist)
{
qDebug() << "---PryptoPage::sslErrorHandler: ";
qnr->ignoreSslErrors();
}

void PryptoPage::showAPINetworkError(QNetworkReply::NetworkError error)
{
    qDebug() << "PryptoPage::showAPINetworkError: " << error;
    QMessageBox msgBox;
    msgBox.setText("Error redeeming Prypto Card.");
    msgBox.exec();
}

void PryptoPage::showAPIResult(QByteArray data)
{
    // reset text fields
    ui->txtPryptoCode->setText("");
    ui->txtSecurityCode->setText("");
    // handle result
    if(data.length() > 0)
    {
        qDebug() << "API Result: " << data;
        QMessageBox msgBox;
        msgBox.setText("Prypto Card succesfully redeemed.");
        msgBox.exec();
    }
    else
    {
        qDebug() << "API Empty Result";
        QMessageBox msgBox;
        msgBox.setText("Prypto Card already redeemed or invalid.");
        msgBox.exec();
    }
}

PryptoPage::~PryptoPage()
{
    delete ui;
}
