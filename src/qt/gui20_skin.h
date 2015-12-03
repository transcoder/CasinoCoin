#ifndef GUI20_SKIN_H
#define GUI20_SKIN_H

#include <QColor>
#include <QString>

#include <QMutex>
#include <QObject>

class GUI20Skin : public QObject
{
	Q_OBJECT

	Q_PROPERTY( QColor colorToolbarMainGradientBegin		READ GetColorToolbarMainGradientBegin			CONSTANT )
	Q_PROPERTY( QColor colorToolbarMainGradientEnd			READ GetColorToolbarMainGradientEnd				CONSTANT )
	Q_PROPERTY( QColor colorToolbarMainCurrent				READ GetColorToolbarMainCurrent					CONSTANT )

	Q_PROPERTY( QColor colorToolbarMainBottomCurrent		READ GetColorToolbarBottomCurrent				CONSTANT )

	Q_PROPERTY( QColor colorToolbarMainTextCurrent			READ GetColorToolbarMainTextCurrent				CONSTANT )
	Q_PROPERTY( QColor colorToolbarMainTextNormal			READ GetColorToolbarMainTextNormal				CONSTANT )
	Q_PROPERTY( QColor colorToolbarMainTextShadow			READ GetColorToolbarMainTextShadow				CONSTANT )
	Q_PROPERTY( QColor colorToolbarMainTextWebsiteURL		READ GetColorToolbarMainTextWebsiteURL			CONSTANT )
	Q_PROPERTY( QColor colorToolbarMainTextVisitWebsite		READ GetColorToolbarMainTextVisitWebsite		CONSTANT )

	Q_PROPERTY( QColor colorWindowBackground				READ GetColorWindowBackground					CONSTANT )
	Q_PROPERTY( QColor colorFrameBackground					READ GetColorFrameBackground					CONSTANT )

	Q_PROPERTY( QColor colorButtonTopGradient				READ GetColorButtonTopGradient					CONSTANT )
	Q_PROPERTY( QColor colorButtonBottomGradient			READ GetColorButtonBottomGradient				CONSTANT )
	Q_PROPERTY( QColor colorButtonMid						READ GetColorButtonMid							CONSTANT )
	Q_PROPERTY( QColor colorButtonDark						READ GetColorButtonDark							CONSTANT )
	Q_PROPERTY( QColor colorButtonLight						READ GetColorButtonLight						CONSTANT )

	Q_PROPERTY( QColor colorListCurrent						READ GetColorListCurrent						CONSTANT )
	Q_PROPERTY( QColor colorListValue						READ GetColorListValue							CONSTANT )
	Q_PROPERTY( QColor colorListValueAlternative			READ GetColorListValueAlternative				CONSTANT )

	Q_PROPERTY( QColor colorTextActive						READ GetColorTextActive							CONSTANT )
	Q_PROPERTY( QColor colorTextActiveAutocomplete			READ GetColorTextActiveAutocomplete				CONSTANT )
	Q_PROPERTY( QColor colorTextDisabled					READ GetColorTextDisabled						CONSTANT )
	Q_PROPERTY( QColor colorTextDisabledAutocomplete		READ GetColorTextDisabledAutocomplete			CONSTANT )

	Q_ENUMS( ESizeConstants )

public:

	enum ESizeConstants
	{
		ToolbarMainHeight								= 77,
		ToolbarMainBottomPartHeight						= 5
	};

	const QColor GetColorToolbarMainGradientBegin() const		{return colorToolbarMainGradientBegin;}
	const QColor GetColorToolbarMainGradientEnd() const			{return colorToolbarMainGradientEnd;}
	const QColor GetColorToolbarMainCurrent() const				{return colorToolbarMainCurrent;}

	const QColor GetColorToolbarBottomCurrent() const			{return colorToolbarMainBottomCurrent;}

	const QColor GetColorToolbarMainTextCurrent() const			{return colorToolbarMainTextCurrent;}
	const QColor GetColorToolbarMainTextNormal() const			{return colorToolbarMainTextNormal;}
	const QColor GetColorToolbarMainTextShadow() const			{return colorToolbarMainTextShadow;}
	const QColor GetColorToolbarMainTextWebsiteURL() const		{return colorToolbarMainTextWebsiteURL;}
	const QColor GetColorToolbarMainTextVisitWebsite() const	{return colorToolbarMainTextVisitWebsite;}

	const QColor GetColorWindowBackground() const				{return colorWindowBackground;}
	const QColor GetColorFrameBackground() const				{return colorFrameBackground;}

	const QColor GetColorButtonTopGradient() const				{return colorButtonTopGradient;}
	const QColor GetColorButtonBottomGradient() const			{return colorButtonBottomGradient;}
	const QColor GetColorButtonMid() const						{return colorButtonMid;}
	const QColor GetColorButtonDark() const						{return colorButtonDark;}
	const QColor GetColorButtonLight() const					{return colorButtonLight;}

	const QColor GetColorListCurrent() const					{return colorListCurrent;}
	const QColor GetColorListValue() const						{return colorListValue;}
	const QColor GetColorListValueAlternative() const			{return colorListValueAlternative;}

	const QColor GetColorTextActive() const						{return colorTextActive;}
	const QColor GetColorTextActiveAutocomplete() const			{return colorTextActiveAutocomplete;}
	const QColor GetColorTextDisabled() const					{return colorTextDisabled;}
	const QColor GetColorTextDisabledAutocomplete() const		{return colorTextDisabledAutocomplete;}

private:
	const QColor colorToolbarMainGradientBegin;
	const QColor colorToolbarMainGradientEnd;
	const QColor colorToolbarMainCurrent;

	const QColor colorToolbarMainBottomCurrent;

	const QColor colorToolbarMainTextCurrent;
	const QColor colorToolbarMainTextNormal;
	const QColor colorToolbarMainTextShadow;
	const QColor colorToolbarMainTextWebsiteURL;
	const QColor colorToolbarMainTextVisitWebsite;

	const QColor colorWindowBackground;
	const QColor colorFrameBackground;

	const QColor colorButtonTopGradient;
	const QColor colorButtonBottomGradient;
	const QColor colorButtonMid;
	const QColor colorButtonDark;
	const QColor colorButtonLight;

	const QColor colorListCurrent;
	const QColor colorListValue;
	const QColor colorListValueAlternative;

	const QColor colorTextActive;
	const QColor colorTextActiveAutocomplete;
	const QColor colorTextDisabled;
	const QColor colorTextDisabledAutocomplete;

    const QColor colorTextBlack;

public:
	static GUI20Skin& Instance();
private:
	GUI20Skin( QObject* a_pParent = 0 );
	virtual ~GUI20Skin();

};
#endif // GUI20_SKIN_H


