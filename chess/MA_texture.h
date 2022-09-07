#pragma once
#include<SDL.h>
class MA_texture
{
public:
	MA_texture(int _x, int _y, double _angle, SDL_Point *_center,
		SDL_Rect *_cliprect, SDL_RendererFlip _fliptype);
	~MA_texture();

	SDL_Texture *get_texture();
	void set_texture(SDL_Texture *_texture);
	int get_x() const;
	int get_y() const;
	int get_width() const;
	int get_height() const;
	double get_angle() const;
	SDL_Point *get_center();
	SDL_Rect *get_cliprect();
	SDL_RendererFlip get_fliptype();
	void set_x(int _x);
	void set_y(int _y);
	void set_width(int _width);
	void set_height(int _height);
	void set_cliprect(SDL_Rect *_cliprect);

private:
	int x, y, width, height;
	double angle;
	SDL_Point *center;
	SDL_Rect *cliprect;
	SDL_RendererFlip fliptype;
	SDL_Texture *texture;
};

