#include <gb/gb.h>
#include <gb/console.h>
#include <stdio.h>
#include <rand.h>

#include "../assets/background/tilemap.c"
#include "../assets/background/tileset.c"
#include "../assets/logo/tilemapset.c"
#include "../assets/player/tilemapset.c"
#include "../assets/items/coin.c"
#include "../include/settings.h"
#include "../include/text.h"
#include "../include/actor.h"
#include "../include/sound.h"

UINT8 score = 0;
UINT16 game_time = 0;
UINT8 time = 0;
UINT8 hundreds = 0;
UINT8 tens = 0;
UINT8 units = 0;

UBYTE hud_values_tile_map[3];

struct Actor player;
struct Actor coins[COIN_COUNT];

void reset_coin_position(struct Actor* coin)
{
    static UINT8 random;
    random = (UINT8)rand();

    coin->x = (random % 152) + 8;
    coin->y = (random % 70) + 170;
}

void set_hud_text(UBYTE* data)
{
    set_win_tiles(0, 0, 20, 1, data);
}

void check_input()
{
    // LEFT
    if (joypad() & J_LEFT)
    {
        player.x -= MOVE_SPEED;
    }

    // RIGHT
    if (joypad() & J_RIGHT)
    {
        player.x += MOVE_SPEED;
    }
}

void update_player()
{
    UINT8 tileCounter = 0;

    for (UINT8 y = 0; y < BEAR_TILE_MAP_WIDTH; y++)
    {
        UINT8 yOffset = y * TILE_HEIGHT;

        for (UINT8 x = 0; x < BEAR_TILE_MAP_HEIGHT; x++)
        {
            UINT8 xOffset = x * TILE_WIDTH;
            move_sprite(tileCounter++, player.x + xOffset, player.y + yOffset);
        }
    }
}

void update_coins()
{
    for (UINT8 i = 0; i < COIN_COUNT; i++)
    {
        coins[i].y -= COIN_SPEED;
        move_sprite(BEAR_TILE_MAP_SIZE + i, coins[i].x, coins[i].y);

        if (AreColliding(&coins[i], &player))
        {
            score++;
            play_coin_sound();
            reset_coin_position(&coins[i]);
        }
    }
}

void show_splash_screen()
{
    HIDE_SPRITES;
    HIDE_BKG;
    HIDE_WIN;

    cls();
    printf(" "); //printf loads the font and MUST be called first or tile maps break.
    move_bkg(-5, 0);

    set_bkg_data(128, LOGO_TILE_SET_COUNT, logo_tile_data);
    set_bkg_tiles(0, 7, LOGO_TILE_MAP_WIDTH, LOGO_TILE_MAP_HEIGHT, logo_tile_map);

    SHOW_BKG;

    gotoxy(0, 15);
    printf("   PRESS  START    ");

    waitpadup();
    waitpad(J_START);
    play_start_sound();
}

void show_game_screen()
{
    HIDE_BKG;
    HIDE_WIN;
    HIDE_SPRITES;

    score = 0;
    game_time = 0;
    time = GAME_LENGTH_SECONDS;

    move_win(HUD_X, HUD_Y);
    set_hud_text(hud_tile_map);

    // Load tileset into background memory
    set_bkg_data(128, BACKGROUND_TILE_SET_COUNT, background_tile_set);

    // Load tile map into memory.
    set_bkg_tiles(0, 0, BACKGROUND_TILE_MAP_WIDTH, BACKGROUND_TILE_MAP_HEIGHT, background_tile_map);

    // Load the the 'sprites' tiles into sprite memory
    set_sprite_data(0, BEAR_TILE_SET_COUNT, bear_tile_set);
    set_sprite_data(BEAR_TILE_SET_COUNT, 1, coins_tile_set);

    // Set the first movable sprite (0) to be the first tile in the sprite memory (0)
    for (UINT8 i = 0; i < BEAR_TILE_MAP_SIZE; i++)
    {
        set_sprite_tile(i, bear_tile_map[i]);
    }

    for (UINT8 i = 0; i < COIN_COUNT; i++)
    {
        set_sprite_tile(i + BEAR_TILE_MAP_SIZE, 0x0E);
    }

    ConfigureActor(&player, 60, 40, 40, 40);

    for (UINT8 i = 0; i < COIN_COUNT; i++)
    {
        ConfigureActor(&coins[i], 0, 0, 8, 8);
        reset_coin_position(&coins[i]);
    }

    SHOW_BKG;
    SHOW_WIN;
    SHOW_SPRITES;
}

void show_game_over_screen()
{
    HIDE_SPRITES;
    cls();
    move_bkg(0, 0);
    gotoxy(0, 5);
    printf("     GAME  OVER     ");
    gotoxy(0, 9);
    printf("    PRESS  START    ");

    waitpadup();
    waitpad(J_START);
}

void update_hud()
{
    time = GAME_LENGTH_SECONDS - (game_time / 60);
    units = time % 10;
    tens = time / 10;
    hundreds = time  / 100;

    hud_values_tile_map[0] = 0x10 + hundreds;
    hud_values_tile_map[1] = 0x10 + tens;
    hud_values_tile_map[2] = 0x10 + units;
    set_win_tiles(6, 0, 3, 1, hud_values_tile_map);

    units = score % 10;
    tens = score / 10;
    hundreds = score / 100;

    hud_values_tile_map[0] = 0x10 + hundreds;
    hud_values_tile_map[1] = 0x10 + tens;
    hud_values_tile_map[2] = 0x10 + units;
    set_win_tiles(16, 0, 3, 1, hud_values_tile_map);
}

void main()
{
    // be very careful about turning the display OFF, this can fry physical hardware at certain times.
    DISPLAY_ON;
    init_sound();

    while (1)
    {
        show_splash_screen();
        initrand(DIV_REG);
        show_game_screen();

        while (time > 0)
        {
            check_input();
            update_player();
            update_coins();
            scroll_bkg(0, FALL_SPEED);
            update_hud();

            game_time++;

            // Wait until VBLANK to avoid corrupting memory and keep time.
            wait_vbl_done();
        }

        show_game_over_screen();
    }
}