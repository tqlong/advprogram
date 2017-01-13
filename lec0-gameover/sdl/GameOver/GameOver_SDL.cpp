#include <SDL.h>
#include <iostream>

using namespace std;

const int SCREEN_WIDTH = 640; //Screen width
const int SCREEN_HEIGHT = 480; // Screen height

int main( int argc, char* args[] )
{
	SDL_Window* window = NULL; 	//The window we'll be rendering to
	SDL_Surface* screenSurface = NULL; //The surface contained by the window

	if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) //Initialize SDL
	{
		cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
	}
	else
	{
		window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN ); //Create window
		if( window == NULL )
		{
			cout << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
		}
		else
		{
			screenSurface = SDL_GetWindowSurface( window ); //Get window surface
			
			SDL_Surface* gGameOver = SDL_LoadBMP( "gameover.bmp" );			
			if( gGameOver == NULL )
			{
				cout << "Unable to load image gameover.bmp SDL Error: " << SDL_GetError() << endl;
			}
			else
			{
				SDL_BlitSurface( gGameOver, NULL, screenSurface, NULL );
			}

			SDL_UpdateWindowSurface( window ); //Update the surface
			SDL_Delay( 2000 ); //Wait two seconds
		}
	}

	SDL_DestroyWindow( window ); //Destroy window
	SDL_Quit(); //Quit SDL subsystems

	return 0;
}
