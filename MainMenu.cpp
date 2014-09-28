#include "MainMenu.hpp"

MainMenu::MainMenu(sf::RenderWindow& window, ContentManager& content)
	: mWindow{ window }
	, mBackground{ content.getTexture(Textures::GUI_BACKGROUND) }
	, mGUI{ content.getTexture(Textures::GUI_SPRITESHEET) }
	, mLogo{ content.getTexture(Textures::GUI_LOGO) }
{

}

void MainMenu::render()
{
	mBackground.render(mWindow);
	//mWindow.draw(mGUI);
}

void MainMenu::update(const sf::Time& dt)
{

}