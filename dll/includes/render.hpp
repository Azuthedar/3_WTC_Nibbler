#pragma once

#include <iostream>
#include <curses.h>

class Render
{
	public:

		Render();
		Render(Render const & src);
		virtual ~Render();

		virtual Render  operator=(Render const & rhs);

		virtual void    renderPlayer();
		virtual void	renderFood();

	private:
		WINDOW *_window;
};