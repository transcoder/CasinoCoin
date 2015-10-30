#ifndef QMLLISTMODEL_H
#define QMLLISTMODEL_H

#include <QAbstractListModel>
#include <QColor>

#include "qmllistitem.h"

class QmlListModel : public QAbstractListModel
{
	Q_OBJECT

	Q_PROPERTY( int count READ rowCount NOTIFY signalCountChanged )
	Q_PROPERTY( int p_iCurrentElementIndex MEMBER m_iCurrentElementIndex NOTIFY signalCurrentItemIndexChanged )
public:
	//////////////////
	// Methods
	explicit QmlListModel( QObject* a_pParent = 0 );													/** Default Constructor **/
	explicit QmlListModel( ListItemInterface* a_pPrototype, QObject* a_pParent = 0 );					/** Constructor with item prototype **/
	virtual ~QmlListModel();																			/** Destructor **/

	int rowCount( const QModelIndex& a_rParent = QModelIndex() ) const;									/** size of list getter **/
	QVariant data( const QModelIndex& a_rIndex, int a_iRole = Qt::DisplayRole ) const;					/** function returning model data at specific index **/
	virtual bool setData																				/** Sets the role data for the item at index to value. **/
			( const QModelIndex& a_rIndex
			, const QVariant& a_rValue
			, int a_iRole = Qt::EditRole
			);
	QHash<int, QByteArray> roleNames() const;															/** returns user defined roles for model **/
	bool removeRows( int a_iRow, int a_iCount, const QModelIndex& a_rParent = QModelIndex() );			/** deletes /count/ rows from model starting at /row/ **/

	// Methods created to match QML Model style of data manipulation
	Q_INVOKABLE void append( ListItemInterface* a_pItem );												/** appends /a_pItem/ element to the list **/
	Q_INVOKABLE void insert( int a_iIndex, ListItemInterface* a_pItem );								/** insert /a_pItem/ to the list before the given /a_iIndex/ **/
	Q_INVOKABLE QVariant get( int a_iIndex );															/** returns QMap containing value<->role pa at /a_iIndex/ **/
	Q_INVOKABLE void clear();																			/** clears the list **/
	Q_INVOKABLE void refresh();																			/** refreshes the list **/

	inline const ListItemInterface* GetItem( int a_iIndex ) const;										/** Get item at index **/
	int GetItemIndex( int a_iItemRole, QVariant a_variantValue ) const;									/** Get index of first item having given a_variantValue at given a_iItemRole **/

	/** NOTE!!
	This three methods have their implementation, however whole
	currentItem system must be implemented manually for every derived class. **/
	ListItemInterface* GetCurrentItem() const;															/** Get current item pointer **/
	virtual void SetCurrentItemIndex( int a_iIndex );													/** Set current item index **/
	int GetCurrentItemIndex() const;																	/** Get current item index **/

	bool SetData( int a_iIndex, const QVariant& a_rValue, int a_iRole );								/** Sets the role data for the item at index to value. **/
	QVariant GetData( int a_iIndex, int a_iRole );														/** Get model data at specific index **/

	void Sort( int a_iRole, Qt::SortOrder a_eOrder = Qt::AscendingOrder );								/** Sort items in list model by role in the given order **/

signals:
	void signalCountChanged( int a_iNewCount );															/** notify that list contents changed **/
	void signalCurrentItemIndexChanged();																/** notify that currently highlighted/focused item changed **/
	void signalCurrentItemIndexClicked();																/** notify that currently highlighted/focused item was clicked again **/
	void signalTextColorCol1Changed();																	/** notify that text color in col1 changed **/
	void signalTextSizeChanged();																		/** notify that text size changed **/
	void signalRowHeightChanged();																		/** notify that row height changed **/
protected:
	/////////////////
	// Methods
	virtual int Compare( int a_iRole, QVariant& a_rValue1, QVariant& a_rValue2 );						/** Compare two values with given role **/

	//////////////////
	// Properties
	ListItemInterface*				m_pPrototype;														/** information on what type is held in a list **/
	QList<ListItemInterface*>		m_aItems;															/** list with model data **/
	int								m_iCurrentElementIndex;												/** current element index **/
};

const ListItemInterface* QmlListModel::GetItem( int a_iIndex ) const
{
	if ( m_aItems.size() > a_iIndex && a_iIndex >= 0 )
	{
		return m_aItems[a_iIndex];
	}
	return 0;
}


#endif // QMLLISTMODEL_H
