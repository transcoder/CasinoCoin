import QtQuick 2.0
import CasinoCoinControls 1.0

GUIMenuToolbarListView
{
	id: id_ListViewItem

	property alias m_ListModel: id_ListView.model
	property alias m_ListView: id_ListView
	property real m_iCurrentItemXProperty: id_ListView.currentIndex * id_toolbarControl.height
	property real m_iCppCurrentIndex: p_pListModel.p_iCurrentElementIndex

	ListView
	{
		id: id_ListView
		anchors.fill: id_ListViewItem

		model: p_pListModel
		delegate: id_menuToolbarViewDelegate

		orientation: ListView.Horizontal
		currentIndex: m_iCppCurrentIndex
	}


	Component
	{
		id: id_menuToolbarViewDelegate
		Rectangle
		{
			id: id_delegateRect
			height: id_toolbarControl.height
			width: height
			color: "transparent"
			z: 1
			Rectangle
			{
				id: id_singleButton
				height: id_toolbarControl.height - id_toolbarBottomStripe.height
				width: id_delegateRect.width
				color: "transparent"
				Image
				{
					id: id_singleButtonImage
					source: id_delegateMouseArea.containsMouse ? m_imageHoverSource : p_pListModel.p_iCurrentElementIndex == index ? m_imageHoverSource : m_imageNormalSource
					anchors.centerIn: id_singleButton
				}
				Text
				{
					id: id_singleButtonText

					text: m_text
					wrapMode: Text.Wrap
					color: id_delegateMouseArea.containsMouse ? GUI20Skin.colorToolbarMainTextCurrent : p_pListModel.p_iCurrentElementIndex == index ? GUI20Skin.colorToolbarMainTextCurrent : GUI20Skin.colorToolbarMainTextNormal
					style: Text.Sunken
					styleColor: GUI20Skin.colorToolbarMainTextShadow
					font.pixelSize: 10

					anchors.bottom: id_singleButton.bottom
					anchors.bottomMargin: 5
					anchors.horizontalCenter: id_singleButton.horizontalCenter

				}
			}
			MouseArea
			{
				id: id_delegateMouseArea
				anchors.fill: id_singleButton
				hoverEnabled: true
				onClicked:
				{
					OnClicked( index )
				}
			}
		}

	}
}

