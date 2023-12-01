#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"
#include "Character.h"
#include "Assets.h"

// Global variables
extern int playerLives;
extern bool isGameOver;

// Global assets
extern PlayerTextures playerTextures;

class Player : public Character
{
    // Constants used only for player
    const float GRAVITY = 0.3f;
    const float STEP = 2;

private:
    // Sounds
    Sound gameOverSound{LoadSound("resources/sounds/gameover.wav")};
    Sound playerDiedSound{LoadSound("resources/sounds/player_died.wav")};

    bool isPlayerOnGround{true};    // Used to check if player can jump - to not allow double jump
    bool isPlayerOnPlatform{false}; // Used to check if player should fall in next iteration
    bool isInvincible{false};

    float jumpValue{0.0f};
    float groundValue{0.0f};

    Vector2 prevPosition; // To allow undo moviment

public:
    // Constructor
    Player(TextureFrames playertx, Vector2 pos);
    Player();

    // Getters and Setters
    bool GetIsPlayerOnGround() { return isPlayerOnGround; }
    void SetIsPlayerOnGround(bool isOnGround) { isPlayerOnGround = isOnGround; }
    bool GetIsPlayerOnPlatform() { return isPlayerOnPlatform; }
    void SetIsPlayerOnPlatform(bool isOnPlatform) { isPlayerOnPlatform = isOnPlatform; }

    void Init(int playerSelected);
    void Update();
    void Jump();
    void JumpTrampoline(float groundf);
    void Die();
    void UndoMove();
    void ResetPosition();
    void Unload();
};

#endif