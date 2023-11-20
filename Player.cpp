#include "Player.h"

Player::Player(Texture2D playertx, int numFrames, Vector2 pos, Color c)
    : playerTexture(playertx),
      numberFrames(numFrames),
      position(pos),
      color(c),
      frameRec({0.0f, 0.0f, (float)playerTexture.width / numberFrames - 1, (float)playerTexture.height}),
      currentFrame(0),
      framesCounter(0),
      framesSpeed(8) // TODO: add to some config file
{
}

void Player::Draw()
{
    DrawTextureRec(playerTexture, frameRec, position, color);
}

void Player::Move(Vector2 offset)
{
    position.x += offset.x;
    position.y += offset.y;
}

Vector2 Player::GetPosition() const
{
    return position;
}

void Player::Animate()
{
    framesCounter++;
    if (framesCounter >= (60 / framesSpeed))
    {
        framesCounter = 0;
        currentFrame++;

        if (currentFrame > numberFrames - 1)
            currentFrame = 0;

        frameRec.x = (float)currentFrame * (float)playerTexture.width / numberFrames;
    }
}
