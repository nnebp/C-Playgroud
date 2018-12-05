//
// Created by something on 12/3/18.
//
#include <SDL2/SDL_ttf.h>
//TODO above or below inndef

#ifndef C_PLAYGROUD_TEXTURE_H
#define C_PLAYGROUD_TEXTURE_H

bool loadFromRenderedText(char* textureText, SDL_Color textColor, SDL_Texture** texture, TTF_Font *font);

#endif //C_PLAYGROUD_TEXTURE_H
