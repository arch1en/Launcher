
#include <SFML/System.hpp>
#include <iostream>

class DebugConsole
{
public:
	DebugConsole()
		: mFrame { 0 }
		, mFPS { 0 } {}
	void showResult()
	{
		if(mClock.getElapsedTime().asSeconds() >= 1.f)
	{
		mFPS = mFrame;
		mFrame = 0;
		std::cout << "FPS: " << mFPS << '\n';
		mClock.restart();
	}
	++mFrame;
	}
private:
	unsigned int mFrame;
	unsigned int mFPS;
	sf::Clock mClock;
};