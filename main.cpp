#include <SDL2/SDL.h>
#include "include/screen.h"
#include "include/defs.h"

void line(Screen&,float,float,float,float);
void mystery(Screen&,float,float);

int main()
{
	/* Create screen */
	Screen screen;

	/* Testing mystery function */
	for(float i=0;i<100;i++)
	{
		mystery(screen,89.9,i*PI/9);
	}

	/* Output */
	screen.show();




	



	return 0;
}
