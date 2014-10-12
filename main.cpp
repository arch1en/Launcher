
#define _CRTDBG_NAP_ALLOC

#include <stdlib.h>
#include <crtdbg.h>

#include "Launcher.hpp"

int main(int argc, char* argv[])
{

	Launcher launcher;
	launcher.run();

	_CrtDumpMemoryLeaks();

	return 0;
}