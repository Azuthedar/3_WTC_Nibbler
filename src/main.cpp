#include "guiLib1.hpp"
#include <dlfcn.h>
#include <iostream>
#include <curses.h>
#include <unistd.h>
bool loop = true;


bool checkHandle(void *handle)
{
	if (!handle)
	{
		clear();
		printw("Library could not be loaded");
		usleep(4000);

		return (false);
	}
	return (true);
}

int main()
{
	void	*handle;
	Render *(*create)();
	Render *playerRender;
	void (*destroy)(Render*);


	initscr();
	nodelay(stdscr, true);
	keypad(stdscr, true);

	handle = dlopen("guilib1.so", RTLD_NOW);
	while (loop)
	{
		clear();
		if (loop)
		{
			int c = getch();
			switch (c)
			{
				case 27:
					loop = false;
					break ;
				case 259:
					if (handle)
						dlclose(handle);
					handle = dlopen("guilib3.so", RTLD_NOW);
					loop = checkHandle(handle);

					break ;
				case 260:
					if (handle)
						dlclose(handle);
					handle = dlopen("guilib1.so", RTLD_NOW);
					loop = checkHandle(handle);
					break ;
				case 261:
					if (handle)
						dlclose(handle);
					handle = dlopen("guilib2.so", RTLD_NOW);
					break;
			}
			if (handle)
			{
				// If a handle exists initialize the create and destroy
				create = (Render *(*)())dlsym(handle, "create_renderer");
				destroy = (void (*)(Render *))dlsym(handle, "delete_renderer");

				//Initialize playerRender and render the player
				playerRender = create();
				playerRender->renderPlayer();
			}
		}
		refresh();
		usleep(500);
	}
	destroy(playerRender);
	dlclose(handle);
	endwin();
	return (0);
}