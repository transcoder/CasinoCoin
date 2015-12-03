#include "gui20_skin.h"


GUI20Skin::GUI20Skin( QObject* a_pParent )
	: QObject( a_pParent )
	, colorToolbarMainGradientBegin( "#9c181c" )
//	, colorToolbarMainGradientEnd( "#ae1e22" )
    , colorToolbarMainGradientEnd( "#a61b22" )
	, colorToolbarMainCurrent( "#761316" )
	, colorToolbarMainBottomCurrent( "#e1252b" )
	, colorToolbarMainTextCurrent( "#ffffff" )
	, colorToolbarMainTextNormal( "#3f0a0c" )
	, colorToolbarMainTextWebsiteURL( colorToolbarMainTextCurrent )
	, colorToolbarMainTextVisitWebsite( "#ffffaf" )
	, colorToolbarMainTextShadow( "#c72427" )
	, colorWindowBackground( "#f0f0f0" )
	, colorFrameBackground( "#ffffff" )
	, colorButtonTopGradient( colorFrameBackground )
	, colorButtonBottomGradient( "#F2F2F2" )
	, colorButtonMid( "#F8F8F8" )
	, colorButtonDark( colorButtonBottomGradient )
	, colorButtonLight( colorFrameBackground )
	, colorListCurrent( "#F5E5E5" )
	, colorListValue( colorFrameBackground )
	, colorListValueAlternative( "#F5F5F5" )
	, colorTextActive( "#404040" )
	, colorTextActiveAutocomplete( "#6B3D3D" )
	, colorTextDisabled( "#707070" )
	, colorTextDisabledAutocomplete( "#8B5D5D" )
    , colorTextBlack("#000000")
{
}

GUI20Skin& GUI20Skin::Instance()
{
	static GUI20Skin	m_oInstance;
	return m_oInstance;
}

GUI20Skin::~GUI20Skin()
{

}

