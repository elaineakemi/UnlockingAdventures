#ifndef ENEMY_H
#define ENEMY_H

#include "raylib.h"
#include "Character.h"

class Enemy : public Character
{

private:
    bool isOnGround;

public:
    Enemy(Texture2D txtr, int numFrames, Vector2 pos, Color c);

    void Drop();
    void Move();
};

#endif