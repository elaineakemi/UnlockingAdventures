#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"
#include "Character.h"

class Player : public Character
{
    const float GRAVITY = 0.3f;
    const float STEP = 2;

private:
    bool isPlayerOnGround{true};
    bool isPlayerOnPlatform{false};
    float jumpValue{0.0f};
    float groundValue{0.0f};

public:
    Player(Texture2D playertx, int numFrames, Vector2 pos, Color c, Texture2D disappearChar);

    void Update();
    void Jump();
    void JumpTrampoline(float groundf);

    bool GetIsPlayerOnGround() { return isPlayerOnGround; }
    void SetIsPlayerOnGround(bool isOnGround) { isPlayerOnGround = isOnGround; }
    bool GetIsPlayerOnPlatform() { return isPlayerOnPlatform; }
    void SetIsPlayerOnPlatform(bool isOnPlatform) { isPlayerOnPlatform = isOnPlatform; }
};

#endif