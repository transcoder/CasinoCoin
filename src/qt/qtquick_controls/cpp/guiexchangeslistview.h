#ifndef GUIEXCHANGESLISTVIEW_H
#define GUIEXCHANGESLISTVIEW_H

#include <QQuickItem>

class QmlListModel;
class QmlExchangesListModel;
class QmlExchangesListItem;

class GUIExchangesListView : public QQuickItem
{
	Q_OBJECT
	Q_PROPERTY( QmlExchangesListModel* p_pListModel MEMBER m_pModel NOTIFY signalModelChanged )

public:
	explicit GUIExchangesListView( QQuickItem *a_pParent = 0 );
	virtual ~GUIExchangesListView();																			/** Destructor **/

    void setModel( QmlExchangesListModel* a_pModel );
    QmlExchangesListModel* getModel() const { return m_pModel; }

    void clear();

    Q_INVOKABLE void onClicked( int a_iItemIndex );

signals:
	void signalModelChanged();

public slots:

private:

	QmlExchangesListModel* m_pModel;
};

#endif // GUIEXCHANGESLISTVIEW_H
