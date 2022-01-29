#include <gb/gb.h>
#include <gbdk/console.h>
#include <stdio.h>


#define LOGO_TILE_MAP_SIZE 0x39
#define LOGO_TILE_MAP_WIDTH 0x13
#define LOGO_TILE_MAP_HEIGHT 0x03

#define LOGO_TILE_SET_SIZE 0x0350
#define LOGO_TILE_SET_COUNT 0x35

// ALL CHARS NEED 0x80 OFFSET TO AVOID CLASH WITH FONT MEMORY.
const unsigned char logo_tile_map[] ={
  0x00+0x80,0x01+0x80,0x02+0x80,0x03+0x80,0x04+0x80,0x05+0x80,0x06+0x80,0x00+0x80,0x07+0x80,0x08+0x80,0x09+0x80,0x0A+0x80,0x00+0x80,0x0B+0x80,0x0C+0x80,0x0D+0x80,
  0x0E+0x80,0x0F+0x80,0x10+0x80,0x11+0x80,0x12+0x80,0x13+0x80,0x14+0x80,0x15+0x80,0x16+0x80,0x17+0x80,0x18+0x80,0x19+0x80,0x1A+0x80,0x1B+0x80,0x1C+0x80,0x1D+0x80,
  0x1E+0x80,0x1F+0x80,0x20+0x80,0x21+0x80,0x22+0x80,0x23+0x80,0x24+0x80,0x25+0x80,0x26+0x80,0x27+0x80,0x28+0x80,0x24+0x80,0x29+0x80,0x2A+0x80,0x2B+0x80,0x2C+0x80,
  0x2D+0x80,0x2E+0x80,0x24+0x80,0x2F+0x80,0x30+0x80,0x31+0x80,0x32+0x80,0x33+0x80,0x34+0x80
};

const unsigned char logo_tile_data[] ={
  0xFF,0xFF,0xFF,0xFF,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC7,0xC7,0xC7,0xC7,0xC7,0xC7,
  0xC0,0xC0,0xC0,0xC0,0xF0,0xF0,0x38,0x38,0x38,0x38,0x0E,0x0E,0xC6,0xC6,0xC6,0xC6,
  0x3F,0x3F,0x3F,0x3F,0x20,0x20,0x20,0x20,0x20,0x20,0x21,0x21,0x21,0x21,0x21,0x21,
  0xFE,0xFE,0xFE,0xFE,0x07,0x07,0x01,0x01,0x01,0x01,0xF8,0xF8,0xF8,0xF8,0xF8,0xF8,
  0x00,0x00,0x00,0x00,0x80,0x80,0xC3,0xC3,0xC3,0xC3,0x47,0x47,0x47,0x47,0x44,0x44,
  0x3F,0x3F,0x3F,0x3F,0xF0,0xF0,0xC0,0xC0,0xC0,0xC0,0x0E,0x0E,0x1E,0x1E,0x3F,0x3F,
  0xC0,0xC0,0xC0,0xC0,0x70,0x70,0x3C,0x3C,0x3C,0x3C,0x0C,0x0C,0x0C,0x0C,0x8C,0x8C,
  0xF0,0xF0,0xF0,0xF0,0x38,0x38,0x0E,0x0E,0x0E,0x0E,0xC6,0xC6,0xC6,0xC6,0xC6,0xC6,
  0x07,0x07,0x07,0x07,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,
  0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x3E,0x3E,0x3E,0x3E,0x3E,0x3E,
  0xE0,0xE0,0xE0,0xE0,0x70,0x70,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x70,0x70,
  0xFE,0xFE,0xFE,0xFE,0x02,0x02,0x02,0x02,0x02,0x02,0xFE,0xFE,0xFC,0xFC,0xFC,0xFC,
  0x01,0x01,0x01,0x01,0x01,0x01,0x07,0x07,0x07,0x07,0x06,0x06,0x06,0x06,0x0E,0x0E,
  0xFE,0xFE,0xFE,0xFE,0x83,0x83,0x81,0x81,0x81,0x81,0x00,0x00,0x00,0x00,0x7C,0x7C,
  0x07,0x07,0x07,0x07,0x86,0x86,0xE6,0xE6,0xE6,0xE6,0x66,0x66,0x66,0x66,0x66,0x66,
  0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,
  0xE0,0xE0,0xE0,0xE0,0x70,0x70,0x1C,0x1C,0x1C,0x1C,0x8C,0x8C,0x8C,0x8C,0x8C,0x8C,
  0xC7,0xC7,0xC7,0xC7,0xC7,0xC7,0xC7,0xC7,0xC6,0xC6,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,
  0xC6,0xC6,0xC6,0xC6,0x06,0x06,0x06,0x06,0x0E,0x0E,0x3E,0x3E,0x3E,0x3E,0xF8,0xF8,
  0x21,0x21,0x21,0x21,0x20,0x20,0x20,0x20,0x21,0x21,0x21,0x21,0x21,0x21,0x21,0x21,
  0xF1,0xF1,0xF1,0xF1,0x07,0x07,0x07,0x07,0xC1,0xC1,0xF0,0xF0,0xF0,0xF0,0xF9,0xF9,
  0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0xC4,0x47,0x47,0x47,0x47,0xC7,0xC7,
  0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x0E,0x0E,0x00,0x00,0x00,0x00,0xC0,0xC0,
  0x8C,0x8C,0x8C,0x8C,0x8C,0x8C,0x8C,0x8C,0x0C,0x0C,0x3C,0x3C,0x3C,0x3C,0x7C,0x7C,
  0xC7,0xC7,0xC7,0xC7,0xC0,0xC0,0xC0,0xC0,0xC7,0xC7,0xC7,0xC7,0xC7,0xC7,0xC6,0xC6,
  0xC6,0xC6,0xC6,0xC6,0x0E,0x0E,0x0E,0x0E,0xFE,0xFE,0xF8,0xF8,0xF8,0xF8,0x00,0x00,
  0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,
  0x00,0x00,0x00,0x00,0x3E,0x3E,0x3E,0x3E,0x3E,0x3E,0x00,0x00,0x00,0x00,0x00,0x00,
  0x1C,0x1C,0x1C,0x1C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x1C,0x1C,0x1C,0x1C,0x7C,0x7C,
  0xC0,0xC0,0xC0,0xC0,0xC7,0xC7,0xC7,0xC7,0xC7,0xC7,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,
  0x0C,0x0C,0x0C,0x0C,0xFC,0xFC,0xFC,0xFC,0xFE,0xFE,0x02,0x02,0x02,0x02,0x02,0x02,
  0x08,0x08,0x08,0x08,0x38,0x38,0x38,0x38,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,
  0x7C,0x7C,0x7C,0x7C,0x7C,0x7C,0x7C,0x7C,0x00,0x00,0x70,0x70,0x70,0x70,0x70,0x70,
  0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,
  0x3E,0x3E,0x3E,0x3E,0x00,0x00,0x00,0x00,0x3C,0x3C,0x3E,0x3E,0x3E,0x3E,0x3F,0x3F,
  0x1C,0x1C,0x1C,0x1C,0x7C,0x7C,0x7C,0x7C,0x1C,0x1C,0x0C,0x0C,0x0C,0x0C,0x9C,0x9C,
  0xC0,0xC0,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0xF8,0xF8,0xF0,0xF0,0xC0,0xC0,0xC0,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x21,0x21,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0xF9,0xF9,0x3F,0x3F,0x0F,0x0F,0x0F,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0xC7,0xC7,0xC3,0xC3,0x80,0x80,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x7C,0x7C,0xF0,0xF0,0xC0,0xC0,0xC0,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0xC6,0xC6,0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x06,0x06,0x07,0x07,0x07,0x07,0x07,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x7C,0x7C,0xF0,0xF0,0xE0,0xE0,0xE0,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x02,0x02,0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x30,0x30,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x70,0x70,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x66,0x66,0xE7,0xE7,0xE7,0xE7,0xE7,0xE7,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x3F,0x3F,0xF3,0xF3,0xF1,0xF1,0xF1,0xF1,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x9C,0x9C,0xFC,0xFC,0xF0,0xF0,0xF0,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

#define BACKGROUND_TILE_SET_COUNT 2

unsigned char background_tile_set[] =
{
  0x10,0x00,0x10,0x00,0x10,0x00,0x10,0x00,
  0x10,0x00,0x10,0x00,0x10,0x00,0x10,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

#define BACKGROUND_TILE_MAP_WIDTH 20
#define BACKGROUND_TILE_MAP_HEIGHT 32
#define BACKGROUND_TILE_MAP_BANK 0

const unsigned char background_tile_map[] =
{
  0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x00+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,
  0x01+0x80,0x01+0x80,0x00+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,
  0x01+0x80,0x00+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x00+0x80,0x01+0x80,
  0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x00+0x80,0x01+0x80,0x01+0x80,0x00+0x80,0x01+0x80,
  0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,
  0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,
  0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,
  0x01+0x80,0x01+0x80,0x00+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,
  0x01+0x80,0x01+0x80,0x01+0x80,0x00+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,
  0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x00+0x80,0x01+0x80,0x01+0x80,0x01+0x80,
  0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x00+0x80,0x01+0x80,0x01+0x80,0x01+0x80,
  0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,
  0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,
  0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x00+0x80,
  0x01+0x80,0x00+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,
  0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,
  0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x00+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x00+0x80,
  0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x00+0x80,0x01+0x80,0x01+0x80,
  0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,
  0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,
  0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,
  0x01+0x80,0x01+0x80,0x01+0x80,0x00+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,
  0x01+0x80,0x00+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,
  0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,
  0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x00+0x80,0x01+0x80,
  0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x00+0x80,0x01+0x80,0x01+0x80,
  0x01+0x80,0x01+0x80,0x01+0x80,0x00+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,
  0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,
  0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,
  0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,
  0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,
  0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,
  0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x00+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,
  0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x00+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,
  0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x00+0x80,
  0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,
  0x01+0x80,0x01+0x80,0x00+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,
  0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,
  0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,
  0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x00+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,
  0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x00+0x80,
  0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,
  0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,
  0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,
  0x01+0x80,0x01+0x80,0x01+0x80,0x00+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,
  0x01+0x80,0x01+0x80,0x01+0x80,0x00+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,
  0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,
  0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,
  0x00+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,
  0x00+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,
  0x01+0x80,0x01+0x80,0x01+0x80,0x00+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,
  0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,
  0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,
  0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x00+0x80,0x01+0x80,0x01+0x80,
  0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,
  0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,
  0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,
  0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,
  0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x00+0x80,0x01+0x80,0x01+0x80,0x01+0x80,
  0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x00+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,
  0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x00+0x80,
  0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,
  0x01+0x80,0x01+0x80,0x00+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,
  0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x01+0x80,0x00+0x80,0x01+0x80,0x01+0x80
};


#define BEAR_TILE_MAP_SIZE 0x10
#define BEAR_TILE_MAP_WIDTH 0x04
#define BEAR_TILE_MAP_HEIGHT 0x04

#define BEAR_TILE_SET_SIZE 0xE0
#define BEAR_TILE_SET_COUNT 0x0E

const unsigned char bear_tile_map[] ={
  0x00,0x01,0x02,0x03,0x04,0x05,0x05,0x06,0x07,0x08,0x09,0x07,0x0A,0x0B,0x0C,0x0D
};

const unsigned char bear_tile_set[] ={
  0x00,0x0F,0x00,0x0F,0x00,0x0F,0x00,0x0F,0x0F,0xF0,0x0F,0xF0,0x00,0xFF,0x00,0xFF,
  0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0xC0,0x3C,0xC0,0x3C,0x00,0xFF,0x00,0xFF,
  0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x03,0x3C,0x03,0x3C,0x00,0xFF,0x00,0xFF,
  0x00,0xF0,0x00,0xF0,0x00,0xF0,0x00,0xF0,0xF0,0x0F,0xF0,0x0F,0x00,0xFF,0x00,0xFF,
  0x00,0xFF,0x00,0xFF,0x00,0x0F,0x00,0x0F,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,
  0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x3C,0xFF,0x3C,0xFF,0x3C,0xFF,0x3C,0xFF,
  0x00,0xFF,0x00,0xFF,0x00,0xF0,0x00,0xF0,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,
  0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,
  0x3C,0xFF,0x3C,0xFF,0x3C,0xFF,0x3C,0xFF,0x00,0xFF,0x00,0xFF,0x3F,0xCF,0x3F,0xCF,
  0x3C,0xFF,0x3C,0xFF,0x3C,0xFF,0x3C,0xFF,0x00,0xFF,0x00,0xFF,0xFC,0xF3,0xFC,0xF3,
  0x00,0xFF,0x00,0xFF,0x00,0x0F,0x00,0x0F,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,
  0x3F,0xCF,0x3F,0xCF,0x3F,0xC0,0x3F,0xC0,0x3F,0xC0,0x3F,0xC0,0x00,0xFF,0x00,0xFF,
  0xFC,0xF3,0xFC,0xF3,0xFC,0x03,0xFC,0x03,0xFC,0x03,0xFC,0x03,0x00,0xFF,0x00,0xFF,
  0x00,0xFF,0x00,0xFF,0x00,0xF0,0x00,0xF0,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xC0
};

unsigned char coins_tile_map[] =
{
  129,
};

/* Start of tile array. */
unsigned char coins_tile_set[] =
{
  0x00,0x7E,0x24,0xFF,0x28,0xFF,0x30,0xFF,
  0x30,0xFF,0x28,0xFF,0x24,0xFF,0x00,0x7E,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

UINT16 game_time = 600;
UINT8 player_x = 72;
UINT8 player_y = 32;
UINT8 coin_a_x = 16;
UINT8 coin_a_y = 0;
UINT8 coin_b_x = 32;
UINT8 coin_b_y = 0;
UINT8 coin_c_x = 64;
UINT8 coin_c_y = 0;

void main()
{
    start:
    // use macros to hide screen all sprites, background layer and the window layer.
    HIDE_SPRITES;
    HIDE_BKG;
    HIDE_WIN;

    cls();
    printf(" "); //printf loads the font and MUST be called first or tile maps break.
    move_bkg(-5, 0);

    // load the logo into tile memory
    set_bkg_data(128, LOGO_TILE_SET_COUNT, logo_tile_data);

    // set the background tiles to the logo we just loaded
    set_bkg_tiles(0, 7, LOGO_TILE_MAP_WIDTH, LOGO_TILE_MAP_HEIGHT, logo_tile_map);

    // show the background layer
    SHOW_BKG;

    // move the text cursor to a lower row and print
    gotoxy(0, 15);
    printf("   PRESS  START    ");

    waitpadup();
    waitpad(J_START);
    cls();

    // set game timer
    game_time = 60 * 10;

    // Load tileset into background memory
    set_bkg_data(128, BACKGROUND_TILE_SET_COUNT, background_tile_set);

    // Load tile map into memory.
    set_bkg_tiles(0, 0, BACKGROUND_TILE_MAP_WIDTH, BACKGROUND_TILE_MAP_HEIGHT, background_tile_map);

    // Load the the 'sprites' tiles into sprite memory
    set_sprite_data(0, BEAR_TILE_SET_COUNT, bear_tile_set);
    set_sprite_data(BEAR_TILE_SET_COUNT, 1, coins_tile_set);

    // Set the bear sprite to the correct sprite tiles.
    for (UINT8 i = 0; i < BEAR_TILE_MAP_SIZE; i++)
    {
        set_sprite_tile(i, bear_tile_map[i]);
    }

    // set the coin sprites to load in memory after the bear sprite.
    for (UINT8 i = 0; i < 3; i++)
    {
        set_sprite_tile(i + BEAR_TILE_MAP_SIZE, 0x0E);
    }

    SHOW_SPRITES;

    while(game_time)
    {
       // scroll the background
      scroll_bkg(0, 3);

      UINT8 tileCounter = 0;

      // move player
      for (UINT8 y = 0; y < BEAR_TILE_MAP_WIDTH; y++)
      {
          UINT8 yOffset = y * 8;

          for (UINT8 x = 0; x < BEAR_TILE_MAP_HEIGHT; x++)
          {
              UINT8 xOffset = x * 8;
              move_sprite(tileCounter++, player_x + xOffset, player_y + yOffset);
          }
      }

      // move coins
      coin_a_y -= 1;
      coin_b_y -= 1;
      coin_c_y -= 1;
      move_sprite(BEAR_TILE_MAP_SIZE + 0, coin_a_x, coin_a_y);
      move_sprite(BEAR_TILE_MAP_SIZE + 1, coin_b_x, coin_b_y);
      move_sprite(BEAR_TILE_MAP_SIZE + 2, coin_c_x, coin_c_y);

      // update input
      // LEFT
      if (joypad() & J_LEFT)
      {
          player_x -= 2;
      }

      // RIGHT
      if (joypad() & J_RIGHT)
      {
          player_x += 2;
      }

      //decrement the game timer
      game_time--;

      // Wait until VBLANK to avoid corrupting memory and keep time
      wait_vbl_done();
    }

     //jump back to the start of the program
    goto start;
}