#include "LoadingBar.hpp"

LoadingBar::LoadingBar(BarColor::ID color, const sf::Texture& texture)
	: Art(texture)
	, mProgress { 0.f }
{
	getSprite().setTextureRect(sf::IntRect( 1050, 522, 529, 38));

	if (color == BarColor::BLUE)
	{
		//1054, 433, 326, 38
	} 
	else if(color == BarColor::RED)
	{
		//mBar(1054, 433, 326, 38);
	}
	else if (color == BarColor::YELLOW)
	{
		//mBar(1050, 522, 529, 38);
	}
	else if (color == BarColor::GREEN)
	{
		//mBar(1054, 617, 326, 38);
	}
	else
	{
		//mBar(1054, 617, 326, 38);
	}
}

void LoadingBar::handleLoadingBar()
{
	
}

void LoadingBar::render(sf::RenderWindow& window)
{
	window.draw(getSprite());
}

void LoadingBar::update(const sf::Time& dt)
{
	getSprite().setScale(mProgress * mRealScale.x,getSprite().getScale().y);
}

void LoadingBar::addProgress(float progress)
{
	mProgress += progress;
}

const float LoadingBar::getProgress() const
{
	return mProgress;
}

void LoadingBar::setProgress(float progress)
{
	mProgress = progress;
}

void LoadingBar::setStatus(bool status)
{
	mStatus = status;
}

const bool LoadingBar::getStatus() const
{
	return mStatus;
}

void LoadingBar::setScale(float x, float y)
{
	getSprite().setScale(x,y);
	mRealScale = sf::Vector2f(x,y);
}


