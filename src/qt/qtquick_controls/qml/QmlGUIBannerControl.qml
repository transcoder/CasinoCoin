import QtQuick 2.2
import CasinoCoinControls 1.0

GUIBannerControl
{
	id: id_bannerControl

	property color colorBackgroundInWidget: GUI20Skin.colorFrameBackground
	Rectangle
	{
		id: id_leftArrow
		height: id_bannerControl.height
		width: 30
		color: colorBackgroundInWidget
		Image
		{
			id: id_leftArrowImage

			source: "qrc:/icons/advertsArrowLeft"

			anchors.centerIn: id_leftArrow
		}
		anchors.left: id_bannerControl.left

		MouseArea
		{
			id: id_leftArrowMouseArea
			anchors.fill: id_leftArrow

			hoverEnabled: true

			onEntered:
			{
				id_leftArrowImage.source = "qrc:/icons/advertsArrowLeftHover"
				id_bannerListView.m_PathView.decrementCurrentIndex()
				id_animationTimer.restart()
			}
			onExited:
			{
				id_leftArrowImage.source = "qrc:/icons/advertsArrowLeft"
				id_animationTimer.stop()
			}
			onClicked:
			{
				id_bannerListView.m_PathView.decrementCurrentIndex()
			}
		}
	}
	Rectangle
	{
		id: id_BannersArea
		height: id_bannerControl.height
		width: id_bannerControl.width - id_leftArrow.width - id_rightArrow.width
		color: colorBackgroundInWidget
		z: -1

		anchors.horizontalCenter: id_bannerControl.horizontalCenter
		anchors.left: id_leftArrow.left
		Rectangle
		{
			id: id_fadeOutLeft

			height: id_BannersArea.width / 6
			width: id_BannersArea.height
			rotation: 270
			z: 1

			anchors.left: id_BannersArea.left
			anchors.verticalCenter: id_BannersArea.verticalCenter
			gradient:
			Gradient
			{
				GradientStop { position: 0.0; color: colorBackgroundInWidget }
				GradientStop { position: 0.7; color: "transparent" }
				GradientStop { position: 1.0; color: "transparent" }
			}
	}
	QmlGUIBannerListView
	{
		id: id_bannerListView

		anchors.fill: id_BannersArea
		Component.onCompleted:
		{
			id_bannerControl.InitializeAdvertsView( id_bannerListView )
		}
	}
	Rectangle
	{
		id: id_fadeOutRight

		height: id_BannersArea.width / 6
		width: id_BannersArea.height
		rotation: 90
		z: 1

		anchors.right: id_BannersArea.right
		anchors.verticalCenter: id_BannersArea.verticalCenter
		gradient:
		Gradient
		{
			GradientStop { position: 0.0; color: colorBackgroundInWidget }
			GradientStop { position: 0.7; color: "transparent" }
			GradientStop { position: 1.0; color: "transparent" }
		}
	}
}
	Rectangle
	{
		id: id_rightArrow
		height: id_bannerControl.height
		width: 30
		color: colorBackgroundInWidget
		Image
		{
			id: id_rightArrowImage
			source: "qrc:/icons/advertsArrowRight"

			anchors.centerIn: id_rightArrow
		}

		anchors.right: id_bannerControl.right

		MouseArea
		{
			id: id_rightArrowMouseArea
			anchors.fill: id_rightArrow

			hoverEnabled: true

			onEntered:
			{
				id_rightArrowImage.source = "qrc:/icons/advertsArrowRightHover"
				id_bannerListView.m_PathView.incrementCurrentIndex()
				id_animationTimer.restart()
			}
			onExited:
			{
				id_rightArrowImage.source = "qrc:/icons/advertsArrowRight"
				id_animationTimer.stop()
			}
			onClicked:
			{
				id_bannerListView.m_PathView.incrementCurrentIndex()
			}
		}
		Timer
		{
			id: id_animationTimer
			interval: id_bannerListView.m_PathView.highlightMoveDuration
			running: false
			repeat: true
			onTriggered:
			{
				if ( id_rightArrowMouseArea.containsMouse )
				{
					id_bannerListView.m_PathView.incrementCurrentIndex()
				}
				if ( id_leftArrowMouseArea.containsMouse )
				{
					id_bannerListView.m_PathView.decrementCurrentIndex()
				}
			}
		}
	}
}
