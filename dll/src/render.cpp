#include "../includes/render.hpp"


extern "C" Render *create_renderer()
{
	return (new Render);
}

extern "C" void	delete_renderer(Render *renderer)
{
	delete renderer;
}

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
	mvprintw(14, 10, "PPP");
}

void	Render::renderFood()
{

}