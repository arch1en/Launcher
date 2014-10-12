#include "LoadingBarFrame.hpp"

LoadingBarFrame::LoadingBarFrame(const sf::Texture& texture, sf::Text& text)
	: Art(texture)
	, mSpriteRect { 1034, 228, 569, 81 }
	, mProgress { text }
	, mLoadingBar { BarColor::YELLOW, texture }
{
	getSprite().setTextureRect(mSpriteRect);
	getSprite().setScale(0.5f, 0.5f);

	mProgress.setStyle(sf::Text::Regular);
	mProgress.setColor(sf::Color(124, 74, 31, 255));
}

void LoadingBarFrame::render(sf::RenderWindow& window)
{
	window.draw(getSprite());
	window.draw(mLoadingBar.getSprite());
	window.draw(mProgress);
}

void LoadingBarFrame::update(const sf::Time& dt)
{
	mLoadingBar.update(dt);

	;

	mLoadingBar.addProgress(0.0001f);

	if(mLoadingBar.getProgress() >= 1.f)
		mLoadingBar.setProgress(0.f);
}

void LoadingBarFrame::setPosition(float x, float y)
{
	/// LOADING BAR FRAME POSITION ///
	getSprite().setPosition(x,y);
	/// LOADING BAR POSITION ///
	mLoadingBar.getSprite().setPosition(x + xOffset * getSprite().getScale().x,
										y + yOffset * getSprite().getScale().y);
	/// PROGRESS TEXT POSITION ///
	mProgress.setPosition(		(getSprite().getPosition().x + getSprite().getGlobalBounds().width / 2 - mProgress.getGlobalBounds().width / 2) ,
								getSprite().getPosition().y + getSprite().getGlobalBounds().height / 2 - mProgress.getGlobalBounds().height / 2);
}

const sf::Vector2f  LoadingBarFrame::getPosition()
{
	return sf::Vector2f(getSprite().getPosition().x, getSprite().getPosition().y);
}

void LoadingBarFrame::setScale(float x, float y)
{
	getSprite().setScale(x,y);
	mLoadingBar.setScale(x,y);
}

const sf::Vector2f LoadingBarFrame::getScale()
{
	return sf::Vector2f(getSprite().getScale().x, getSprite().getScale().y);
}
/////////////////////////////////
/// \brief - convertProgress() - functions converts float progress member variable into string literal, casting it beforehand to int, and ends with percent sign.
/// \return - const sf::String - returns parsed 
/////////////////////////////////
const sf::String LoadingBarFrame::convertProgress() const
{
	char charBuffer[4];
	sprintf(charBuffer, mLoadingBar.getProgress(), 10);
	charBuffer[3] = '%';
	return charBuffer;
}