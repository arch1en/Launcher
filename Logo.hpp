#pragma once

#include "Art.hpp"

class Logo : public Art
{
public:
	Logo(const sf::Texture&);
	void render(sf::RenderWindow&);
};