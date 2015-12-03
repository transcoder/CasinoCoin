#ifndef CURRENCIES_H
#define CURRENCIES_H

#include <QAbstractListModel>

class Currencies : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit Currencies(QObject *parent);

    enum FiatCurrencyID {
        USD,
        EUR,
        CNY,
        JPY,
        RUB,
    };

    //! Get list of currencies, for drop-down box
    static QList<FiatCurrencyID> availableCurrencies();
    //! Is currency ID valid?
    static bool valid(int currency);
    //! Short name
    static QString name(int currency);
    //! Longer description
    static QString description(int unit);
    //! symbol
    static QString symbol(int currency);
    //! Format value
    static QString format(int currency, double value, bool symbol);

    //! @name AbstractListModel implementation
    //! List model for currency drop-down selection box.
    ///@{
    enum RoleIndex {
        /** Currency identifier */
        CurrencyRole = Qt::UserRole
    };
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    ///@}

private:
    QList<Currencies::FiatCurrencyID> currencylist;
};
typedef Currencies::FiatCurrencyID Currency;

#endif // CURRENCIES_H
