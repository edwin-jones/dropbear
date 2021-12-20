#ifndef ACTOR_INCLUDE
#define ACTOR_INCLUDE

#include <gb/gb.h>

struct Actor
{
   UINT8 x;
   UINT8 y;
   UINT8 width;
   UINT8 height;
};

void ConfigureActor(struct Actor* actor, UINT8 x, UINT8 y, UINT8 width, UINT8 height);
BOOLEAN AreColliding(struct Actor* a, struct Actor* b);

#endif