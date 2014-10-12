#pragma once

#include "Art.hpp"

class Background : public Art
{
public:
	Background(const sf::Texture&);
	void render(sf::RenderWindow&);
	sf::Sprite	mSprite2;
};