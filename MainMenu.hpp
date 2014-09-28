#pragma once

#include <SFML/Graphics.hpp>
#include "ContentManager.hpp"
#include "Background.hpp"
 

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
	sf::Sprite				mLogo;
};