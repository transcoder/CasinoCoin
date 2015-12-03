import QtQuick 2.2
import CasinoCoinControls 1.0

GUIExchangesControl
{
	id: id_ExchangesControl

	property color colorBackgroundInWidget: GUI20Skin.colorFrameBackground
	QmlGUIExchangesListView
	{
		id: id_ExchangesListView

		anchors.fill: id_ExchangesControl
		Component.onCompleted:
		{
			id_ExchangesControl.initializeExchangesView( id_ExchangesListView )
		}
	}

}
