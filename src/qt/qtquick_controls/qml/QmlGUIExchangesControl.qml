import QtQuick 2.2
import CasinoCoinControls 1.0

GUIExchangesControl
{
	id: id_ExchangesControl

	property color colorBackgroundInWidget: GUI20Skin.colorFrameBackground
	Rectangle
	{
		id: id_ExchangessArea
		height: id_ExchangesControl.height
		width: id_ExchangesControl.width
		color: colorBackgroundInWidget
		z: -1

		anchors.fill: id_ExchangesControl
//		anchors.horizontalCenter: id_ExchangesControl.horizontalCenter
//		anchors.left: id_leftArrow.left
	QmlGUIExchangesListView
	{
		id: id_ExchangesListView

		anchors.fill: id_ExchangessArea
		Component.onCompleted:
		{
			id_ExchangesControl.InitializeExchangesView( id_ExchangesListView )
		}
	}
}

}
