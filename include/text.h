// GBDK's built in printing functions write to the background layer and the first 128 bytes
// of background tile memory. They also appear to alter the backgound tile map in various ways.
// To print a HUD on the window layer that we can keep static even as the background scrolls
// this file defines constants to help print to the window layer correctly.

#ifndef TEXT_INCLUDE
#define TEXT_INCLUDE

#include <gb/gb.h>
#include <gb/font.h>

#define LINE_TILE_COUNT 20

#define CHARACTER_SPACE 0x00
#define CHARACTER_ZERO 0x10
#define CHARACTER_COLON 0x1A
#define CHARACTER_A 0X21
#define CHARACTER_C 0X23
#define CHARACTER_E 0x25
#define CHARACTER_I 0x29
#define CHARACTER_M 0x2D
#define CHARACTER_O 0x2F
#define CHARACTER_P 0x30
#define CHARACTER_S 0x33
#define CHARACTER_R 0x32
#define CHARACTER_T 0x34

#define PRESS_START_TILE_COUNT 11
#define PRESS_START_X 42
#define PRESS_START_Y 120

#define HUD_X 8
#define HUD_Y 136

extern const unsigned char hud_tile_map[LINE_TILE_COUNT];

#endif