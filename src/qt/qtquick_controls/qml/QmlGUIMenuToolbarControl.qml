import QtQuick 2.0
import CasinoCoinControls 1.0

GUIMenuToolbarControl
{
	id: id_toolbarControl

	Rectangle
	{
		id: id_toolbarRect
		anchors.top: id_toolbarControl.top
		anchors.left: id_toolbarControl.left
		width: id_toolbarControl.width
		height: id_toolbarControl.height - id_toolbarBottomStripe.height
		gradient:
		Gradient
		{
			GradientStop { position: 0.0; color: GUI20Skin.colorToolbarMainGradientBegin }
			GradientStop { position: 1.0; color: GUI20Skin.colorToolbarMainGradientEnd }
		}
		z: 0
		QmlGUIMenuToolbarListView
		{
			id: id_menuToolbarListView
			width: id_toolbarControl.width
			anchors.left: id_toolbarRect.left
			anchors.top: id_toolbarRect.top

			Component.onCompleted:
			{
                id_toolbarControl.initializeMenuToolbarView( id_menuToolbarListView )
			}
			z: 2
		}
		Rectangle
		{
			id: id_currentSelectionIndicator
			height: id_toolbarControl.height
			width: height
			color: GUI20Skin.colorToolbarMainCurrent
			z: 1
			x: id_menuToolbarListView.m_iCurrentItemXProperty
			Rectangle
			{
				id: id_toolbarBottomStripe
				width: id_currentSelectionIndicator.width
				height: 5
				anchors.bottom: id_currentSelectionIndicator.bottom
				color: GUI20Skin.colorToolbarMainBottomCurrent
			}
			Behavior on x
			{
				NumberAnimation { duration: 300; easing.type: Easing.InOutQuad }
			}
		}
		Image
		{
			id: id_cardsImage
			anchors.top: id_toolbarRect.top
			anchors.right: id_toolbarRect.right
			source: "qrc:/images/res/images/GUI20_mainToolBar_cards.png"
		}
		Rectangle
		{
			id: id_visitWebsiteBox
			height: id_visitWebsiteText.height + id_visitWebsiteURL.height
			width: id_visitWebsiteText.width
			anchors.rightMargin: 20
			anchors.right: id_toolbarRect.right
			anchors.topMargin: 25
			anchors.top: id_toolbarRect.top
			color: "transparent"
			Column
			{
				anchors.right: id_visitWebsiteBox.right
				anchors.top: id_visitWebsiteBox.top
				Text
				{
					id: id_visitWebsiteText
					text: id_toolbarControl.p_strVisitWebsiteText
					color: GUI20Skin.colorToolbarMainTextVisitWebsite
				}
				Text
				{
					id: id_visitWebsiteURL
					text: id_toolbarControl.p_strWebsiteURL
					font.bold: true
					color: GUI20Skin.colorToolbarMainTextWebsiteURL
				}
			}

			MouseArea
			{
				id: id_visitWebsiteMouseArea
				anchors.fill: id_visitWebsiteBox
				onClicked:
				{
					console.log( "clicked hehe" )
					signalOurWebsiteURLClicked()
				}
			}
		}
	}
}
