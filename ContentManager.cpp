#include "ContentManager.hpp"

ContentManager::ContentManager()
{
	loadTexture(Textures::GUI_BACKGROUND, "D:/C++/VSWorkspace/Launcher/Launcher/content/textures/black-brick-wall-18482.jpg");
	loadTexture(Textures::GUI_SPRITESHEET, "D:/C++/VSWorkspace/Launcher/Launcher/content/textures/ADOM-OGA-UI-SmartObject.png");
	loadTexture(Textures::GUI_BUTTON, "D:/C++/VSWorkspace/Launcher/Launcher/content/textures/ADOM-OGA-BUTTON-SmartObject.png");
	loadTexture(Textures::GUI_LOGO, "D:/C++/VSWorkspace/Launcher/Launcher/content/textures/metin2_logo.png");
	loadFont(Fonts::MENU_CAROLINGIA, "D:/C++/VSWorkspace/Launcher/Launcher/content/fonts/CAROBTN_.TTF");
}
/////////////////////////////////////////
/// \brief - loadTexture - loads texture asset from given path.
/// \param Textures::ID textureID - enum element from "Texture" namespace. Kind of texture that we want to load.
/// \param const std::string& filename - a constant reference to the file path.
/////////////////////////////////////////
void ContentManager::loadTexture(Textures::ID textureID, const std::string& filename)
{
	std::unique_ptr<sf::Texture> texture{ new sf::Texture() };
	if (!texture->loadFromFile(filename))
		throw std::runtime_error("Failed to load texture: " + filename);

	

	auto inserted = textureMap.insert(std::make_pair(textureID, std::move(texture)));
	assert(inserted.second);
}
/////////////////////////////////////////
/// \brief - loadFont - loads font asset from given path.
/// \param Fonts::ID fontID - enum element from "Fonts" namespace. Kind of font that we want to load.
/// \param const std::string& filename - a constant reference to the file path.
/////////////////////////////////////////
void ContentManager::loadFont(Fonts::ID fontID, const std::string& filename)
{
	std::unique_ptr<sf::Font> font{ new sf::Font() };
	if (!font->loadFromFile(filename))
		throw std::runtime_error("Failed to load font: " + filename);

	auto inserted = fontMap.insert(std::make_pair(fontID, std::move(font)));
	assert(inserted.second);
}
/////////////////////////////////////////
/// \brief - getTexture - returns texture object from given ID
/// \param Textures::ID textureID - enum element from "Textures" namespace. Kind of texture that we want to load.
/// \return - returns sf::Texture object based on ID.
/////////////////////////////////////////
sf::Texture& ContentManager::getTexture(Textures::ID textureID) const
{
	auto found = textureMap.find(textureID);
	assert(found != textureMap.end());

	return *found->second;
}
/////////////////////////////////////////
/// \brief - getFont - returns font object from given ID
/// \param Font::ID fontID - enum element from "Fonts" namespace. Kind of font that we want to load.
/// \return - returns sf::Font object based on ID.
/////////////////////////////////////////
sf::Font& ContentManager::getFont(Fonts::ID fontID) const
{
	auto found = fontMap.find(fontID);
	assert(found != fontMap.end());

	return *found->second;
}