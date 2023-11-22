#include "math.h"
#include "Player.h"

Player::Player(Texture2D txtr, int numFrames, Vector2 pos, Color c)
    : Character(txtr, numFrames, pos, c),
      isPlayerOnGround(true),
      jumpValue(0.0f),
      groundValue(0.0f)
{
}

void Player::Update()
{

    if (IsKeyDown(KEY_RIGHT) && position.x < GetScreenWidth() - 50)
    {
        position.x += STEP;
    }

    if (IsKeyDown(KEY_LEFT) && position.x > 20)
    {
        position.x -= STEP;
    }

    if (IsKeyDown(KEY_DOWN) && position.y < GetScreenHeight() - 50)
    {
        position.y += STEP;
    }

    if ((IsKeyDown(KEY_UP) || IsKeyDown(KEY_SPACE)) && isPlayerOnGround)
    {
        isPlayerOnGround = false;
        jumpValue = -4.0f;
        groundValue = position.y;
    }

    if (isPlayerOnGround == false)
    {
        Jump();
    }
}

void Player::Jump()
{
    // Move 1 pixel at a time for collision detection
    for (int i = 0; i < abs((int)jumpValue); i++)
    {
        if (isPlayerOnGround == false)
        {
            position.y += jumpValue;
        }

        // If touch the ground reset position
        if (position.y > groundValue)
        {
            position.y = groundValue;
            isPlayerOnGround = true;
            break;
        }
    }
    // Update jump with gravity so player falls back
    jumpValue += GRAVITY;
}

void Player::JumpTrampoline(float groundf)
{
    groundValue = groundf;
    isPlayerOnGround = false;
    jumpValue = -6.0f;

    Jump();
}
