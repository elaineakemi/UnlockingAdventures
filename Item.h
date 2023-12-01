#ifndef ITEM_H
#define ITEM_H

#include "raylib.h"
#include "Character.h"
#include "Assets.h"

// Global variables
extern int score;

// Global assets
extern ItemTextures itemTextures;
extern GameSounds gameSounds;

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
    bool isActive{false};
    bool isExploding{false};
    bool isOnGround{false};
    int framesExploding{6};
    int waitFramesExplosion{0};

    Vector2 GetRandomPosition();

public:
    // Constructors
    Item() = default;
    Item(TextureFrames itemtx, Vector2 pos);
    Item(TextureFrames itemtx, Vector2 pos, TextureFrames collecttx);

    // Getters and Setters
    bool GetIsExploding() { return isExploding; }
    void SetIsExploding(bool value) { isExploding = value; }

    void Collect();
    void RenderBomb();
    void ActivateBomb();
};

#endif