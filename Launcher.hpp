#pragma once

#include <SFML/Graphics.hpp>
#include "MainMenu.hpp"
#include "ContentManager.hpp"

class Launcher
{
public:
	Launcher();
	void run();
	void render();
	void event();
	void update(const sf::Time&);

private:
	sf::RenderWindow	mWindow;
	sf::Event			mEvent;
	sf::Time			mLastUpdateTime;
	const sf::Time		mFrameTime;
	sf::Clock			mClock;
	ContentManager		mContentManager;
	MainMenu			mMainMenu;
};