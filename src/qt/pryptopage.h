#ifndef PRYPTOPAGE_H
#define PRYPTOPAGE_H

#include <QDialog>
#include <QUrlQuery>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QProgressDialog>
#include <QList>

class WalletModel;

namespace Ui {
    class PryptoPage;
}

class PryptoPage : public QDialog
{
    Q_OBJECT

public:
    explicit PryptoPage(QWidget *parent = 0);
    void setWalletModel(WalletModel *model);
    ~PryptoPage();

signals:
    void apiResponseReady( const QByteArray& content );
    void apiNetworkError( const QNetworkReply::NetworkError& error );

private slots:
    void on_butRedeem_clicked();
    void parseAPINetworkResponse( QNetworkReply *finished );
    void showAPIResult(QByteArray data);
    void showAPINetworkError(QNetworkReply::NetworkError error);
    void sslErrorHandler(QNetworkReply* qnr, const QList<QSslError> & errlist);

private:
    static const QString strAPIEndpoint;
    static const QString strMerchantToken;
    static const QString strAddressLabel;

    Ui::PryptoPage *ui;
    QNetworkAccessManager networkAccessManager;
    WalletModel *walletModel;
    QProgressDialog *busyDialog;
};

#endif // PRYPTOPAGE_H
