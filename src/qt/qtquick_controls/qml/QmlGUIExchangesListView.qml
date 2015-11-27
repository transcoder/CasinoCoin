import QtQuick 2.0
import CasinoCoinControls 1.0

GUIExchangesListView
{
	id: id_ExchangesView

	property int m_iItemBorderWidth: 1
	property int m_iColumnWidth: 0
	property alias m_ListModel: id_listView.model
	property alias m_PathView: id_listView

	ListView
	{
		id: id_listView
		anchors.fill: id_ExchangesView

		clip: true
		visible: true
		interactive: contentHeight > id_listView.height ? true : false

		model: id_ExchangesView.p_pListModel
		delegate: id_elementDelegate
	}

	Component
	{
		id: id_elementDelegate
		Rectangle
		{
			id: id_listElement
			objectName: id_ExchangesView.objectName + "_Element" + index

			width: 400
			height: 100
			Row
			{
				id: id_row
				anchors.fill: id_listElement
				Rectangle
				{
					id: id_imageRectangle

					width: id_listElement.width / 3
					height: 80
					anchors.verticalCenter: id_row.verticalCenter
					Image
					{
						id: id_exchangeImage
						source: "image://exchangesImages/" + m_imageSource
						scale: ( id_imageRectangle.height / height )
						anchors.centerIn: id_imageRectangle
					}

					MouseArea
					{
						id: id_leftItemMouseArea
						anchors.fill: id_imageRectangle
						onClicked:
						{
							id_ExchangesView.OnClicked( index )
						}
					}
				}
				Rectangle
				{
					id: id_otherInfoRectangle

					width: id_listElement.width - id_imageRectangle.width
					height: 90
					anchors.verticalCenter: id_row.verticalCenter
					Column
					{
						id: id_otherInfoColumn
						anchors.fill: id_otherInfoRectangle
						Rectangle
						{
							id: id_exchangeNameRectangle
							width: id_otherInfoRectangle.width
							height: id_otherInfoRectangle.height / 3
							Text
							{
								id: id_exchangeNameText
								anchors.fill: id_exchangeNameRectangle
								text: qsTr( m_exchangeName )
							}
						}
						Rectangle
						{
							id: id_pricesRectangle
							width: id_otherInfoRectangle.width
							height: id_otherInfoRectangle.height / 3
							Row
							{
								id: id_pricesRow
								anchors.fill: id_pricesRectangle
								Rectangle
								{
									id: id_priceBid
									width: id_pricesRectangle.width / 3
									height: id_pricesRectangle.height
									Text
									{
										id: id_priceBidText
										anchors.fill: id_priceBid
										text: qsTr( m_bidPrice )
									}
								}
								Rectangle
								{
									id: id_priceAsk
									width: id_pricesRectangle.width / 3
									height: id_pricesRectangle.height
									Text
									{
										id: id_priceAskText
										anchors.fill: id_priceAsk
										text: qsTr( m_askPrice )
									}
								}
								Rectangle
								{
									id: id_priceLast
									width: id_pricesRectangle.width / 3
									height: id_pricesRectangle.height
									Text
									{
										id: id_priceLastText
										anchors.fill: id_priceLast
										text: qsTr( m_lastPrice )
									}
								}
							}
						}
						Rectangle
						{
							id: id_exchangeLink
							width: id_otherInfoRectangle.width
							height: id_otherInfoRectangle.height / 3
							Text
							{
								id: id_exchangeLinkText
								anchors.fill: id_exchangeLink
								text: qsTr( "Go to site" )
								MouseArea
								{
									id: id_linkMouseArea
									anchors.fill: id_exchangeLinkText
									onClicked:
									{
										id_ExchangesView.OnClicked( index )
									}
								}
							}
						}
					}
				}
			}
		}


	}

}
