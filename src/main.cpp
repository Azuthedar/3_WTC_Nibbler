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
		/*if (getch() == 27)
			loop = false;
		if (getch() == 260)
		{
			if (handle)
				dlclose(handle);
			handle = dlopen("guilib1.so", RTLD_DEFAULT);
			loop = checkHandle(handle);
			printw("I am in lib1");
		}
		else if (getch() == 261)
		{
			if (handle)
				dlclose(handle);
			handle = dlopen("guilib2.so", RTLD_DEFAULT);
			printw("I am in lib2");
		}
		else if (getch() == 259)
		{
			if (handle)
				dlclose(handle);
			handle = dlopen("guilib3.so", RTLD_DEFAULT);
			printw("I am in lib3");
		}*/
		if (handle)
		{
			create = (Render *(*)())dlsym(handle, "create_renderer");
			destroy = (void (*)(Render *))dlsym(handle, "destroy_renderer");

			playerRender = create();
			playerRender->renderPlayer();
		}
		refresh();
		usleep(500);
	}
	endwin();
	destroy(playerRender);

	/*void *handle = dlopen("MinMax.so", RTLD_LAZY);

	if (!handle)
	{
		std::cout << "Failed to open library" << std::endl;
		return (1);
	}

	maxMin *(*create)();
	void (*destroy)(maxMin*);

	create = (maxMin * (*)())dlsym(handle, "create_obj");
	destroy = (void (*) (maxMin *))dlsym(handle, "destroy_obj");
	maxMin *maxmin = create();
	maxmin->printSomething();
	destroy(maxmin);*/
	return (0);
}