import QtQuick 2.2
import CasinoCoinControls 1.0
import QtQuick.Controls 1.4

GUIExchangesListView
{
	id: id_ExchangesView

	property int m_iItemBorderWidth: 1
	property int m_iColumnWidth: 0
	property alias m_ListModel: id_listView.model
	property alias m_PathView: id_listView

    ScrollView
    {
        id: id_ExchangesScrollView
		anchors.fill: id_ExchangesView

        ListView
        {
            id: id_listView
            anchors.fill: id_ExchangesScrollView
            clip: true
            visible: true
            interactive: contentHeight > id_listView.height ? true : false

            model: id_ExchangesView.p_pListModel
            delegate: id_elementDelegate
        }
    }

	Component
	{
		id: id_elementDelegate
		Rectangle
		{
			id: id_listElement
			objectName: id_ExchangesView.objectName + "_Element" + index

			width: id_ExchangesView.width
			height: 125
            Row
			{
				id: id_row
				anchors.fill: id_listElement
				Rectangle
				{
					id: id_imageRectangle

					width: id_listElement.width / 5
                    height: 100
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
                            id_ExchangesView.onClicked( index )
						}
					}
				}
				Rectangle
				{
					id: id_otherInfoRectangle

					width: id_listElement.width - id_imageRectangle.width
                    height: 100
					anchors.verticalCenter: id_row.verticalCenter
					Column
					{
						id: id_otherInfoColumn
						anchors.fill: id_otherInfoRectangle
						Rectangle
						{
							id: id_exchangeNameRectangle
							width: id_otherInfoRectangle.width
                            height: id_otherInfoRectangle.height / 4
							Text
							{
								id: id_exchangeNameText
								anchors.fill: id_exchangeNameRectangle
								text: qsTr( m_exchangeName )
                                color: GUI20Skin.colorToolbarMainGradientEnd
                                font.bold: true
                                font.pointSize: 9
							}
						}
						Rectangle
						{
							id: id_pricesRectangle
							width: id_otherInfoRectangle.width
                            height: id_otherInfoRectangle.height / 4
							Row
							{
								id: id_pricesRow
								anchors.fill: id_pricesRectangle
								Rectangle
								{
									id: id_priceBid
									width: id_pricesRectangle.width / 4
									height: id_pricesRectangle.height
									Text
									{
										id: id_priceBidTextDescription
										anchors.left: id_priceBid.left
										text: qsTr("Bid:")
										width: id_priceBid.width / 3
										color: GUI20Skin.colorToolbarMainGradientEnd
									}
									Text
									{
										id: id_priceBidTextValue
										anchors.left: id_priceBidTextDescription.right
										text: qsTr( m_bidPrice )
                                        font.bold: true
										color: GUI20Skin.colorTextActive
									}
								}
								Rectangle
								{
									id: id_priceAsk
									width: id_pricesRectangle.width / 4
									height: id_pricesRectangle.height

									Text
									{
										id: id_priceAskTextDescription
										anchors.left: id_priceAsk.left
										text: qsTr("Ask:")
										color: GUI20Skin.colorToolbarMainGradientEnd
										width: id_priceAsk.width / 3
									}
									Text
									{
										id: id_priceAskTextValue
										anchors.left: id_priceAskTextDescription.right
										text: qsTr( m_askPrice )
                                        font.bold: true
										color: GUI20Skin.colorTextActive
									}
								}
								Rectangle
								{
									id: id_volume24h
									width: id_pricesRectangle.width / 2
									height: id_pricesRectangle.height
									Text
									{
										id: id_volume24hTextDescription
										anchors.left: id_volume24h.left
										text: qsTr("24h Volume:")
										color: GUI20Skin.colorToolbarMainGradientEnd
										width: id_volume24h.width / 3
									}
									Text
									{
										id: id_volume24hTextValue
										anchors.left: id_volume24hTextDescription.right
										text: qsTr( m_volume24H )
                                        font.bold: true
										color: GUI20Skin.colorTextActive
									}
								}
							}
						}
						Rectangle
						{
							id: id_volumeTimeRectangle
							width: id_otherInfoRectangle.width
							height: id_otherInfoRectangle.height / 4
							Row
							{
								id: id_volumeTimeRow
								anchors.fill: id_volumeTimeRectangle
								Rectangle
								{
									id: id_priceLast
									width: id_pricesRectangle.width / 4
									height: id_pricesRectangle.height
									Text
									{
										id: id_priceLastTextDescription
										anchors.left: id_priceLast.left
										text: qsTr("Last:")
										color: GUI20Skin.colorToolbarMainGradientEnd
										width: id_priceLast.width / 3
									}
									Text
									{
										id: id_priceLastTextValue
										anchors.left: id_priceLastTextDescription.right
										text: qsTr( m_lastPrice )
                                        font.bold: true
										color: GUI20Skin.colorTextActive
									}
								}
								Rectangle
								{
									id: id_exchangeLastUpdateTime
									width: id_volumeTimeRectangle.width / 4
									height: id_volumeTimeRectangle.height
									Text
									{
										id: id_exchangeTimeDescription
										anchors.left: id_exchangeLastUpdateTime.left
										text: qsTr( "Time:" )
										color: GUI20Skin.colorToolbarMainGradientEnd
										width: id_exchangeLastUpdateTime.width / 3
									}
									Text
									{
										id: id_exchangeTimeValue
										anchors.left: id_exchangeTimeDescription.right
										text: qsTr( m_lastUpdateTime )
                                        font.bold: true
										color: GUI20Skin.colorTextActive
									}
								}
							}
						}

                        Rectangle
                        {
                            id: id_exchangeLink
                            width: id_otherInfoRectangle.width
                            height: id_otherInfoRectangle.height / 4
                            Text
                            {
                                id: id_exchangeLinkText
                                anchors.fill: id_exchangeLink
                                text: qsTr( "Trade Casinocoin at %1" ).arg(m_exchangeName)
                                font.underline: true
                                color: GUI20Skin.colorTextBlack
								MouseArea
								{
									id: id_linkMouseArea
									anchors.fill: id_exchangeLinkText
									hoverEnabled: true
									onClicked:
									{
										id_ExchangesView.onClicked( index )
									}
									onEntered:
									{
										id_exchangeLinkText.color = GUI20Skin.colorTextActive
									}
									onExited:
									{
										id_exchangeLinkText.color = GUI20Skin.colorToolbarMainGradientEnd
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
