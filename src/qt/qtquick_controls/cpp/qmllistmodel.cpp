#include "qmllistmodel.h"

#include <QDebug>

QmlListModel::QmlListModel( QObject* a_pParent )
	: QAbstractListModel( a_pParent )
	, m_pPrototype( 0 )
	, m_iCurrentElementIndex( -1 )
{
	m_aItems = QList<ListItemInterface*>();
}

QmlListModel::QmlListModel( ListItemInterface* a_pPrototype, QObject* a_pParent )
	: QAbstractListModel( a_pParent )
	, m_pPrototype( a_pPrototype )
	, m_iCurrentElementIndex( -1 )
{	
	m_aItems = QList<ListItemInterface*>();
}

QmlListModel::~QmlListModel()
{
	clear();
	if ( m_pPrototype )
	{
		delete m_pPrototype;
		m_pPrototype = 0;
	}
}

int QmlListModel::rowCount( const QModelIndex& a_rParent ) const
{
	Q_UNUSED( a_rParent );
	return m_aItems.size();
}

QVariant QmlListModel::data( const QModelIndex& a_rIndex, int a_iRole ) const
{
	if ( a_rIndex.row() < 0 )
	{
		return QVariant();
	}
	if ( a_rIndex.row() > m_aItems.size() )
	{
		return QVariant();
	}
	ListItemInterface* pValidate = m_aItems.at( a_rIndex.row() );
	if ( pValidate )
	{
		return pValidate->GetData( a_iRole );
	}
	return QVariant();
}

bool QmlListModel::setData( const QModelIndex& a_rIndex, const QVariant& a_rValue, int a_iRole )
{
	if ( a_rIndex.isValid() && a_iRole > Qt::UserRole )
	{
		ListItemInterface* pItem = m_aItems.at( a_rIndex.row() );
		if ( pItem )
		{
			if ( pItem->SetData( a_iRole, a_rValue ) )
			{
				emit dataChanged( a_rIndex, a_rIndex );
				return true;
			}
		}
	}
	return false;
}

QHash<int, QByteArray> QmlListModel::roleNames() const				//NS
{
	if ( m_pPrototype )
	{
		return m_pPrototype->RoleNames();
	}
	return ( QHash<int, QByteArray>() );
}

bool QmlListModel::removeRows( int a_iRow, int a_iCount, const QModelIndex& a_rParent )		//NS
{
	if ( a_iRow < 0 )
	{
		return false;
	}
	if ( a_iCount <= 0 )
	{
		return false;
	}
	if ( ( a_iRow + a_iCount ) > m_aItems.size() )
	{
		return false;
	}
	beginRemoveRows( a_rParent, a_iRow, a_iRow + a_iCount - 1 );
	for ( int i = 0; i < a_iCount; i++ )
	{
		ListItemInterface* pItem = m_aItems.takeAt( a_iRow );
		delete pItem;
		pItem = 0;
	}
	endRemoveRows();
	emit signalCountChanged( rowCount() );
	return true;
}

void QmlListModel::append( ListItemInterface* a_pItem )					//NS
{
	if ( a_pItem != 0 )
	{
		beginInsertRows( QModelIndex(), rowCount(), rowCount() );
		m_aItems.append( a_pItem );
		a_pItem->setObjectName( objectName() + "_item_" + QString::number( rowCount() ) );
		endInsertRows();
		emit signalCountChanged( rowCount() );
	}
}

void QmlListModel::insert( int a_iIndex, ListItemInterface* a_pItem )					//NS
{
	if ( a_pItem != 0 && a_iIndex >= 0 && a_iIndex <= m_aItems.size() )
	{
		beginInsertRows( QModelIndex(), a_iIndex, a_iIndex );
		m_aItems.insert( a_iIndex, a_pItem );
		a_pItem->setObjectName( objectName() + "_item_" + QString::number( a_iIndex ) );
		endInsertRows();
		emit signalCountChanged( rowCount() );
	}
}

QVariant QmlListModel::get( int a_iIndex )
{
	if ( a_iIndex < 0 )
	{
		return QVariant();
	}
	if ( a_iIndex >= m_aItems.size() )
	{
		return QVariant();
	}
	QMap<QString, QVariant> aItemData;
	ListItemInterface* pItem = m_aItems.at( a_iIndex );
	if ( pItem )
	{
		QHashIterator<int, QByteArray> aRolesItr( pItem->RoleNames() );
		while ( aRolesItr.hasNext() )
		{
			aRolesItr.next();
			aItemData.insert( aRolesItr.value(), QVariant( pItem->GetData( aRolesItr.key() ) ) );
		}
		return QVariant( aItemData );
	}
	return QVariant();
}

void QmlListModel::clear()
{
	if ( m_aItems.size() > 0 )
	{
		removeRows( 0, m_aItems.size() );
		// signalCountChanged emitted inside removeRows
	}
}

void QmlListModel::refresh()
{
	if ( m_aItems.size() > 0 )
	{
		beginResetModel();
		endResetModel();
	}
}

int QmlListModel::GetItemIndex( int a_iItemRole, QVariant a_variantValue ) const
{
	for ( int i = 0; i < m_aItems.size(); i++ )
	{
		if ( m_aItems[i]->GetData( a_iItemRole ) == a_variantValue )
		{
			return i;
		}
	}
	return -1;
}

ListItemInterface* QmlListModel::GetCurrentItem() const
{

	if ( m_iCurrentElementIndex >= 0 && m_aItems.size() > m_iCurrentElementIndex )
	{
		return m_aItems[m_iCurrentElementIndex];
	}
	return 0;
}

void QmlListModel::SetCurrentItemIndex( int a_iIndex )
{

	if	(	a_iIndex == -1
		||	( a_iIndex >= 0 && a_iIndex < rowCount() )
			)
	{
		if ( m_iCurrentElementIndex != a_iIndex )
		{
			m_iCurrentElementIndex = a_iIndex;
			emit signalCurrentItemIndexChanged();
		}
		else
		{
			if ( m_iCurrentElementIndex != -1 )
			{
				emit signalCurrentItemIndexClicked();
			}
		}
	}	
}

int QmlListModel::GetCurrentItemIndex() const
{
	return m_iCurrentElementIndex;
}

bool QmlListModel::SetData( int a_iIndex, const QVariant& a_rValue, int a_iRole )
{
	QModelIndex modelIndex = createIndex( a_iIndex, 0 );
	return setData( modelIndex, a_rValue, a_iRole );
}

QVariant QmlListModel::GetData( int a_iIndex, int a_iRole )
{	
	QModelIndex modelIndex = createIndex( a_iIndex, 0 );
	return data( modelIndex, a_iRole );
}

void QmlListModel::Sort( int a_iRole, Qt::SortOrder a_eOrder )
{	
	QList<ListItemInterface*>	aSortedList;

	if ( a_eOrder == Qt::AscendingOrder )
	{
		foreach ( ListItemInterface* pItem, m_aItems )
		{
			int			iSortedIndex		= 0;
			const int	iSortedListCount	= aSortedList.count();
			QVariant	valueOriginal		= pItem->GetData( a_iRole );

			bool bIndexFound = false;
			for ( iSortedIndex = iSortedListCount - 1 ; iSortedIndex >= 0 ; --iSortedIndex )
			{
				const ListItemInterface* pSortedItem = aSortedList.at( iSortedIndex );
				if ( pSortedItem )
				{
					QVariant valueSorted = pSortedItem->GetData( a_iRole );
					if ( Compare( a_iRole, valueOriginal, valueSorted ) > 0 )
					{
						aSortedList.insert( iSortedIndex + 1, pItem );
						bIndexFound = true;
						break;
					}
				}
			}
			if ( !bIndexFound )
			{
				aSortedList.prepend( pItem );
			}
		}
	}
	else if ( Qt::DescendingOrder )
	{
		foreach ( ListItemInterface* pItem, m_aItems )
		{
			int			iSortedIndex		= 0;
			const int	iSortedListCount	= aSortedList.count();
			QVariant	valueOriginal		= pItem->GetData( a_iRole );

			bool bIndexFound = false;
			for ( iSortedIndex = 0 ; iSortedIndex < iSortedListCount ; ++iSortedIndex )
			{
				const ListItemInterface* pSortedItem = aSortedList.at( iSortedIndex );
				if ( pSortedItem )
				{
					QVariant valueSorted = pSortedItem->GetData( a_iRole );
					if ( Compare( a_iRole, valueOriginal, valueSorted ) > 0 )
					{
						aSortedList.insert( iSortedIndex, pItem );
						bIndexFound = true;
						break;
					}
				}
			}
			if ( !bIndexFound )
			{
				aSortedList.append( pItem );
			}
		}
	}
	m_aItems = aSortedList;

	emit dataChanged( createIndex( 0, 0 ), createIndex( rowCount() - 1, 0 ) );
}

int QmlListModel::Compare( int a_iRole, QVariant& a_rValue1, QVariant& a_rValue2 )
{
	Q_UNUSED( a_iRole );
	int iReturn = 0;
	if ( a_rValue1 > a_rValue2 )
	{
		iReturn = 1;
	}
	else if ( a_rValue1 < a_rValue2 )
	{
		iReturn = -1;
	}
	return iReturn;
}
