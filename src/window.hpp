#pragma once

#include <curses.h>
#include <iostream>

class Window
{
	public:
		Window(); // Could add paramaters to get WinW && WinH (Size of the window) *window
		Window(Window const & src);
		virtual ~Window();

		Window		operator=(Window const & rhs);

		virtual void		setWinHeight(int windowHeight);
		virtual void		setWinWidth(int windowWidth);

		virtual int			getWinHeight();
		virtual int			getWinWidth();

	private:

		int		_winH;
		int		_winW;
};