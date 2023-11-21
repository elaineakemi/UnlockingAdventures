#ifndef ITEM_H
#define ITEM_H

#include "raylib.h"
#include "Character.h"

class Item : public Character
{
private:
    Texture2D collectedTexture; // To change texture when item is collected
    bool isCollected;

public:
    Item(Texture2D itemtx, int numFrames, Vector2 pos, Color c);

    void Render();

    void Collect();
};

#endif