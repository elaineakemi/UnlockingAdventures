#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"
#include "Character.h"

class Player : public Character
{
private:
    bool isPlayerOnGround;
    float jumpValue;
    float groundValue;

public:
    Player(Texture2D playertx, int numFrames, Vector2 pos, Color c);

    void Update();
    void Jump();
};

#endif