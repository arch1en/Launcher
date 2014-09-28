#include "Art.hpp"

Art::Art(const sf::Texture& texture)
	: Entity()
	, mSprite{ texture }
{
	mSprite.setPosition(getPosition());
	mSprite.setScale(getScale());
	mSprite.setRotation(getRotation());
	mSprite.setOrigin(getOrigin());
}

const sf::Sprite&	Art::getSprite() const
{
	return mSprite;
}