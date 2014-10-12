#include "Logo.hpp"

Logo::Logo(const sf::Texture& texture)
	: Art{texture}
{
	getSprite().setPosition((1024.f / 2.f) - (getSprite().getLocalBounds().width / 2), 640.f / 15.f);
}

void Logo::render(sf::RenderWindow& window)
{
	window.draw(getSprite());
}