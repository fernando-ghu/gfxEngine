#ifndef INCLUDE_SCREEN_H
#define INCLUDE_SCREEN_H

#include<SDL2/SDL.h>
#include<vector>

class Screen
{
	SDL_Event e;
	SDL_Window* window;
	SDL_Renderer* renderer;
	std::vector<SDL_FPoint> points;

	public:
	Screen()
	{
		SDL_Init(SDL_INIT_VIDEO);
		SDL_CreateWindowAndRenderer(
				240*2,240*2,0,&window,&renderer);
		SDL_RenderSetScale(renderer,2,2);
	}

	void pixel(float x, float y)
	{
		points.emplace_back(x,y);
	}

	void show()
	{
		SDL_SetRenderDrawColor(renderer,0,0,0,255);
		SDL_RenderClear(renderer);

		SDL_SetRenderDrawColor(renderer,255,255,255,255);
		for(auto& point : points)
		{
			SDL_RenderDrawPointF(renderer,point.x,point.y);
		}
		SDL_RenderPresent(renderer);
		SDL_Delay(3000); /* Window closes after 3sec */
	}

	void clear()
	{
		points.clear();
	}

	void input()
	{
		while(SDL_PollEvent(&e))
		{
			if(e.type == SDL_QUIT)
			{
				SDL_Quit();
				exit(0);
			}
		}
	}
};
#endif



