/*////////////////////////////////////////////////////////////////////////////*/

#define SCREEN_WIDTH        0xA0   /* (160) Width of the screen in pixels.    */
#define SCREEN_HEIGHT       0x90   /* (144) Height of the screen in pixels.   */

#define SCREEN_TILES_WIDTH  0x14   /* ( 20) Width of the screen in tiles.     */
#define SCREEN_TILES_HEIGHT 0x12   /* ( 18) Height of the screen in tiles.    */

#define TILE_WIDTH          0x08   /* (  8) Width of a tile in pixels.        */
#define TILE_HEIGHT         0x08   /* (  8) Height of a tile in pixels.       */

#define BOOL                BOOLEAN

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

GLOBAL U8                   i,j,k; /* General-purpose counter variables.      */

/*////////////////////////////////////////////////////////////////////////////*/

#define   SET_FLAGS(x, flags) ((x) |=  (flags))
#define UNSET_FLAGS(x, flags) ((x) &= ~(flags))

/*////////////////////////////////////////////////////////////////////////////*/