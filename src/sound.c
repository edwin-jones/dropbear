#include "../include/sound.h"

//TODO properly document sound registers etc.


void init_sound()
{
     // these registers must be in this specific order!
    NR52_REG = 0x80; // is 1000 0000 in binary and turns on sound
    NR50_REG = 0x77; // sets the volume for both left and right channel just set to max 0x77
    NR51_REG = 0xFF; // is 1111 1111 in binary, select which chanels we want to use in this case all of them. One bit for the L one bit for the R of all four channels
}

void play_coin_sound()
{
    NR21_REG = 0x80;
    NR22_REG = 0x73;
    NR23_REG = 0x9F;
    NR24_REG = 0xC7;
}


void play_start_sound()
{
    NR10_REG = 0x34;
    NR11_REG = 0x80;
    NR12_REG = 0xF0;
    NR13_REG = 0x0A;
    NR14_REG = 0xC6;
}