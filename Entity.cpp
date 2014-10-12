#include "source\Entity.hpp"
///////////////////////////////////////////////////
/// \brief - Entity - This class sets the default position of every element in the world.
///////////////////////////////////////////////////
Entity::Entity()
	: mPosition{ 0.f, 0.f }
	, mScale{ 1.f, 1.f }
	, mRotation{ 0.f }
	, mOrigin{ 0.f, 0.f }
{

}

void Entity::setPosition(float x, float y)
{
	mPosition.x = x;
	mPosition.y = y;
}
void Entity::setPosition(const sf::Vector2f& vector)
{
	mPosition.x = vector.x;
	mPosition.y = vector.y;
}

const sf::Vector2f& Entity::getPosition() const
{
	return mPosition;
}

void Entity::setScale(float x, float y)
{
	mScale.x = x;
	mScale.y = y;
}

void Entity::setScale(const sf::Vector2f& vector)
{
	mScale.x = vector.x;
	mScale.y = vector.y;
}

const sf::Vector2f&	Entity::getScale() const
{
	return mScale;
}

void Entity::setRotation(float rotation)
{
	mRotation = rotation;
}

float Entity::getRotation() const
{
	return mRotation;
}

void Entity::setOrigin(float x, float y)
{
	mOrigin.x = x;
	mOrigin.y = y;
}

void Entity::setOrigin(const sf::Vector2f& vector)
{
	mOrigin.x = vector.x;
	mOrigin.y = vector.y;
}

const sf::Vector2f& Entity::getOrigin() const
{
	return mOrigin;
}


