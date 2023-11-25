#ifndef ITEM_H
#define ITEM_H

#include "raylib.h"
#include "Character.h"

// Items are static - can only be collected and do not move
class Item : public Character
{

public:
    Item(Texture2D itemtx, int numFrames, Vector2 pos, Color c, Texture2D disappearChar);
    Item();
};

#endif