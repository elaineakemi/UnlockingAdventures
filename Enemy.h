#ifndef ENEMY_H
#define ENEMY_H

#include "raylib.h"
#include "Character.h"

class Enemy : public Character
{

private:
    bool isOnGround;
    bool canBeKilled{false};
    Vector2 initialPosition;

public:
    Enemy(Texture2D txtr, int numFrames, Vector2 pos, Color c, Texture2D disappearChar, bool kill);

    bool GetCanBeKilled() { return canBeKilled; }

    void Drop();
    void Move();
};

#endif