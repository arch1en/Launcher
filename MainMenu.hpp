#pragma once

#include <SFML/Graphics.hpp>
#include "ContentManager.hpp"
#include "Background.hpp"
#include "Logo.hpp"
#include "Button.hpp"
#include "LoadingBarFrame.hpp"
#include "LoadingBar.hpp"
 

class MainMenu
{
public:
	MainMenu(sf::RenderWindow&, ContentManager&);

	void					render();
	void					events();
	void					update(const sf::Time&);
private:

	sf::RenderWindow&		mWindow;
	Background				mBackground;
	sf::Sprite 				mGUI;
	Logo					mLogo;
	Button					mPlayButton;
	Button					mOptionsButton;
	LoadingBarFrame			mCurrentFileLoadingBarFrame;
};