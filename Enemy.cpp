#include "Enemy.h"

Enemy::Enemy() {}

Enemy::Enemy(Texture2D txtr, int numFrames, Vector2 pos, Color c, Texture2D disappearChar, bool kill)
    : Character(txtr, numFrames, pos, c, disappearChar), isOnGround(true), canBeKilled(kill), initialPosition(pos)
{
}

void Enemy::Drop()
{
    // Get delta
    float dt = GetFrameTime() * GetFPS();

    if (!isOnGround)
    {
        // Drop enemy with delta * 5 speed
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
        // Enemy goes up with 0.5 delta speed
        if (position.y >= initialPosition.y)
        {
            position.y -= dt / 2;
        }
        else
        {
            isOnGround = false;
        }
    }
}

// Normal level enemy disappears when reaches corner
void Enemy::Move()
{
    if (!GetIsAlive())
        return;
    float dt = GetFrameTime() * GetFPS();

    if (position.x > 20)
    {
        position.x -= dt / 2;
    }
    else
    {
        SetIsAlive(false);
    }
}

// Boss level enemy comes back when reaches corner
void Enemy::MoveBossLevel(bool isBoss)
{
    float dt = GetFrameTime() * GetFPS();

    // Boss walks faster than normal enemies
    if (!isBoss)
    {
        dt = dt / 2;
    }

    if (position.x <= 20)
    {
        walkToLeft = false;
        SetFlipTexture(true);
    }
    else if (position.x >= GetScreenWidth() - 80)
    {
        walkToLeft = true;
        SetFlipTexture(false);
    }

    if (walkToLeft)
    {
        position.x -= dt;
    }
    else
    {
        position.x += dt;
    }
}

void Enemy::Die()
{
    PlaySound(killSound);
    SetIsAlive(false);
}