#include <SDL2/SDL.h>
#include "include/screen.h"
#include "include/defs.h"

void line(Screen& screen,float x1,float y1, float x2,float y2)
{
	float dx = x2 - x1;
	float dy = y2 - y1;

	float length = hypot(dx,dy);
	float angle = std::atan2(dy,dx);

	for(float i = 0; i < length; i++)
	{
		screen.pixel(
				x1 + std::cos(angle) * i,
				y1 + std::sin(angle) * i
				);
	}
}

void mystery(Screen& screen,float len,float angle)
{
	for(float i = 0; i < len; i++)
	{
		for(float j = 0; j < PI; j++)
		{
			screen.pixel(
					PI+0+ORIGIN_X+(i*PI+j*PI/6) + std::cos(angle) * j/2,
					PI*ORIGIN_Y/(i/2) + std::sin(angle) * i
					);
		}
	}
}
