#include "MainMenu.hpp"

MainMenu::MainMenu(sf::RenderWindow& window, ContentManager& content)
	: mWindow{ window }
	, mBackground{ content.getTexture(Textures::GUI_BACKGROUND) }
	, mGUI{ content.getTexture(Textures::GUI_SPRITESHEET) }
	, mLogo{ content.getTexture(Textures::GUI_LOGO) }
	, mPlayButton { "Graj", ButtonAction::PLAY, content.getTexture(Textures::GUI_BUTTON), content.getFont(Fonts::MENU_CAROLINGIA) }
	, mOptionsButton { "Opcje", ButtonAction::OPTIONS, content.getTexture(Textures::GUI_BUTTON), content.getFont(Fonts::MENU_CAROLINGIA) }
	, mCurrentFileLoadingBar { BarColor::GREEN, content.getTexture(Textures::GUI_SPRITESHEET), sf::Text("DEBUG_MODE", content.getFont(Fonts::MENU_CAROLINGIA), 20) }
	, mSummaryFileLoadingBar { BarColor::GREEN, content.getTexture(Textures::GUI_SPRITESHEET), sf::Text("ERROR", content.getFont(Fonts::MENU_CAROLINGIA), 20) }
{
	//	PLAY BUTTON SETTINGS //
	mPlayButton.getSprite().setScale(0.4f, 0.4f);
	mPlayButton.getSprite().setPosition((1024 / 2) - (mPlayButton.getSprite().getGlobalBounds().width / 2), (640 / 2) + 45);

	//	OPTIONS BUTTON SETTINGS	//
	mOptionsButton.getSprite().setScale(0.4f, 0.4f);
	mOptionsButton.getSprite().setPosition(mPlayButton.getSprite().getPosition().x, mPlayButton.getSprite().getPosition().y + mPlayButton.getSprite().getLocalBounds().height * mPlayButton.getSprite().getScale().y );

	//	CURRENT FILE LOADING BAR SETTINGS //
	mCurrentFileLoadingBar.setPosition(10.f, mPlayButton.getSprite().getPosition().y);
	mCurrentFileLoadingBar.setScale(0.5f, 0.5f);

	//	SUMMARY FILE LOADING BAR SETTINGS //
	mSummaryFileLoadingBar.setPosition(10.f, mCurrentFileLoadingBar.getBottomPosY() + 10.f);
	mSummaryFileLoadingBar.setScale(0.5f, 0.5f);
}

void MainMenu::render()
{
	mBackground.render(mWindow);
	mLogo.render(mWindow);
	mPlayButton.render(mWindow);
	mOptionsButton.render(mWindow);
	mCurrentFileLoadingBar.render(mWindow);
	mSummaryFileLoadingBar.render(mWindow);

}

void MainMenu::update(const sf::Time& dt)
{
	mPlayButton.update(dt);
	mOptionsButton.update(dt);
	mCurrentFileLoadingBar.update(dt);
	mSummaryFileLoadingBar.update(dt);
}