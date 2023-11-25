#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"
#include "Character.h"

extern int playerLives;

class Player : public Character
{
    const float GRAVITY = 0.3f;
    const float STEP = 2;

private:
    bool isPlayerOnGround{true};    // Used to check if player can jump - to not allow double jump
    bool isPlayerOnPlatform{false}; // Used to check if player should fall in next iteration

    float jumpValue{0.0f};
    float groundValue{0.0f};

    Vector2 prevPosition;

public:
    Player(Texture2D playertx, int numFrames, Vector2 pos, Color c, Texture2D disappearChar);

    void Update();
    void Jump();
    void JumpTrampoline(float groundf);
    void Die();
    void UndoMove();

    bool GetIsPlayerOnGround() { return isPlayerOnGround; }
    void SetIsPlayerOnGround(bool isOnGround) { isPlayerOnGround = isOnGround; }
    bool GetIsPlayerOnPlatform() { return isPlayerOnPlatform; }
    void SetIsPlayerOnPlatform(bool isOnPlatform) { isPlayerOnPlatform = isOnPlatform; }
};

#endif