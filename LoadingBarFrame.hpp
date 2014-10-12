#pragma once

#include "Art.hpp"
#include "LoadingBar.hpp"
#include <sstream>
#include <stdlib.h>

const float xOffset{19};	//	offset from the edge of the frame to the inside.
const float yOffset{21};	//	offset from the edge of the frame to the inside.

class LoadingBarFrame : public Art
{
public:
	LoadingBarFrame(const sf::Texture&, sf::Text&);
	void	render(sf::RenderWindow&);
	void	update(const sf::Time&);
	void	setPosition(float, float);
	const sf::Vector2f getPosition();
	void	setScale(float, float);
	const sf::Vector2f getScale();

private:
	sf::IntRect		mSpriteRect;
	LoadingBar		mLoadingBar;
	sf::Text		mProgress;			//	Progress of the currently downloading file

	const sf::String convertProgress() const;
};