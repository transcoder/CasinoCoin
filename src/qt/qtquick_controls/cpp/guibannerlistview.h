#ifndef GUIBANNERLISTVIEW_H
#define GUIBANNERLISTVIEW_H

#include <QQuickItem>

class QmlListModel;
class QmlBannerListModel;
class QmlBannerListItem;

class GUIBannerListView : public QQuickItem
{
	Q_OBJECT
	Q_PROPERTY( QmlBannerListModel* p_pListModel MEMBER m_pModel NOTIFY signalModelChanged )

public:
	explicit GUIBannerListView( QQuickItem *a_pParent = 0 );
	virtual ~GUIBannerListView();																			/** Destructor **/

    void setModel( QmlBannerListModel* a_pModel );
    QmlBannerListModel* setModel() const { return m_pModel; }

    void clear();

    Q_INVOKABLE void onClicked( int a_iItemIndex );
signals:
	void signalModelChanged();

public slots:

private:

	QmlBannerListModel* m_pModel;
};

#endif // GUIBANNERLISTVIEW_H
