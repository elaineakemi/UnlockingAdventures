#ifndef ITEM_H
#define ITEM_H

#include "raylib.h"

class Item
{
private:
    Texture2D itemTexture;
    int numberFrames; // Number of frames in the texture
    Vector2 position;
    Color color;

    // Used to change item frames within texture
    Rectangle frameRec;
    int currentFrame;
    int framesCounter;
    int framesSpeed;

    Texture2D collectedTexture; // To change texture when item is collected
    bool isCollected;

public:
    Item(Texture2D itemtx, int numFrames, Vector2 pos, Color c);

    void Draw();

    Vector2 GetPosition() const;

    Rectangle GetPositionRec() const;

    void Collect();
};

#endif