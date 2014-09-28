#include "Background.hpp"

Background::Background(const sf::Texture& texture)
	: Art(texture)
{

}

void Background::render(sf::RenderWindow& window)
{
	window.draw(getSprite());
}