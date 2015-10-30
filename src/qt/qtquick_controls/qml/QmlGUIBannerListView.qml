import QtQuick 2.0
import CasinoCoinControls 1.0

GUIBannerListView
{
	id: id_bannerView

	property int m_iItemBorderWidth: 1
	property int m_iColumnWidth: 0
	property alias m_ListModel: id_pathView.model
	property alias m_PathView: id_pathView

	PathView
	{
		id: id_pathView
		anchors.fill: id_bannerView

		pathItemCount: 3
		highlightRangeMode: PathView.StrictlyEnforceRange
		highlightMoveDuration: 1000
		preferredHighlightBegin: 0.5
		preferredHighlightEnd: 0.5
		visible: true
		interactive: false

		model: id_bannerView.p_pListModel
		delegate: id_elementDelegate
		path: Path
		{
			startX: 30; startY: id_bannerView.height / 2
			PathLine { x: id_bannerView.width - 30; y: id_bannerView.height / 2 }
		}
	}

	Component
	{
		id: id_elementDelegate
		Rectangle
		{
			id: id_listElement
			objectName: id_bannerView.objectName + "_Element" + index

			width: 115
			height: width

			Image
			{
				id: id_advertisementImage
				source: m_imageSource
				scale: ( id_listElement.width / width )
				anchors.centerIn: id_listElement
			}

			// coming soon
//			QmlImageProvider
//			{
//				id: id_advertisementImage
//				scale: ( id_listElement.width / width )
//				anchors.centerIn: id_listElement
//			}
			MouseArea
			{
				id: id_leftItemMouseArea
				anchors.fill: id_listElement
				onClicked:
				{
					id_bannerView.OnClicked( index )
				}
			}
		}
	}

}
