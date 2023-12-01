#ifndef ITEM_H
#define ITEM_H

#include "raylib.h"
#include "Character.h"

extern int score;

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
    Texture2D initialTexture;
    int initialNumFrames;

public:
    // Constructors
    Item(Texture2D itemtx, int numFrames, Vector2 pos, Texture2D disappearChar);
    Item();

    // Getters and Setters
    bool GetIsExploding() { return isExploding; }
    void SetIsExploding(bool value) { isExploding = value; }

    void Collect();
    void RenderBomb();
    void Activate(Texture2D textureActive, int framesActive);
    Vector2 GetRandomPosition();
};

#endif