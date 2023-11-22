#ifndef ITEM_H
#define ITEM_H

#include "raylib.h"
#include "Character.h"

class Item : public Character
{

public:
    Item(Texture2D itemtx, int numFrames, Vector2 pos, Color c, Texture2D disappearChar);
};

#endif