#include "math.h"
#include "Player.h"

Player::Player(Texture2D txtr, int numFrames, Vector2 pos, Color c)
    : Character(txtr, numFrames, pos, c, LoadTexture("resources/textures/items/collected.png"))
{
}
Player::Player() {}

void Player::Init(int playerSelected)
{
    switch (playerSelected)
    {
    case 1:
        SetTexture(frogTexture);
        break;
    case 2:
        SetTexture(blueGuyTexture);
        break;
    case 3:
        SetTexture(pinkGuyTexture);
        break;
    default:
        SetTexture(frogTexture);
        break;
    }
}

void Player::Update()
{
    // If player moves invincibilty after die finishes
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_UP) || IsKeyDown(KEY_SPACE) ||
        IsKeyDown(KEY_A) || IsKeyDown(KEY_D) || IsKeyDown(KEY_W))
    {
        isInvincible = false;
    }

    if ((IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_A)) && position.x < GetScreenWidth() - 50)
    {
        prevPosition = position;
        position.x += STEP;
        SetFlipTexture(false);
    }

    if ((IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_D)) && position.x > 20)
    {
        prevPosition = position;
        position.x -= STEP;
        SetFlipTexture(true);
    }

    if ((IsKeyDown(KEY_UP) || IsKeyDown(KEY_SPACE) || IsKeyDown(KEY_W)) && (isPlayerOnGround || isPlayerOnPlatform))
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
        if (position.y > 400)
        {
            position.y = 400;
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
    if (!isInvincible)
    {

        playerLives--;
        // Gives invincibility after die until player moves to allow recovey time
        // if enemy is in same position player died
        isInvincible = true;
        if (playerLives < 0)
        {
            if (!isGameOver) // Avoid play sound again if is already playing
            {
                PlaySound(gameOverSound);
            }
            SetIsAlive(false);
            isGameOver = true;
        }
        else
        {
            PlaySound(playerDiedSound);
            WaitTime(1);
            // Reset player and move to initial position
            ResetPosition();
        }
    }
}

void Player::UndoMove()
{
    position = prevPosition;
}

void Player::ResetPosition()
{
    position.x = 15.0f;
    position.y = 400.0f;
    isPlayerOnGround = true;
    isPlayerOnPlatform = false;
}

void Player::Unload()
{
    UnloadTexture(disappearTexture);
    UnloadTexture(frogTexture);
    UnloadTexture(blueGuyTexture);
    UnloadTexture(pinkGuyTexture);

    UnloadSound(playerDiedSound);
}