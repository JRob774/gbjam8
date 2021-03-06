/*////////////////////////////////////////////////////////////////////////////*/

#define SCREEN_WIDTH        0xA0   /* (160) Width of the screen in pixels.    */
#define SCREEN_HEIGHT       0x90   /* (144) Height of the screen in pixels.   */

#define SCREEN_TILES_WIDTH  0x14   /* ( 20) Width of the screen in tiles.     */
#define SCREEN_TILES_HEIGHT 0x12   /* ( 18) Height of the screen in tiles.    */

#define TILE_WIDTH          0x08   /* (  8) Width of a tile in pixels.        */
#define TILE_HEIGHT         0x08   /* (  8) Height of a tile in pixels.       */

#define SPRITE_X_OFFSET     0x08   /* (  8) Sprite X offset in pixels.        */
#define SPRITE_Y_OFFSET     0x10   /* ( 16) Sprite Y offset in pixels.        */

#define BOOL                BOOLEAN
#define VOID                void

#define  U8                 UINT8
#define U16                 UINT16
#define U32                 UINT32
#define  S8                 INT8
#define S16                 INT16
#define S32                 INT32

#define INTERNAL            static
#define GLOBAL              static

#define DIR_U               0x01   /* Direction flag to represet up.          */
#define DIR_R               0x02   /* Direction flag to represet right.       */
#define DIR_D               0x04   /* Direction flag to represet down.        */
#define DIR_L               0x08   /* Direction flag to represet left.        */

#define BKG_PAL0             BGP_REG
#define SPR_PAL0            OBP0_REG
#define SPR_PAL1            OBP1_REG

#define SET_SPR_DATA(name) set_sprite_data(name##_OFFSET, name##_LENGTH,        name)
#define SET_BKG_DATA(name) set_bkg_data   (name##_OFFSET, name##_LENGTH,        name)
#define SET_MAP_DATA(name) set_bkg_tiles  (name##_X,name##_Y,name##_W,name##_H, name)

#define    SET_FLAGS(x, flags) ((x) |=  (flags))
#define  UNSET_FLAGS(x, flags) ((x) &= ~(flags))
#define TOGGLE_FLAGS(x, flags) ((x) ^=  (flags))

#define WAIT(time)                      \
do                                      \
{                                       \
U8 _wait_;                              \
for (_wait_=0; _wait_<time; ++_wait_) { \
    wait_vbl_done();                    \
}                                       \
}                                       \
while (0)

#define CHECK_COLLISION(a,b)                                                                                       \
((((a->x+a->bounds.x+a->bounds.w)>=(b->x+b->bounds.x)) && ((b->x+b->bounds.x+b->bounds.w)>=(a->x+a->bounds.x))) && \
 (((a->y+a->bounds.y+a->bounds.h)>=(b->y+b->bounds.y)) && ((b->y+b->bounds.y+b->bounds.h)>=(a->y+a->bounds.y))))

#if DEBUG_MODE /* ----------------------------------------------------------- */

/* Some debugging utilities for the BGB emulator if we're in DEBUG_MODE. */

#include <gb/bgb_emu.h>
#include <stdio.h>

#ifndef DEBUG_BUFFER_SIZE
#define DEBUG_BUFFER_SIZE 512
#endif

GLOBAL char debug_buffer[DEBUG_BUFFER_SIZE];

#if !DEBUG_NO_PROFILE
#define DEBUG_PROFILE_BEGIN(msg) BGB_PROFILE_BEGIN(msg)
#define DEBUG_PROFILE_END(  msg) BGB_PROFILE_END  (msg)
#else
#define DEBUG_PROFILE_BEGIN(msg)
#define DEBUG_PROFILE_END(  msg)
#endif
#define DEBUG_LOG_MESSAGE(  ...) BGB_MESSAGE_FMT  (debug_buffer, __VA_ARGS__)

#else

#define DEBUG_PROFILE_BEGIN(msg)
#define DEBUG_PROFILE_END(  msg)
#define DEBUG_LOG_MESSAGE(  ...)

#endif  /* ------------------------------------------------------------------ */

/*////////////////////////////////////////////////////////////////////////////*/
