#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <cassert>

namespace Textures
{
	enum ID
	{
		GUI_SPRITESHEET,
		GUI_BACKGROUND,
		GUI_BUTTON,
		GUI_LOGO
	};
}

namespace Fonts
{
	enum ID
	{
		MENU_CAROLINGIA
	};
}

class ContentManager
{
public:
	ContentManager();

	sf::Texture& getTexture(Textures::ID) const;
	sf::Font& getFont(Fonts::ID) const;

private:
		std::map<Textures::ID, std::unique_ptr<sf::Texture>> textureMap;
		std::map<Fonts::ID, std::unique_ptr<sf::Font>> fontMap;

		void loadTexture(Textures::ID, const std::string&);
		void loadFont(Fonts::ID, const std::string&);


};