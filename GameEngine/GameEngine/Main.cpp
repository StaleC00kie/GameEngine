#include "Main.h"


int main()
{
	SDL_SetMainReady();
	auto app = new Engine();

	app->run("test", 800, 600, false);

	//delete app;

	return 0;
}