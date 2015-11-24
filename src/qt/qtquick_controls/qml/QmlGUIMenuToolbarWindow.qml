import QtQuick 2.0

Rectangle
{
	id: id_toolbarRoot
	width: parent ? parent.width : 0
	height: parent ? parent.height : 0
	color: GUI20Skin.colorWindowBackground
	QmlGUIMenuToolbarControl
	{
		id: id_toolbarControlMain
		anchors.fill: id_toolbarRoot
	}
}
