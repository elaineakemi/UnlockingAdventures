#include "Enemy.h"

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

// Boss walks faster and returns when reaches corner
void Enemy::MoveBoss(bool isBoss)
{
    float dt = GetFrameTime() * GetFPS();

    if (!isBoss)
    {
        dt = dt / 2;
    }

    if (position.x <= 20)
    {
        walkToLeft = false;
    }
    else if (position.x >= GetScreenWidth() - 80)
    {
        walkToLeft = true;
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

void Enemy::Kill()
{
    PlaySound(killSound);
    SetIsAlive(false);
}

bool Enemy::CheckBossCollision(Rectangle playerPos, int *bossHealth)
{
    bool playerDied = false;
    if (intervalHit == 0)
    {
        if (CheckCollisionRecs(playerPos, GetPositionRec()))
        { // Check if colision comes from top
            if (playerPos.y < 375)
            {
                PlaySound(killSound);
                bossHealth = bossHealth - 1;
            }
            else
            {
                playerDied = true;
            }
        }
        intervalHit = 5;
    }
    else
    {
        intervalHit--;
    }
    return playerDied;
}
