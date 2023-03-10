#include <SDL2/SDL.h>
#include "screen.h"
#include "defs.h"
#include "linec.h"
#include "circle.h"
#include "triangle.h"

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

	/* Draw triangle */
	Triangle tri(screen,2,3);

	/* Output */
	screen.show();




	



	return 0;
}
