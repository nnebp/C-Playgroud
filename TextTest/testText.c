#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>
#include <stdio.h>
#include "Texture.h"

//TODO not global
TTF_Font *font = NULL;
SDL_Texture* gTexture;
//The window renderer
SDL_Renderer* gRenderer = NULL;

//Screen dimension constants
//TODO no longer global?
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
int width;
int height;

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

bool init(SDL_Window** gWindow, int screenWidth, int screenHeight) {
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Set texture filtering to linear
        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
        {
            printf( "Warning: Linear texture filtering not enabled!" );
        }

        //Create window
        gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Create vsynced renderer for window
            gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
            if( gRenderer == NULL )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) )
                {
                    printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                    success = false;
                }

                //Initialize SDL_ttf
                if( TTF_Init() == -1 )
                {
                    printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
                    success = false;
                }
            }
        }
    }

    return success;
}

bool loadMedia()
{
    //Loading success flag
    bool success = true;

    //Open the font
    font = TTF_OpenFont( "/home/something/Dev/C-Playgroud/TextTest/alterebro-pixel-font.ttf", 28 );
    if( font == NULL )
    {
        printf( "Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError() );
        success = false;
    }
    else
    {
        //Render text
        SDL_Color textColor = { 0, 0, 0 };
        //if( !gTextTexture.loadFromRenderedText( "The quick brown fox jumps over the lazy dog", textColor ) )
        if(!loadFromRenderedText("The quick brown fox jumps over the lazy dog", textColor, &gTexture, font, gRenderer, &width, &height)) {
        //if( !loadFromRenderedText( "The quick brown fox jumps over the lazy dog", textColor, &gTexture, font ) )

            printf( "Failed to render text texture!\n" );
            success = false;
        }
    }

    return success;
}
/*
bool loadMedia(SDL_Surface** surface) {
    //Loading success flag
    bool success = true;

    //Load splash image
    *surface = SDL_LoadBMP( "/home/something/Dev/C-Playgroud/TextTest/hello_world.bmp" );
    if( *surface == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "./hello_world.bmp", SDL_GetError() );
        success = false;
    }

    return success;
}
 */

void closeAll(SDL_Window** gWindow, SDL_Surface** gHelloWorld) {
    //Deallocate surface
    SDL_FreeSurface( *gHelloWorld );
    *gHelloWorld = NULL;

    //Destroy window
    SDL_DestroyWindow( *gWindow );
    *gWindow = NULL;

    //Quit SDL subsystems
    SDL_Quit();
}

int main(int argc, char* args[]) {

    //Start up SDL and create window
    if( !init(gWindow, SCREEN_HEIGHT, SCREEN_HEIGHT) )
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {
        //Load media
        if( !loadMedia() )
        {
            printf( "Failed to load media!\n" );
        }
        else
        {
            //Main loop flag
            bool quit = false;

            //Event handler
            SDL_Event e;

            //While application is running
            while( !quit )
            {
                //Handle events on queue
                while( SDL_PollEvent( &e ) != 0 )
                {
                    //User requests quit
                    if( e.type == SDL_QUIT )
                    {
                        quit = true;
                    }
                }

                //Clear screen
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
                SDL_RenderClear( gRenderer );

                //Render current frame
                //gTextTexture.render( ( SCREEN_WIDTH - gTextTexture.getWidth() ) / 2, ( SCREEN_HEIGHT - gTextTexture.getHeight() ) / 2 );
                render(222, 222, height, width, NULL, 0.0, NULL, SDL_FLIP_NONE, &gTexture, gRenderer);
                //render( ( SCREEN_WIDTH - gTextTexture.getWidth() ) / 2, ( SCREEN_HEIGHT - gTextTexture.getHeight() ) / 2 );

                //Update screen
                SDL_RenderPresent( gRenderer );
            }
        }
    }

    //Free resources and close SDL
    //close();

    return 0;
}