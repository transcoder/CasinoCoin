import QtQuick 2.0

Rectangle
{
	id: id_toolbarRoot
	width: parent.width
	height: parent.height
	color: "transparent"
	QmlGUIMenuToolbarControl
	{
		id: id_toolbarControlMain
		anchors.fill: id_toolbarRoot
	}
}
