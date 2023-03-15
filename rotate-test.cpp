#include <vector>
#include <cmath>

struct vec3
{
	float x,y,z;
};

void rotate(vec3& point,float x=1, float y=1, float z=1)
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
	std::vector<vec3> point{
		{1,1,0}
	};

	rotate(point);

	return 0;
}
