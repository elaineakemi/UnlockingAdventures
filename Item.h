#ifndef ITEM_H
#define ITEM_H

#include "raylib.h"
#include "Character.h"

extern int score;

// Items are static - can only be collected and do not move
class Item : public Character
{
private:
    Sound appleSound{LoadSound("resources/sounds/apple.wav")};
    Sound bombDropSound{LoadSound("resources/sounds/bomb_drop.wav")};
    Sound bombExplodeSound{LoadSound("resources/sounds/bomb_explode.wav")};
    bool isActive{false};
    bool isExploding{false};
    bool isOnGround{false};
    int framesExploding{6};
    int waitFramesExplosion{0};
    Texture2D initialTexture;
    int initialNumFrames;

public:
    Item(Texture2D itemtx, int numFrames, Vector2 pos, Color c, Texture2D disappearChar);
    Item();

    void Collect();
    void RenderBomb();
    void Activate(Texture2D textureActive, int framesActive);
    bool GetIsExploding() { return isExploding; }
    void SetIsExploding(bool value) { isExploding = value; }
    Vector2 GetRandomPosition();
};

#endif