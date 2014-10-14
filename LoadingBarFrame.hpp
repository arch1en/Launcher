#pragma once

#include "Art.hpp"
#include <sstream>
#include <stdlib.h>
#include <string>

const float xOffset{19};	//	offset from the edge of the frame to the inside.
const float yOffset{21};	//	offset from the edge of the frame to the inside.

namespace BarColor
{
	enum ID
	{
		GREEN
	};
}

class LoadingBarFrame : public Art
{
public:
	LoadingBarFrame(const BarColor::ID, const sf::Texture&, const sf::Text&);
	void	render(sf::RenderWindow&);
	void	update(const sf::Time&);
	void	setPosition(float, float);
	const sf::Vector2f getPosition();
	void	setScale(float, float);
	const sf::Vector2f getScale();
	const float getBottomPosY() const;			// Returns Y coordinate just below the last object from the loading bar structure.

private:
	sf::IntRect		mSpriteRect;
	sf::Sprite		mLoadingBar;
	sf::Text		mProgressString;			// Text of the progress of current activity.
	float			mProgressPercent;			// 
	sf::Vector2f	mRealProgressBarScale;		// 
	sf::Text		mCurrentTaskString;			// Text that describes, what does the launcher currently do (patching, updating, unpacking etc.)
	sf::Text		mCurrentFileString;

	const std::string convertProgress() const;
};