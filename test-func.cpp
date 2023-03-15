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
					i+PI+ORIGIN_X-(i-j*PI/9) + std::cos(angle) * i/2,
					ORIGIN_Y/(i) + std::sin(angle) * i
					);
		}
	}
}


