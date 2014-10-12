#pragma once

#include "Art.hpp"

namespace BarColor
{
	enum ID
	{
		BLUE,
		RED,
		YELLOW,
		GREEN
	};
}

class LoadingBar : public Art
{
public:
	LoadingBar(BarColor::ID, const sf::Texture&);
	void render(sf::RenderWindow&);
	void update(const sf::Time&);
	void handleLoadingBar();
	void addProgress(float);
	const float getProgress() const;
	void setProgress(float);
	void setStatus(bool);
	const bool getStatus() const;
	void setScale(float, float);
	const sf::Vector2f getRealScale() const;

private:

	float			mProgress;
	bool			mStatus;
	sf::Vector2f	mRealScale;		// scale that is 
};