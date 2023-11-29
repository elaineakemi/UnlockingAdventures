#ifndef ENEMY_H
#define ENEMY_H

#include "raylib.h"
#include "Character.h"

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
    Enemy(Texture2D txtr, int numFrames, Vector2 pos, Color c, Texture2D disappearChar, bool kill);
    Enemy();

    bool GetCanBeKilled() { return canBeKilled; }

    void Drop();
    void Move();
    void MoveBossLevel(bool isBoss);
    void Kill();
    bool CheckBossCollision(Rectangle playerPos, int *bossHealth);
};

#endif