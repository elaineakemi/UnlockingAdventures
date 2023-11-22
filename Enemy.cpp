#include "Enemy.h"

Enemy::Enemy(Texture2D txtr, int numFrames, Vector2 pos, Color c)
    : Character(txtr, numFrames, pos, c), isOnGround(false)
{
}

void Enemy::Drop()
{
    float dt = GetFrameTime() * GetFPS();
    if (!isOnGround)
    {
        if (position.y < GetScreenHeight() - 30 - texture.height)
        {
            position.y += dt * 5;
        }
        else
        {
            isOnGround = true;
        }
    }
    else
    {
        if (position.y >= 300)
        {
            position.y -= dt / 2;
        }
        else
        {
            isOnGround = false;
        }
    }
}

void Enemy::Move()
{
    float dt = GetFrameTime() * GetFPS();

    position.x -= dt / 2;
}
