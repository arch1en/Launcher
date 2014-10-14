#include "LoadingBarFrame.hpp"

LoadingBarFrame::LoadingBarFrame(const BarColor::ID, const sf::Texture& texture, const sf::Text& text)
	: Art(texture)
	, mSpriteRect { 1034, 228, 569, 81 }
	, mLoadingBar { texture }
	, mProgressString { text }
	, mCurrentTaskString { text }
	, mCurrentFileString { text }
	, mProgressPercent { 0.f }
	, mRealProgressBarScale { 1.f, 1.f }
{
	// LOADING BAR FRAME SETTINGS //
	getSprite().setTextureRect(mSpriteRect);
	getSprite().setScale(0.5f, 0.5f);

	// LOADING BAR SETTINGS //
	mLoadingBar.setTextureRect(sf::IntRect( 1050, 522, 529, 38));

	// PROGRESS STRING SETTINGS // 
	mProgressString.setStyle(sf::Text::Regular);
	mProgressString.setColor(sf::Color(124, 74, 31, 255));

	// CURRENT TASK STRING SETTINGS //
	mCurrentTaskString.setStyle(sf::Text::Regular);
	mCurrentTaskString.setColor(sf::Color(124,74,31,255));
	mCurrentTaskString.setString("Downloading: ");

	// CURRENT FILE STRING SETTINGS //
	mCurrentFileString.setStyle(sf::Text::Regular);
	mCurrentFileString.setColor(sf::Color(124,74,31,255));
	mCurrentFileString.setString("C:/Metin2/patch/patch_1.rar");
}

void LoadingBarFrame::render(sf::RenderWindow& window)
{
	window.draw(getSprite());
	window.draw(mLoadingBar);
	window.draw(mProgressString);
	window.draw(mCurrentTaskString);
	window.draw(mCurrentFileString);
}

void LoadingBarFrame::update(const sf::Time& dt)
{
	mLoadingBar.setScale(mProgressPercent * mRealProgressBarScale.x,getSprite().getScale().y);

	mProgressString.setString(convertProgress());

		if(mLoadingBar.getScale().x >= mRealProgressBarScale.x)
			mLoadingBar.setScale(mRealProgressBarScale.x, mRealProgressBarScale.y);
		if(mProgressPercent <= 1.f)
			mProgressPercent += 0.00001f;
		else
			mProgressPercent = 1.f;

}

void LoadingBarFrame::setPosition(float x, float y)
{
	/// LOADING BAR FRAME POSITION ///
	getSprite().setPosition(x,y);
	/// LOADING BAR POSITION ///
	mLoadingBar.setPosition(	x + xOffset * getSprite().getScale().x,
								y + yOffset * getSprite().getScale().y);
	/// PROGRESS TEXT POSITION ///
	mProgressString.setPosition(	mLoadingBar.getPosition().x + mLoadingBar.getGlobalBounds().width / 2.f - mProgressString.getGlobalBounds().width,
									mLoadingBar.getPosition().y + mLoadingBar.getGlobalBounds().height / 2.f - mProgressString.getGlobalBounds().height);
	// CURRENT TASK STRING POSITION //
	mCurrentTaskString.setPosition(	getSprite().getPosition().x, getSprite().getPosition().y + getSprite().getGlobalBounds().height);

	// CURRENT FILE STRING POSITION //
	mCurrentFileString.setPosition( mCurrentTaskString.getPosition().x, mCurrentTaskString.getPosition().y + mCurrentTaskString.getGlobalBounds().height);
}

const sf::Vector2f  LoadingBarFrame::getPosition()
{
	return sf::Vector2f(getSprite().getPosition().x, getSprite().getPosition().y);
}

void LoadingBarFrame::setScale(float x, float y)
{
	getSprite().setScale(x,y);
	mLoadingBar.setScale(x,y);
	mRealProgressBarScale = sf::Vector2f(x,y);
}

const sf::Vector2f LoadingBarFrame::getScale()
{
	return sf::Vector2f(getSprite().getScale().x, getSprite().getScale().y);
}
/////////////////////////////////
/// \brief - convertProgress() - functions converts float progress member variable into string literal, casting it beforehand to int, and ends with percent sign.
/// \return - const sf::String - returns parsed 
/////////////////////////////////
const std::string LoadingBarFrame::convertProgress() const
{
	char charBuffer[6];
	int intBuffer{static_cast<int>(mProgressPercent * 100.f)};
	sprintf_s(charBuffer, "%d %%", intBuffer);
	return charBuffer;
}

const float LoadingBarFrame::getBottomPosY() const
{
	return mCurrentFileString.getPosition().y + mCurrentFileString.getGlobalBounds().height;
}