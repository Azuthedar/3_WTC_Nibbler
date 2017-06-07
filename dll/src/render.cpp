#include "../includes/render.hpp"

Render::Render()
{
	return ;
}

Render::Render(Render const & src)
{
	*this = src;
}

Render::~Render()
{
	return ;
}

Render Render::operator=(Render const & rhs)
{
	this->_window = rhs._window;
	return *this;
}

void	Render::renderPlayer()
{

}

void	Render::renderFood()
{

}