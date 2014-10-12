#include "MainMenu.hpp"

MainMenu::MainMenu(sf::RenderWindow& window, ContentManager& content)
	: mWindow{ window }
	, mBackground{ content.getTexture(Textures::GUI_BACKGROUND) }
	, mGUI{ content.getTexture(Textures::GUI_SPRITESHEET) }
	, mLogo{ content.getTexture(Textures::GUI_LOGO) }
	, mPlayButton { "Graj", ButtonAction::PLAY, content.getTexture(Textures::GUI_BUTTON), content.getFont(Fonts::MENU_CAROLINGIA) }
	, mOptionsButton { "Opcje", ButtonAction::OPTIONS, content.getTexture(Textures::GUI_BUTTON), content.getFont(Fonts::MENU_CAROLINGIA) }
	, mCurrentFileLoadingBarFrame{ content.getTexture(Textures::GUI_SPRITESHEET), sf::Text("DEBUG_MODE", content.getFont(Fonts::MENU_CAROLINGIA), 20) }
{
	//	PLAY BUTTON SETTINGS //
	mPlayButton.getSprite().setScale(0.4f, 0.4f);
	mPlayButton.getSprite().setPosition((1024 / 2) - (mPlayButton.getSprite().getGlobalBounds().width / 2), (640 / 2) + 45);

	//	OPTIONS BUTTON SETTINGS	//
	mOptionsButton.getSprite().setScale(0.4f, 0.4f);
	mOptionsButton.getSprite().setPosition(mPlayButton.getSprite().getPosition().x, mPlayButton.getSprite().getPosition().y + mPlayButton.getSprite().getLocalBounds().height * mPlayButton.getSprite().getScale().y );

	//	CURRENT FILE LOADING BAR FRAME SETTINGS //
	mCurrentFileLoadingBarFrame.setPosition(10.f, mPlayButton.getSprite().getPosition().y);
	mCurrentFileLoadingBarFrame.setScale(0.5f, 0.5f);

	//	CURRENT FILE LOADING BAR SETTINGS //
}

void MainMenu::render()
{
	mBackground.render(mWindow);
	mLogo.render(mWindow);
	mPlayButton.render(mWindow);
	mOptionsButton.render(mWindow);
	mCurrentFileLoadingBarFrame.render(mWindow);
}

void MainMenu::update(const sf::Time& dt)
{
	mPlayButton.update(dt);
	mOptionsButton.update(dt);
	mCurrentFileLoadingBarFrame.update(dt);
}