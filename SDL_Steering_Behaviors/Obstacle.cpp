#include "Obstacle.h"
#include "SDL_SimpleApp.h"

Obstacle::Obstacle(Vector2D _position) : color({ 255,255,255,255 })
{
	position = _position;
	radius = 60;
}

Obstacle::~Obstacle()
{
}

void Obstacle::draw()
{
	draw_circle(TheApp::Instance()->getRenderer(), (int)position.x, (int)position.y, radius, color.r, color.g, color.b, color.a);
}
