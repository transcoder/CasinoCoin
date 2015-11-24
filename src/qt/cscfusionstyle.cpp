/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**	 notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**	 notice, this list of conditions and the following disclaimer in
**	 the documentation and/or other materials provided with the
**	 distribution.
**   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names
**	 of its contributors may be used to endorse or promote products derived
**	 from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

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
		{
			return 8;
		}
		case PM_ComboBoxFrameWidth:
		{
			return 8;
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
		case SH_ComboBox_Popup:
		{
			qDebug() << "yep, there are some comboboxes!";
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
			int x, y, width, height;
			option->rect.getRect(&x, &y, &width, &height);

			QPainterPath roundRect = roundRectPath(option->rect, 0);

			QBrush brush = option->palette.base();
			painter->save();
			painter->setRenderHint(QPainter::Antialiasing, true);
			painter->fillPath(roundRect, brush);
			painter->restore();
			break;
		}
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
		case PE_PanelButtonTool:
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

			QPainterPath roundRect = roundRectPath(option->rect, 5 );

			int radius = 5;

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
//! [40]

