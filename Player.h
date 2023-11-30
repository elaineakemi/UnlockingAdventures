#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"
#include "Character.h"

extern int playerLives;
extern bool isGameOver;

class Player : public Character
{
    const float GRAVITY = 0.3f;
    const float STEP = 2;

private:
    Sound gameOverSound{LoadSound("resources/sounds/gameover.wav")};
    Sound playerDiedSound{LoadSound("resources/sounds/player_died.wav")};
    Texture2D frogTexture{LoadTexture("resources/textures/characters/frog.png")};
    Texture2D blueGuyTexture{LoadTexture("resources/textures/characters/blue_guy.png")};
    Texture2D pinkGuyTexture{LoadTexture("resources/textures/characters/pink_guy.png")};

    bool isPlayerOnGround{true};    // Used to check if player can jump - to not allow double jump
    bool isPlayerOnPlatform{false}; // Used to check if player should fall in next iteration
    bool isInvincible{false};

    float jumpValue{0.0f};
    float groundValue{0.0f};

    Vector2 prevPosition;

public:
    Player(Texture2D playertx, int numFrames, Vector2 pos, Color c);
    Player();

    void Init(int playerSelected);
    void Update();
    void Jump();
    void JumpTrampoline(float groundf);
    void Die();
    void UndoMove();
    void ResetPosition();
    void Unload();

    bool GetIsPlayerOnGround() { return isPlayerOnGround; }
    void SetIsPlayerOnGround(bool isOnGround) { isPlayerOnGround = isOnGround; }
    bool GetIsPlayerOnPlatform() { return isPlayerOnPlatform; }
    void SetIsPlayerOnPlatform(bool isOnPlatform) { isPlayerOnPlatform = isOnPlatform; }
};

#endif