#ifndef PRYPTOPAGE_H
#define PRYPTOPAGE_H

#include <QDialog>

namespace Ui {
    class PryptoPage;
}

class PryptoPage : public QDialog
{
    Q_OBJECT

public:
    explicit PryptoPage(QWidget *parent = 0);
    ~PryptoPage();

private slots:
    void on_butRedeem_clicked();

private:
    Ui::PryptoPage *ui;
};

#endif // PRYPTOPAGE_H
