#pragma once

#include "source/Entity.hpp"

////////////////////////////////////////
/// \brief - Art - A class that represents all elements which will be drawn onto the screen. Element that has one image or more, needs to inherit this class.
////////////////////////////////////////
class Art : public Entity
{
public:
	Art(const sf::Texture&);
	
	virtual void render(sf::RenderWindow&) = 0;
	sf::Sprite&	getSprite();

private:
	sf::Sprite		mSprite;
	
};