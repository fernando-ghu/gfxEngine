#include <SDL2/SDL.h>
#include "include/screen.h"
#include "include/defs.h"

void line(Screen&,float,float,float,float);
void mystery(Screen&,float,float);

struct vec3
{
	float x, y, z;
};

struct connection 
{
	int a, b;
};

void rotate(vec3& point, float x=1, float y=1, float z=1)
{
	float rad = 0;

	rad = x;
	point.y = std::cos(rad) * point.y - std::sin(rad) * point.z;
	point.z = std::sin(rad) * point.y + std::cos(rad) * point.z;

	rad = y;
	point.x = std::cos(rad) * point.x + std::sin(rad) * point.z;
	point.z = -std::sin(rad) * point.x + std::cos(rad) * point.z;

	rad = z;
	point.x = std::cos(rad) * point.x - std::sin(rad) * point.y;
	point.y = std::sin(rad) * point.x + std::cos(rad) * point.y;
}

int main()
{
	/* Create screen */
	Screen screen;

	std::vector<vec3> points {
		{100,100,100},
		{200,100,100},
		{200,200,100},
		{100,200,100},

		{100,100,200},
		{200,100,200},
		{200,200,200},
		{100,200,200}
	};

	std::vector<connection> connections
	{
		{0,4},
		{1,5},
		{2,6},
		{3,7},

		{0,1},
		{1,2},
		{2,3},
		{3,0},

		{4,5},
		{5,6},
		{6,7},
		{7,4}
	};

	/* Calculate centroid */
	vec3 c{0,0,0};
	for(auto& p : points)
	{
		c.x += p.x;
		c.y += p.y;
		c.z += p.z;
	}
	c.x /= points.size();
	c.y /= points.size();
	c.z /= points.size();

	/* Output */
	while(true)
	{
		for(auto& p : points)
		{
			p.x -= c.x;
			p.y -= c.y;
			p.z -= c.z;
			rotate(p, 0.02, 0.01, 0.04);
			p.x += c.x;
			p.y += c.y;
			p.z += c.z;
			screen.pixel(p.x,p.y);
		}
		for(auto& conn : connections)
		{
			line(screen, points[conn.a].x,
									points[conn.a].y,
									points[conn.b].x,
									points[conn.b].y);
		}
		screen.show();
		screen.clear();
		screen.input();
		SDL_Delay(30);
	}
	




	



	return 0;
}
