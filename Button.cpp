#include "Button.hpp"

Button::Button(const sf::String& name, ButtonAction::ID action, const sf::Texture& texture, const sf::Font& font)
	: Art{ texture }
	, mText{ name, font, 30 }
	, mAction{ action }
	, mCurrentState{ ButtonState::NORMAL }
{
	/// FONT SETTINGS ///
	mText.setStyle(sf::Text::Regular);
	mText.setColor(sf::Color(124, 74, 31, 255));		// Default Color of the font (Brown).


	/// SPRITE SETTINGS ///
	getSprite().setTextureRect( sf::IntRect(0, 0, 829, 190));
}

void Button::render(sf::RenderWindow& window)
{
	window.draw(getSprite());
	window.draw(mText);
}

void Button::update(const sf::Time& dt)
{
	/// POSITION RELATIVE TO THE SPRITE ///
	mText.setPosition(getSprite().getPosition().x + (getSprite().getLocalBounds().width * getSprite().getScale().x / 2.f) - (mText.getLocalBounds().width / 2.f),
						getSprite().getPosition().y + (getSprite().getLocalBounds().height * getSprite().getScale().y / 2.f) - (mText.getLocalBounds().height / 2.f));
}