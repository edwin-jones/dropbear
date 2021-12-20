#include "../include/actor.h"

void ConfigureActor(struct Actor* actor, UINT8 x, UINT8 y, UINT8 width, UINT8 height)
{
   actor->x = x;
   actor->y = y;
   actor->width = width;
   actor->height = height;
}

BOOLEAN AreColliding(struct Actor* a, struct Actor* b)
{
   static BOOLEAN a_inside_b;
   static BOOLEAN b_inside_a;

   a_inside_b = a->x >= b->x && a->x <= b->x + b->width && a->y <= b->y + b->height && a->y >= b->y;
   b_inside_a = b->x >= a->x && b->x <= a->x + a->width && b->y <= a->y + a->height && b->y >= a->y;

   return a_inside_b | b_inside_a;
}