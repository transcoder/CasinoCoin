#include "currencies.h"
#include <QStringList>
#include <QLocale>

Currencies::Currencies(QObject *parent):
    QAbstractListModel(parent),
    currencylist(availableCurrencies())
{
}

QList<Currencies::FiatCurrencyID> Currencies::availableCurrencies()
{
    QList<Currencies::FiatCurrencyID> currencylist;
    currencylist.append(USD);
    currencylist.append(EUR);
    currencylist.append(CNY);
    currencylist.append(JPY);
    currencylist.append(RUB);
    return currencylist;
}

bool Currencies::valid(int currency)
{
    switch(currency)
    {
    case USD:
    case EUR:
    case CNY:
    case JPY:
    case RUB:
        return true;
    default:
        return false;
    }
}

QString Currencies::name(int currency)
{
    switch(currency)
    {
    case USD: return QString("USD");
    case EUR: return QString("EUR");
    case CNY: return QString("CNY");
    case JPY: return QString("JPY");
    case RUB: return QString("RUB");
    default: return QString("???");
    }
}

QString Currencies::description(int currency)
{
    switch(currency)
    {
    case USD: return QString("US Dollars");
    case EUR: return QString("European Euro");
    case CNY: return QString("Chinese Yuan");
    case JPY: return QString("Japanese Yen");
    case RUB: return QString("Russian Ruble");
    default: return QString("???");
    }
}

QString Currencies::symbol(int currency)
{
    switch(currency)
    {
    case USD: return QString("$");
    case EUR: return QString("€");
    case CNY: return QString("¥");
    case JPY: return QString("¥");
    case RUB: return QString("₽");
    default: return QString("$");
    }
}

QString Currencies::format(int currency, double value, bool useSymbol)
{
    // divide by satoshi
    double fiatValue = value * 0.00000001;
    QString formattedValue = "";
    if(useSymbol)
    {
        formattedValue.append(symbol(currency)).append(" ");
    }
    // apply format
    QLocale::setDefault( QLocale(QLocale::English, QLocale::UnitedStates) );
    formattedValue.append(QString("%L1").arg(fiatValue, 0, 'f', 2)).append(" ").append(name(currency));
    return formattedValue;
}

int Currencies::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return currencylist.size();
}

QVariant Currencies::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    if(row >= 0 && row < currencylist.size())
    {
        FiatCurrencyID currency = currencylist.at(row);
        switch(role)
        {
        case Qt::EditRole:
        case Qt::DisplayRole:
            return QVariant(name(currency));
        case Qt::ToolTipRole:
            return QVariant(description(currency));
        case CurrencyRole:
            return QVariant(static_cast<int>(currency));
        }
    }
    return QVariant();
}

