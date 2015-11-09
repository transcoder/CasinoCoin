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

	const QColor colorMainWindowBackground;
	const QColor colorMainWindowFrameBackground;

public:
	static GUI20Skin& Instance();
private:
	GUI20Skin( QObject* a_pParent = 0 );
	virtual ~GUI20Skin();

};
#endif // GUI20_SKIN_H


