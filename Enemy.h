#ifndef ENEMY_H
#define ENEMY_H

#include "raylib.h"
#include "Character.h"
#include "Assets.h"

class Enemy : public Character
{

private:
    Sound killSound{LoadSound("resources/sounds/kill_enemy.wav")};

    bool isOnGround;
    bool canBeKilled{false};
    Vector2 initialPosition;
    bool walkToLeft{true};
    int intervalHit{5};

public:
    // Constructors
    Enemy(TextureFrames txtr, Vector2 pos, Texture2D disappearChar, bool kill);
    Enemy();

    // Getters and Setters
    bool GetCanBeKilled() { return canBeKilled; }

    void Drop();
    void Move();
    void MoveBossLevel(bool isBoss);
    void Die();
};

#endif