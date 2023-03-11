#include "screen.h"
#include "defs.h"
#include "circle.h"

Circle::Circle(Screen& screen,float radius)
{
	float radiusSquared=radius*radius;

	float leftBound =ORIGIN_X - radius ;
	float rightBound = ORIGIN_X + radius;
	float topBound =ORIGIN_Y + radius ;
	float bottomBound = ORIGIN_Y - radius;
	
	for(float i = leftBound;i<=rightBound;i++)
	{
		for(float j = bottomBound;j<=topBound;j++)
		{
			float x = (i-ORIGIN_X)*(i-ORIGIN_X);
			float y = (j-ORIGIN_Y)*(j-ORIGIN_Y);

			if(x+y==radiusSquared)
				screen.pixel(i,j); 
		}
	
	}




}
