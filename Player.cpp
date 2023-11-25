#include "math.h"
#include "Player.h"

Player::Player(Texture2D txtr, int numFrames, Vector2 pos, Color c, Texture2D disappearChar)
    : Character(txtr, numFrames, pos, c, disappearChar)
{
}

void Player::Update()
{

    if (IsKeyDown(KEY_RIGHT) && position.x < GetScreenWidth() - 50)
    {
        prevPosition = position;
        position.x += STEP;
    }

    if (IsKeyDown(KEY_LEFT) && position.x > 20)
    {
        prevPosition = position;
        position.x -= STEP;
    }

     if ((IsKeyDown(KEY_UP) || IsKeyDown(KEY_SPACE)) && (isPlayerOnGround || isPlayerOnPlatform))
    {
        if (isPlayerOnGround)
        {
            isPlayerOnGround = false;
            groundValue = position.y;
        }

        if (isPlayerOnPlatform)
        {
            isPlayerOnPlatform = false;
        }
        jumpValue = -4.0f;
    }

    if (isPlayerOnGround == false && isPlayerOnPlatform == false)
    {
        Jump();
    }
}

void Player::Jump()
{
    // Move 1 pixel at a time for collision detection
    for (int i = 0; i < abs((int)jumpValue); i++)
    {
        if (isPlayerOnGround == false || isPlayerOnPlatform == false)
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
    jumpValue = -5.0f;

    Jump();
}

void Player::Die()
{
    playerLives--;
    if (playerLives < 0)
    {
        SetIsAlive(false);
    }
    else
    {
        // Reset player and move to initial position
        position.x = 15.0f;
        position.y = 400.0f;
        isPlayerOnGround = true;
        isPlayerOnPlatform = false;
    }
}

void Player::UndoMove()
{
    position = prevPosition;
}
