#include <SDL2/SDL_system.h>
/TODO ^ is this needed?
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

bool loadFromRenderedText(char* textureText, SDL_Color textColor, SDL_Texture** texture, TTF_Font *font) {
    //Get rid of preexisting texture
    //TODO do we need this even. maybe. it just frees the texture
    //free();

    //Render text surface
    SDL_Surface* textSurface = TTF_RenderText_Solid( font, textureText, textColor );
    if( textSurface == NULL )
    {
        printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
    }
    else
    {
        //Create texture from surface pixels
        *texture = SDL_CreateTextureFromSurface( gRenderer, textSurface );
        if( mTexture == NULL )
        {
            printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
        }
        else
        {
            //Get image dimensions
            //TODO is the neccessary for the texture? create texture struct??
            //mWidth = textSurface->w;
            //mHeight = textSurface->h;
        }

        //Get rid of old surface
        SDL_FreeSurface( textSurface );
    }

    //Return success
    return *texture != NULL;


}

void render( int x, int y, int height, int width, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip, SDL_Texture** texture)
{
    //Set rendering space and render to screen
    SDL_Rect renderQuad = { x, y, width, height };

    //Set clip rendering dimensions
    if( clip != NULL )
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }

    //Render to screen
    SDL_RenderCopyEx( gRenderer, *texture, clip, &renderQuad, angle, center, flip );
}

/*SDL_Texture* finalTexture;

 //TODO grab from main file and rework
bool loadFromFile(char* path)
{
    //Get rid of preexisting texture
    //TODO make free function
    free();

    //The final texture
    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(path);
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path, IMG_GetError() );
    }
    else
    {
        //Color key image
        SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );

        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
        if( newTexture == NULL )
        {
            printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }
        else
        {
            //Get image dimensions
            mWidth = loadedSurface->w;
            mHeight = loadedSurface->h;
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }

    //Return success
    //TODO is this some global variable??
    mTexture = newTexture;
    return mTexture != NULL;
}*/


