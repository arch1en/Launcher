#pragma once

#include <SFML/Graphics.hpp>
#include "../ContentManager.hpp"

////////////////////////////////////////
/// \brief - Entity - An abstract class, that makes sure, that all elements deriving from this class will be placed at the 0 point of the world;
/// \done
////////////////////////////////////////
class Entity
{
public:
	Entity();	
	void				setPosition(float, float);
	void				setPosition(const sf::Vector2f&);
	const sf::Vector2f&	getPosition() const;
	void				setScale(float, float);
	void				setScale(const sf::Vector2f&);
	const sf::Vector2f&	getScale() const;
	void				setRotation(float);
	float				getRotation() const;
	void				setOrigin(float, float);
	void				setOrigin(const sf::Vector2f&);
	const sf::Vector2f&	getOrigin() const;

private:
	sf::Vector2f	mPosition;
	sf::Vector2f	mScale;
	float			mRotation;
	sf::Vector2f	mOrigin;
};
