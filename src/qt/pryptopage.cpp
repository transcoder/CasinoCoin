#include "pryptopage.h"
#include "ui_pryptopage.h"

PryptoPage::PryptoPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PryptoPage)
{
    ui->setupUi(this);
}

PryptoPage::~PryptoPage()
{
    delete ui;
}

void PryptoPage::on_butRedeem_clicked()
{

}
