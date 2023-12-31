#include "Enemy.h"

Enemy::Enemy(TextureFrames txtr, Vector2 pos, TextureFrames killtx, bool kill)
    : Character(txtr, pos, killtx), canBeKilled(kill), isOnGround(true), initialPosition(pos) {}

void Enemy::Drop()
{
    // Get delta
    float dt = GetFrameTime() * GetFPS();

    if (!isOnGround)
    {
        // Drop enemy with delta * 5 speed
        if (position.y < GetScreenHeight() - 30 - textureWithFramesNumber.texture.height)
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

// Move enemies to left
// Normal level enemies disappears when reaches corner
void Enemy::Move()
{
    // If is dead, do nothing
    if (!GetIsAlive())
        return;

    // Get delta
    float dt = GetFrameTime() * GetFPS();

    // Walk until reaches corner, then disappear
    if (position.x > 20)
    {
        position.x -= dt / 2;
    }
    else
    {
        SetIsAlive(false);
    }
}

// Move enemies in the boss level
// Boss level enemy comes back when reaches corner
void Enemy::MoveBossLevel(bool isBoss)
{
    // Get delta
    float dt = GetFrameTime() * GetFPS();

    // Boss walks faster than normal enemies
    if (!isBoss)
    {
        dt = dt / 2;
    }

    // Walk to left until reaches corner, then flip and walk right
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

// When enemy die play sound and set to not appear anymore
void Enemy::Die()
{
    PlaySound(gameSounds.killEnemy);
    SetIsAlive(false);
}