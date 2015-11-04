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
				id_toolbarControl.InitializeMenuToolbarView( id_menuToolbarListView )
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
	}
}
