#include "Enemy.h"

Enemy::Enemy(Texture2D txtr, int numFrames, Vector2 pos, Color c)
    : Character(txtr, numFrames, pos, c)
{
}

bool isOnGround = false;
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
            position.y -= dt;
        }
        else
        {
            isOnGround = false;
        }
    }
}