import QtQuick 2.2

Rectangle
{
	id: id_ExchangesRoot
	width: parent ? parent.width : 0
	height: parent ? parent.height : 0
	color: GUI20Skin.colorFrameBackground

    QmlGUIExchangesControl
    {
        id: id_ExchangesControlMain
		anchors.fill: id_ExchangesRoot
	}
}

