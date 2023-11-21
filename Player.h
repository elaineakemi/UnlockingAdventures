#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"
#include "Character.h"

class Player : public Character
{

public:
    Player(Texture2D playertx, int numFrames, Vector2 pos, Color c);
};

#endif