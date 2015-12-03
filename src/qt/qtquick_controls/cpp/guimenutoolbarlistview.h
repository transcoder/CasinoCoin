#ifndef GUIMENUTOOLBARLISTVIEW_H
#define GUIMENUTOOLBARLISTVIEW_H

#include <QQuickItem>

class QmlListModel;
class QmlMenuToolbarModel;
class QmlMenuToolbarItem;


class GUIMenuToolbarListView : public QQuickItem
{
	Q_OBJECT
	Q_PROPERTY( QmlMenuToolbarModel* p_pListModel MEMBER m_pModel NOTIFY signalModelChanged )

public:
	explicit GUIMenuToolbarListView( QQuickItem *a_pParent = 0 );
	virtual ~GUIMenuToolbarListView();																			/** Destructor **/

	void SetModel( QmlMenuToolbarModel* a_pModel );
	QmlMenuToolbarModel* GetModel() const { return m_pModel; }

	void Clear();

	Q_INVOKABLE void OnClicked( int a_iItemIndex );
signals:
	void signalModelChanged();

public slots:

private:

	QmlMenuToolbarModel* m_pModel;
};

#endif // GUIMENUTOOLBARLISTVIEW_H
