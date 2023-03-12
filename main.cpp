#include <SDL2/SDL.h>
#include "include/screen.h"
#include "include/defs.h"

void line(Screen &screen,float x1,float y1, float x2, float y2)
{
	float dx = x2 - x1;
	float dy = y2 - y1;

	float length = std::sqrt(dx * dx + dy * dy);
	float angle = std::atan2(dy,dx);

	for(float i = 0; i < length; i++)
	{
		screen.pixel(
				x1 + std::cos(angle) * i,
				y1 + std::sin(angle) * i
				);
	}
}


int main()
{
	/* Create screen */
	Screen screen;

	/* Draw a triangle */
  float a, b;
  a = 13;
  b = 10;
  float hyp = hypot(10,10);

	line(screen,ORIGIN_X,ORIGIN_Y,ORIGIN_X+a,ORIGIN_Y);
  line(screen,ORIGIN_X+a,ORIGIN_Y,ORIGIN_X+a,ORIGIN_Y+b);
  line(screen,ORIGIN_X,ORIGIN_Y,ORIGIN_X+a,ORIGIN_Y+b);

	/* Output */
	screen.show();




	



	return 0;
}
