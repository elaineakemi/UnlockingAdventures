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
    TextureFrames GetTexture(ItemType type);
    TextureFrames GetKillTexture(ItemType type);

public:
    // Constructors
    Item() = default;
    Item(ItemType type);
    Item(TextureFrames itemtx, Vector2 pos);
    Item(TextureFrames itemtx, Vector2 pos, TextureFrames collecttx);

    // Getters and Setters
    bool GetIsExploding() { return isExploding; }
    void SetIsExploding(bool value) { isExploding = value; }

    void Collect();
    void RenderBomb();
    void ActivateBomb();
    void Restart(Vector2 position);
};

#endif