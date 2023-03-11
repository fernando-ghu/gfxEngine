#include "screen.h"
#include "defs.h"
#include "triangle.h"

Triangle::Triangle(Screen& screen,float base,float height)
{
	float adjacent = base * base;
	float opposite = height * height;
	float hypotenuseSq = adjacent + opposite;
	float val = hypot(base,height); 

	float vertexB = ORIGIN_X+base;




	for(float i=0;i<=vertexB;i++)
	{
		screen.pixel(
				vertexB,
				ORIGIN_Y	
				);
	}
	/*
	float vertexC = vertexB+height;
	
	for(float i=ORIGIN_X;i<opposite;i++)
		{
			screen.pixel(
				ORIGIN_X + i,
				ORIGIN_Y + i
				);
		}
	for(float i=ORIGIN_X;i<hypot;i++)
		{
			screen.pixel(
				ORIGIN_X + i,
				ORIGIN_Y + i
				);
		}
		*/


}

