#ifndef ENEMY_H
#define ENEMY_H

#include "raylib.h"
#include "Character.h"
#include "Assets.h"

class Enemy : public Character
{

private:
    Sound killSound{LoadSound("resources/sounds/kill_enemy.wav")};

    bool canBeKilled{false};
    bool isOnGround{true};
    bool walkToLeft{true};
    int intervalHit{5};
    Vector2 initialPosition;

public:
    // Constructors
    Enemy() = default;
    Enemy(TextureFrames txtr, Vector2 pos, TextureFrames killtx, bool kill);

    // Getters and Setters
    bool GetCanBeKilled() { return canBeKilled; }

    void Drop();
    void Move();
    void MoveBossLevel(bool isBoss);
    void Die();
};

#endif