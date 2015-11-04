import QtQuick 2.0

Rectangle
{
	id: id_toolbarRoot
	width: 1280
	height: 77 + 5
	color: "transparent"
	QmlGUIMenuToolbarControl
	{
		id: id_toolbarControlMain
		anchors.fill: id_toolbarRoot
	}
}
