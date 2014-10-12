#include "Art.hpp"
///////////////////////////////////////////////////
///	\brief - Art - This constructor is responsible for taking default parameters from Entity class
/// \param const sf::Texture& texture - a constant texture reference, which is later converted into sprite member object.
/// \desc - This class takes a texture, converts it into a sprite and resets it to the origin of the world. This however can be done only
/// to one sprite, not more (for now).
///////////////////////////////////////////////////
Art::Art(const sf::Texture& texture)
	: Entity()
	, mSprite{ texture }
{
	mSprite.setPosition(getPosition());
	mSprite.setScale(getScale());
	mSprite.setRotation(getRotation());
	mSprite.setOrigin(getOrigin());
}

sf::Sprite&	Art::getSprite()
{
	return mSprite;
}