#ifndef ITEM_H
#define ITEM_H

#include "raylib.h"
#include "Character.h"
#include "Assets.h"

// Global variables
extern int score;

// Global assets
extern ItemTextures itemTextures;

typedef enum
{
    APPLE,
    CHECKPOINT,
    DOOR,
    BOMB,
    LIFEBAR,
    LIFEBARLIFE,
    CHECKPOINTBAR,
    CHECKPOINTBARCOLLECTED
} ItemType;

class Item : public Character
{
private:
    // Sounds
    Sound appleSound{LoadSound("resources/sounds/apple.wav")};
    Sound bombDropSound{LoadSound("resources/sounds/bomb_drop.wav")};
    Sound bombExplodeSound{LoadSound("resources/sounds/bomb_explode.wav")};

    bool isActive{false};
    bool isExploding{false};
    bool isOnGround{false};
    int framesExploding{6};
    int waitFramesExplosion{0};

    Vector2 GetRandomPosition();

public:
    // Constructors
    Item(TextureFrames itemtx, Vector2 pos, TextureFrames collecttx);
    Item();

    // Getters and Setters
    bool GetIsExploding() { return isExploding; }
    void SetIsExploding(bool value) { isExploding = value; }

    void Collect();
    void RenderBomb();
    void ActivateBomb();
};

#endif