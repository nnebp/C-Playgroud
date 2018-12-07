//
// Created by something on 12/3/18.
//
#include <SDL2/SDL_ttf.h>
//TODO above or below inndef

#ifndef C_PLAYGROUD_TEXTURE_H
#define C_PLAYGROUD_TEXTURE_H

bool loadFromRenderedText(char* textureText, SDL_Color textColor, SDL_Texture** texture, TTF_Font *font, SDL_Renderer* renderer, int* width, int* height);
//TODO remove this garbage
void render( int x, int y, int height, int width, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip, SDL_Texture** texture, SDL_Renderer* renderer);

#endif //C_PLAYGROUD_TEXTURE_H
