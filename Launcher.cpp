#include "Launcher.hpp"

Launcher::Launcher()
	: mWindow{ sf::VideoMode(1024, 640), "Metin Launcher", sf::Style::None }
	, mEvent{}
	, mFrameTime{ sf::seconds(1.f / 60.f) }
	, mContentManager{}
	, mMainMenu{ mWindow, mContentManager } 
	, mDebugConsole{}
{
	mWindow.setFramerateLimit(60);
	mWindow.setVerticalSyncEnabled(true);
}

void Launcher::run()
{
	while (mWindow.isOpen())
	{
		mDebugConsole.showResult();

		event();
		mLastUpdateTime += mClock.getElapsedTime();

		while (mLastUpdateTime > mFrameTime)
		{
			mLastUpdateTime -= mFrameTime;
			update(mFrameTime);
		}

		mWindow.clear(sf::Color::White);
		render();
		mWindow.display();
	}
}

void Launcher::render()
{
	mMainMenu.render();
}

void Launcher::event()
{
	while (mWindow.pollEvent(mEvent))
	{

	}
}

void Launcher::update(const sf::Time& dt)
{
	mMainMenu.update(dt);
}