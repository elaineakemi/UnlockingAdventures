#ifndef CHARACTER_H
#define CHARACTER_H

#include "raylib.h"
#include "Consts.h"

class Character
{
private:
    bool isAlive{true};
    int renderDied = 5; // To render the disappearing texture
    bool isDisappearAfterCollect{true};
    bool isFlipTexture{false}; // To flip texture when walking in opposite direction

public:
    Texture2D texture;
    int numberFrames; // Number of frames in the texture
    Vector2 position;

    // Used to change frames within texture
    Rectangle frameRec;
    int currentFrame;
    int framesCounter;

    Texture2D disappearTexture;

    // Constructors
    Character(Texture2D txtr, int numFrames, Vector2 pos, Texture2D disappearChar);
    Character();

    // Getters and Setters
    bool GetIsAlive() { return isAlive; }
    void SetIsAlive(bool isCharAlive) { isAlive = isCharAlive; }
    void SetIsDisappearAfterCollect(bool disappear) { isDisappearAfterCollect = disappear; }
    Rectangle GetPositionRec() const;
    void SetTexture(Texture2D txtr) { texture = txtr; }
    void SetFlipTexture(bool value) { isFlipTexture = value; }
    void SetNumFrames(int value) { numberFrames = value; }

    void Render();
    void Restart();
    void Move(Vector2 offset);
};

#endif