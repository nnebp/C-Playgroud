#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>


bool init(SDL_Window* gWindow, SDL_Surface* gScreenSurface, int screenWidth, int screenHeight) {
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Create window
        gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Get window surface
            gScreenSurface = SDL_GetWindowSurface( gWindow );
        }
    }

    printf("is gwindow null? %d", gWindow == NULL);
    return success;
}

bool loadMedia(SDL_Surface* surface) {
    //Loading success flag
    bool success = true;

    //Load splash image
    surface = SDL_LoadBMP( "./hello_world.bmp" );
    if( surface == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "./hello_world.bmp", SDL_GetError() );
        success = false;
    }

    return success;
}

int main(int argc, char* args[]) {

    //The window we'll be rendering to
    SDL_Window* gWindow = NULL;

    //The surface contained by the window
    SDL_Surface* gScreenSurface = NULL;

    //The image we will load and show on the screen
    SDL_Surface* gHelloWorld = NULL;


    //Start up SDL and create window
    if(!init(gWindow, gScreenSurface, 1000, 1000))
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {
        //Load media
        if(!loadMedia(gHelloWorld))
        {
            printf( "Failed to load media!\n" );
        }
        else
        {
            //Apply the image
            printf( "blit result: %d", SDL_BlitSurface( gHelloWorld, NULL, gScreenSurface, NULL ));
            printf( "helloWorld null?: %d", (NULL != gHelloWorld));
            printf( "gScreenSurface null?: %d", (NULL != gScreenSurface));

            //Update the surface
            SDL_UpdateWindowSurface( gWindow );

            //Wait two seconds
            SDL_Delay( 2000 );
        }
    }

    //Free resources and close SDL
    //close();

    return 0;
}