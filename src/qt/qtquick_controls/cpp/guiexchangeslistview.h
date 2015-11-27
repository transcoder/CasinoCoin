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

	void SetModel( QmlExchangesListModel* a_pModel );
	QmlExchangesListModel* GetModel() const { return m_pModel; }

	void Clear();

	Q_INVOKABLE void OnClicked( int a_iItemIndex );
signals:
	void signalModelChanged();

public slots:

private:

	QmlExchangesListModel* m_pModel;
};

#endif // GUIEXCHANGESLISTVIEW_H
