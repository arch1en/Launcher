#pragma once

#include "Art.hpp"

namespace ButtonAction
{
	enum ID
	{
		PLAY,
		OPTIONS,
		MINIMIZE,
		QUIT
	};
}

namespace ButtonState
{
	enum ID
	{
		NORMAL,
		HOVERED,
		PUSHED
	};
}

class Button : public Art
{
////////////////////////////////////
/// \brief - Button - A class that creates a button object
/// \param const sf::String& - name of the button
/// \param Action - enum describing an action that button should perform.
/// \param const sf::Texture& - constant reference to a texture spritesheet. It then needs to be cut into parts.
/// \param const sf::Font& - constant reference to a font.
////////////////////////////////////
public:
	Button(const sf::String&, ButtonAction::ID, const sf::Texture&, const sf::Font&);
	void render(sf::RenderWindow&);
	void update(const sf::Time&);

private:
	sf::Text				mText;
	ButtonAction::ID		mAction;
	ButtonState::ID			mCurrentState;

};