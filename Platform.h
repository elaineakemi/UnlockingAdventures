#ifndef PLATFORM_H
#define PLATFORM_H

#include "raylib.h"
#include "Character.h"

class Platform : public Character
{

public:
    Platform(Texture2D txtr, int numFrames, Vector2 pos, Color c);
};

#endif