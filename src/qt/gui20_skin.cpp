#include "gui20_skin.h"


GUI20Skin::GUI20Skin( QObject* a_pParent )
	: QObject( a_pParent )
	, colorToolbarMainGradientBegin( "#9c181c" )
	, colorToolbarMainGradientEnd( "#ae1e22" )
	, colorToolbarMainCurrent( "#761316" )
	, colorToolbarMainBottomCurrent( "#e1252b" )
	, colorToolbarMainTextCurrent( "#ffffff" )
	, colorToolbarMainTextNormal( "#3f0a0c" )
	, colorToolbarMainTextShadow( "#c72427" )
	, colorMainWindowBackground( "#afafaf" )
	, colorMainWindowFrameBackground( "#ffffff" )
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

