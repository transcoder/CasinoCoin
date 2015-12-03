#include <QtWidgets>

#include "cscfusionstyle.h"
#include "gui20_skin.h"

CSCFusionStyle::CSCFusionStyle() :
	QProxyStyle(QStyleFactory::create("fusion"))
{
}

void CSCFusionStyle::polish(QPalette &palette)
{
	GUI20Skin& skin = GUI20Skin::Instance();
	QLinearGradient buttonGradient;
	buttonGradient.setColorAt( 0, skin.GetColorButtonTopGradient() );
	buttonGradient.setColorAt( 1, skin.GetColorButtonBottomGradient() );

	QLinearGradient toolTipGradient;
	toolTipGradient.setColorAt( 0, skin.GetColorToolbarMainGradientBegin() );
	toolTipGradient.setColorAt( 1, skin.GetColorToolbarMainGradientEnd() );

	palette = QPalette();


	palette.setBrush( QPalette::Active,			QPalette::Text,				skin.GetColorTextActive() );
	palette.setBrush( QPalette::Active,			QPalette::BrightText,		skin.GetColorTextActiveAutocomplete() );
	palette.setBrush( QPalette::Active,			QPalette::Base,				skin.GetColorFrameBackground() );
	palette.setBrush( QPalette::Active,			QPalette::AlternateBase,	skin.GetColorListValueAlternative() );
	palette.setBrush( QPalette::Active,			QPalette::Highlight,		skin.GetColorListCurrent() );
	palette.setBrush( QPalette::Active,			QPalette::HighlightedText,	skin.GetColorTextActive() );
	palette.setBrush( QPalette::Active,			QPalette::Button,			skin.GetColorButtonBottomGradient() );
	palette.setBrush( QPalette::Active,			QPalette::ButtonText,		skin.GetColorTextActive() );
	palette.setBrush( QPalette::Active,			QPalette::Mid,				skin.GetColorButtonMid() );
	palette.setBrush( QPalette::Active,			QPalette::Dark,				skin.GetColorButtonDark() );
	palette.setBrush( QPalette::Active,			QPalette::Light,			skin.GetColorButtonLight() );
	palette.setBrush( QPalette::Active,			QPalette::Window,			skin.GetColorWindowBackground() );

	palette.setBrush( QPalette::Inactive,		QPalette::Text,				skin.GetColorTextDisabled() );
	palette.setBrush( QPalette::Inactive,		QPalette::BrightText,		skin.GetColorTextDisabledAutocomplete() );
	palette.setBrush( QPalette::Inactive,		QPalette::Base,				skin.GetColorFrameBackground() );
	palette.setBrush( QPalette::Inactive,		QPalette::AlternateBase,	skin.GetColorListValueAlternative() );
	palette.setBrush( QPalette::Inactive,		QPalette::Highlight,		skin.GetColorListCurrent() );
	palette.setBrush( QPalette::Inactive,		QPalette::HighlightedText,	skin.GetColorTextDisabled() );
	palette.setBrush( QPalette::Inactive,		QPalette::Button,			skin.GetColorButtonBottomGradient() );
	palette.setBrush( QPalette::Inactive,		QPalette::ButtonText,		skin.GetColorTextDisabled() );
	palette.setBrush( QPalette::Inactive,		QPalette::Mid,				skin.GetColorButtonMid() );
	palette.setBrush( QPalette::Inactive,		QPalette::Dark,				skin.GetColorButtonDark() );
	palette.setBrush( QPalette::Inactive,		QPalette::Light,			skin.GetColorButtonLight() );
	palette.setBrush( QPalette::Inactive,		QPalette::Window,			skin.GetColorWindowBackground() );
	palette.setBrush( QPalette::Inactive,		QPalette::ToolTipBase,		toolTipGradient );
	palette.setBrush( QPalette::Inactive,		QPalette::ToolTipText,		skin.GetColorToolbarMainTextCurrent() );

	palette.setBrush( QPalette::Disabled,		QPalette::Text,				skin.GetColorTextDisabled() );
	palette.setBrush( QPalette::Disabled,		QPalette::BrightText,		skin.GetColorTextDisabledAutocomplete() );
	palette.setBrush( QPalette::Disabled,		QPalette::Base,				skin.GetColorFrameBackground() );
	palette.setBrush( QPalette::Disabled,		QPalette::AlternateBase,	skin.GetColorListValueAlternative() );
	palette.setBrush( QPalette::Disabled,		QPalette::Highlight,		skin.GetColorListCurrent() );
	palette.setBrush( QPalette::Disabled,		QPalette::HighlightedText,	skin.GetColorTextDisabled() );
	palette.setBrush( QPalette::Disabled,		QPalette::Button,			skin.GetColorButtonBottomGradient() );
	palette.setBrush( QPalette::Disabled,		QPalette::ButtonText,		skin.GetColorTextDisabled() );
	palette.setBrush( QPalette::Disabled,		QPalette::Mid,				skin.GetColorButtonMid() );
	palette.setBrush( QPalette::Disabled,		QPalette::Dark,				skin.GetColorButtonDark() );
	palette.setBrush( QPalette::Disabled,		QPalette::Light,			skin.GetColorButtonLight() );
	palette.setBrush( QPalette::Disabled,		QPalette::Window,			skin.GetColorWindowBackground() );

}

void CSCFusionStyle::polish(QWidget *widget)
{
	if	(	qobject_cast<QPushButton *>(widget)
		||	qobject_cast<QComboBox *>(widget)
		)
	{
		widget->setAttribute(Qt::WA_Hover, true);
	}
}

void CSCFusionStyle::unpolish(QWidget *widget)
{
	if	(	qobject_cast<QPushButton *>(widget)
		||	qobject_cast<QComboBox *>(widget)
		)
	{
		widget->setAttribute(Qt::WA_Hover, false);
	}
}

int CSCFusionStyle::pixelMetric(PixelMetric metric,
									const QStyleOption *option,
									const QWidget *widget) const
{
	switch (metric)
	{
		case PM_DefaultFrameWidth:
		case PM_ComboBoxFrameWidth:
		case PM_SpinBoxFrameWidth:
		case PM_CheckBoxLabelSpacing:
		case PM_HeaderMargin:
		{
			return 8;
		}
		case PM_IndicatorHeight:
		case PM_IndicatorWidth:
		case PM_ExclusiveIndicatorWidth:
		case PM_ExclusiveIndicatorHeight:
		{
			return 18;
		}
		case PM_ScrollBarExtent:
		{
			return QProxyStyle::pixelMetric(metric, option, widget) + 4;
		}
		case PM_ToolTipLabelFrameWidth:
		{
			return 6;
		}
		default:
		{
			return QProxyStyle::pixelMetric(metric, option, widget);
		}
	}
}

int CSCFusionStyle::styleHint(StyleHint hint, const QStyleOption *option,
								  const QWidget *widget,
								  QStyleHintReturn *returnData) const
{
	switch (hint)
	{
		case SH_DitherDisabledText:
		{
			return int(false);
		}
		case SH_EtchDisabledText:
		{
			return int(true);
		}
		default:
		{
			return QProxyStyle::styleHint(hint, option, widget, returnData);
		}
	}
}

void CSCFusionStyle::drawPrimitive(PrimitiveElement element,
									   const QStyleOption *option,
									   QPainter *painter,
									   const QWidget *widget) const
{
	GUI20Skin& skin = GUI20Skin::Instance();

	switch (element)
	{
		case PE_FrameDefaultButton:
		{
			return;
		}
		case PE_FrameFocusRect:
		{
			return;
		}
		case PE_PanelItemViewRow:
		{
			QPainterPath roundRect = roundRectPath(option->rect, 0);

			QBrush brush = option->palette.base();
			painter->save();
			painter->setRenderHint(QPainter::Antialiasing, true);
			painter->fillPath(roundRect, brush);
			painter->restore();
			break;
		}
//		case PE_IndicatorArrowDown:
//		case PE_IndicatorArrowUp:
//		case PE_IndicatorArrowLeft:
//		case PE_IndicatorArrowRight:
//		{
//			int x, y, width, height;
//			option->rect.getRect(&x, &y, &width, &height);
//			painter->save();
//			painter->setRenderHint(QPainter::Antialiasing, true);
//			QImage imgArrow;
//			QString strPath = ":/icons/advertsArrow";
//			if ( element == PE_IndicatorArrowDown || PE_IndicatorSpinDown || PE_IndicatorSpinMinus )
//			{
//				strPath.append( "Down" );
//			}
//			else if ( element == PE_IndicatorArrowLeft )
//			{
//				strPath.append( "Left" );
//			}
//			else if ( element == PE_IndicatorArrowUp || PE_IndicatorSpinUp || PE_IndicatorSpinPlus )
//			{
//				strPath.append( "Up" );
//			}
//			else if ( element == PE_IndicatorArrowRight )
//			{
//				strPath.append( "Right" );
//			}

//			if ( option->state & QStyle::State_MouseOver )
//			{
//				strPath.append( "Hover" );
//			}
//			qDebug() << "gonna draw: " << strPath;
//			imgArrow.load( strPath );
//			int iTopLeftX = x + ( ( ( width - imgArrow.width() ) / 2 ) );
//			int iTopLeftY = y + ( ( ( height - imgArrow.height() ) / 2 ) );
//			painter->drawImage( QPoint( iTopLeftX, iTopLeftY), imgArrow );
//			painter->restore();
//			break;
//		}
		case PE_FrameGroupBox:
		case PE_FrameWindow:
		case PE_Frame:
		{
			int x, y, width, height;
			option->rect.getRect(&x, &y, &width, &height);

			QPainterPath roundRect = roundRectPath(option->rect, 5);

			QBrush brush = option->palette.base();
			painter->save();
			painter->setRenderHint(QPainter::Antialiasing, true);
			painter->fillPath(roundRect, brush);
			painter->restore();
			break;
		}
		case PE_IndicatorRadioButton:
		{
			int x, y, width, height;
			option->rect.getRect(&x, &y, &width, &height);

			QPainterPath roundRect = roundRectPath( QRect( x + 1, y + 1, width - 1, height - 1 ), ( width -1 ) / 2);
			QPen pen( skin.GetColorToolbarMainGradientBegin(), 2 );
			painter->save();
			painter->setPen( pen );
			painter->setRenderHint(QPainter::Antialiasing, true);
			painter->drawPath( roundRect );
			if ( option->state & QStyle::State_Off )
			{
			}
			else if ( option->state & QStyle::State_On )
			{
				QImage checkboxTick( ":/icons/radiobuttonTick" );
				checkboxTick = checkboxTick.scaled( 10, 10 );
				int iTopLeftX = x + ( ( ( width - checkboxTick.width() ) / 2 ) );
				int iTopLeftY = y + ( ( ( height - checkboxTick.height() ) / 2 ) );
				painter->drawImage( QPoint( iTopLeftX, iTopLeftY ), checkboxTick );
			}
			painter->restore();
			break;
		}
		case PE_IndicatorCheckBox:
		{
			int x, y, width, height;
			option->rect.getRect(&x, &y, &width, &height);

			QPainterPath roundRect = roundRectPath( QRect( x + 1, y + 1, width - 1, height - 1 ), 2 );
			QPen pen( skin.GetColorToolbarMainGradientBegin(), 2 );
			painter->save();
			painter->setPen( pen );
			painter->setRenderHint(QPainter::Antialiasing, true);
			painter->drawPath( roundRect );
			if ( option->state & QStyle::State_Off )
			{
			}
			else if ( option->state & QStyle::State_On )
			{
				QImage checkboxTick( ":/icons/checkboxTick" );
				int iTopLeftX = x + ( ( ( width - checkboxTick.width() ) / 2 ) );
				int iTopLeftY = y + ( ( ( height - checkboxTick.height() ) / 2 ) );
				painter->drawImage( QPoint( iTopLeftX, iTopLeftY ), checkboxTick );
			}
			painter->restore();
			break;
		}
		case PE_PanelButtonCommand:
		{
			GUI20Skin& skin = GUI20Skin::Instance();
			int delta = (option->state & State_MouseOver) ? 64 : 0;
			QColor semiTransparentWhite = skin.GetColorButtonLight();
			semiTransparentWhite.setAlpha(127 + delta);
			QColor semiTransparentBlack = skin.GetColorButtonDark();
			semiTransparentBlack.setAlpha(127 - delta);

			int x, y, width, height;
			option->rect.getRect(&x, &y, &width, &height);

			int radius = 5;
			QPainterPath roundRect = roundRectPath( QRect( x + 1, y + 1, width - 1, height - 1 ), radius );

			QBrush brush;

			if (option->state & (State_Sunken | State_On))
			{
				brush = option->palette.mid();
			}
			else
			{
				brush = option->palette.button();
			}

			painter->save();
			painter->setRenderHint(QPainter::Antialiasing, true);
			painter->fillPath(roundRect, brush);

			int penWidth;
			if (radius < 10)
			{
				penWidth = 3;
			}
			else if (radius < 20)
			{
				penWidth = 5;
			}
			else
			{
				penWidth = 7;
			}

			QPen topPen(semiTransparentWhite, penWidth);
			QPen bottomPen(semiTransparentBlack, penWidth);

			if (option->state & (State_Sunken | State_On))
			{
				qSwap(topPen, bottomPen);
			}

			int x1 = x;
			int x2 = x + radius;
			int x3 = x + width - radius;
			int x4 = x + width;

			if (option->direction == Qt::RightToLeft)
			{
				qSwap(x1, x4);
				qSwap(x2, x3);
			}

			QPolygon topHalf;
			topHalf << QPoint(x1, y)
					<< QPoint(x4, y)
					<< QPoint(x3, y + radius)
					<< QPoint(x2, y + height - radius)
					<< QPoint(x1, y + height);

			painter->setClipPath(roundRect);
			painter->setClipRegion(topHalf, Qt::IntersectClip);
			painter->setPen(topPen);
			painter->drawPath(roundRect);

			QPolygon bottomHalf = topHalf;
			bottomHalf[0] = QPoint(x4, y + height);

			painter->setClipPath(roundRect);
			painter->setClipRegion(bottomHalf, Qt::IntersectClip);
			painter->setPen(bottomPen);
			painter->drawPath(roundRect);

			painter->setPen(option->palette.foreground().color());
			painter->setClipping(false);
			painter->drawPath(roundRect);

			painter->restore();
			break;
		}
		default:
		{
			QProxyStyle::drawPrimitive(element, option, painter, widget);
		}
	}
}

void CSCFusionStyle::drawControl(ControlElement element,
									 const QStyleOption *option,
									 QPainter *painter,
									 const QWidget *widget) const
{
	switch (element)
	{
		case CE_PushButtonLabel:
		{
			QStyleOptionButton myButtonOption;
			const QStyleOptionButton *buttonOption =
					qstyleoption_cast<const QStyleOptionButton *>(option);
			if (buttonOption)
			{
				myButtonOption = *buttonOption;
				if (myButtonOption.palette.currentColorGroup() != QPalette::Disabled)
				{
					if (myButtonOption.state & (State_Sunken | State_On))
					{
						myButtonOption.palette.setBrush(QPalette::ButtonText,
								myButtonOption.palette.brightText());
					}
				}
			}
			QProxyStyle::drawControl(element, &myButtonOption, painter, widget);
			break;
		}
		default:
		{
			QProxyStyle::drawControl(element, option, painter, widget);
			break;
		}
	}
}

QPainterPath CSCFusionStyle::roundRectPath(const QRect &rect, int radius)
{
	int diam = 2 * radius;

	int x1, y1, x2, y2;
	rect.getCoords(&x1, &y1, &x2, &y2);

	QPainterPath path;
	path.moveTo(x2, y1 + radius);
	path.arcTo(QRect(x2 - diam, y1, diam, diam), 0.0, +90.0);
	path.lineTo(x1 + radius, y1);
	path.arcTo(QRect(x1, y1, diam, diam), 90.0, +90.0);
	path.lineTo(x1, y2 - radius);
	path.arcTo(QRect(x1, y2 - diam, diam, diam), 180.0, +90.0);
	path.lineTo(x1 + radius, y2);
	path.arcTo(QRect(x2 - diam, y2 - diam, diam, diam), 270.0, +90.0);
	path.closeSubpath();
	return path;
}

