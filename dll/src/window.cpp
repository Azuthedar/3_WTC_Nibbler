#include "../includes/window.hpp"

Window::Window() //Default constructor
{
	return ;
}

Window::Window(Window const & src) //Copy constructor
{
	this->_winH = src._winH;
	this->_winW = src._winW;
	*this = src;
}

Window::~Window() //Deconstructor
{
	return ;
}

Window      Window::operator=(Window const & rhs)
{
	this->_winH = rhs._winH;
	this->_winW = rhs._winW;
	return (*this);
}

void		Window::setWinHeight(int windowHeight)
{
	this->_winH = windowHeight;
}

void		Window::setWinWidth(int windowWidth)
{
	this->_winW = windowWidth;
}

int			Window::getWinHeight()
{
	return (this->_winH);
}

int			Window::getWinWidth()
{
	return (this->_winW);
}