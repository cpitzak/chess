#include "MA_texture.h"



MA_texture::MA_texture(int _x, int _y, double _angle, SDL_Point *_center,
	SDL_Rect *_cliprect, SDL_RendererFlip _fliptype) : x{ _x }, y{ _y },
	angle{ _angle }, center{ _center }, cliprect{ _cliprect }, fliptype{ _fliptype } {

}


MA_texture::~MA_texture()
{
	// TODO: add this. what else to add?
	SDL_DestroyTexture(texture);
}

SDL_Texture * MA_texture::get_texture()
{
	return texture;
}

void MA_texture::set_texture(SDL_Texture * _texture)
{
	texture = _texture;
}

int MA_texture::get_x() const
{
	return x;
}

int MA_texture::get_y() const
{
	return y;
}

int MA_texture::get_width() const
{
	return width;
}

int MA_texture::get_height() const
{
	return height;
}

double MA_texture::get_angle() const
{
	return angle;
}

SDL_Point * MA_texture::get_center()
{
	return center;
}

SDL_Rect * MA_texture::get_cliprect()
{
	return cliprect;
}

SDL_RendererFlip MA_texture::get_fliptype()
{
	return fliptype;
}

void MA_texture::set_x(int _x)
{
	x = _x;
}

void MA_texture::set_y(int _y)
{
	y = _y;
}

void MA_texture::set_width(int _width)
{
	width = _width;
}

void MA_texture::set_height(int _height)
{
	height = _height;
}

void MA_texture::set_cliprect(SDL_Rect * _cliprect)
{
	cliprect = _cliprect;
}
