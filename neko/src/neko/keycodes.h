#pragma once
/* Printable keys */
#define NEKO_KEY_SPACE              32
#define NEKO_KEY_APOSTROPHE         39  /* ' */
#define NEKO_KEY_COMMA              44  /* , */
#define NEKO_KEY_MINUS              45  /* - */
#define NEKO_KEY_PERIOD             46  /* . */
#define NEKO_KEY_SLASH              47  /* / */
#define NEKO_KEY_0                  48
#define NEKO_KEY_1                  49
#define NEKO_KEY_2                  50
#define NEKO_KEY_3                  51
#define NEKO_KEY_4                  52
#define NEKO_KEY_5                  53
#define NEKO_KEY_6                  54
#define NEKO_KEY_7                  55
#define NEKO_KEY_8                  56
#define NEKO_KEY_9                  57
#define NEKO_KEY_SEMICOLON          59  /* ; */
#define NEKO_KEY_EQUAL              61  /* = */
#define NEKO_KEY_A                  65
#define NEKO_KEY_B                  66
#define NEKO_KEY_C                  67
#define NEKO_KEY_D                  68
#define NEKO_KEY_E                  69
#define NEKO_KEY_F                  70
#define NEKO_KEY_G                  71
#define NEKO_KEY_H                  72
#define NEKO_KEY_I                  73
#define NEKO_KEY_J                  74
#define NEKO_KEY_K                  75
#define NEKO_KEY_L                  76
#define NEKO_KEY_M                  77
#define NEKO_KEY_N                  78
#define NEKO_KEY_O                  79
#define NEKO_KEY_P                  80
#define NEKO_KEY_Q                  81
#define NEKO_KEY_R                  82
#define NEKO_KEY_S                  83
#define NEKO_KEY_T                  84
#define NEKO_KEY_U                  85
#define NEKO_KEY_V                  86
#define NEKO_KEY_W                  87
#define NEKO_KEY_X                  88
#define NEKO_KEY_Y                  89
#define NEKO_KEY_Z                  90
#define NEKO_KEY_LEFT_BRACKET       91  /* [ */
#define NEKO_KEY_BACKSLASH          92  /* \ */
#define NEKO_KEY_RIGHT_BRACKET      93  /* ] */
#define NEKO_KEY_GRAVE_ACCENT       96  /* ` */
#define NEKO_KEY_WORLD_1            161 /* non-US #1 */
#define NEKO_KEY_WORLD_2            162 /* non-US #2 */

/* Function keys */
#define NEKO_KEY_ESCAPE             256
#define NEKO_KEY_ENTER              257
#define NEKO_KEY_TAB                258
#define NEKO_KEY_BACKSPACE          259
#define NEKO_KEY_INSERT             260
#define NEKO_KEY_DELETE             261
#define NEKO_KEY_RIGHT              262
#define NEKO_KEY_LEFT               263
#define NEKO_KEY_DOWN               264
#define NEKO_KEY_UP                 265
#define NEKO_KEY_PAGE_UP            266
#define NEKO_KEY_PAGE_DOWN          267
#define NEKO_KEY_HOME               268
#define NEKO_KEY_END                269
#define NEKO_KEY_CAPS_LOCK          280
#define NEKO_KEY_SCROLL_LOCK        281
#define NEKO_KEY_NUM_LOCK           282
#define NEKO_KEY_PRINT_SCREEN       283
#define NEKO_KEY_PAUSE              284
#define NEKO_KEY_F1                 290
#define NEKO_KEY_F2                 291
#define NEKO_KEY_F3                 292
#define NEKO_KEY_F4                 293
#define NEKO_KEY_F5                 294
#define NEKO_KEY_F6                 295
#define NEKO_KEY_F7                 296
#define NEKO_KEY_F8                 297
#define NEKO_KEY_F9                 298
#define NEKO_KEY_F10                299
#define NEKO_KEY_F11                300
#define NEKO_KEY_F12                301
#define NEKO_KEY_F13                302
#define NEKO_KEY_F14                303
#define NEKO_KEY_F15                304
#define NEKO_KEY_F16                305
#define NEKO_KEY_F17                306
#define NEKO_KEY_F18                307
#define NEKO_KEY_F19                308
#define NEKO_KEY_F20                309
#define NEKO_KEY_F21                310
#define NEKO_KEY_F22                311
#define NEKO_KEY_F23                312
#define NEKO_KEY_F24                313
#define NEKO_KEY_F25                314
#define NEKO_KEY_KP_0               320
#define NEKO_KEY_KP_1               321
#define NEKO_KEY_KP_2               322
#define NEKO_KEY_KP_3               323
#define NEKO_KEY_KP_4               324
#define NEKO_KEY_KP_5               325
#define NEKO_KEY_KP_6               326
#define NEKO_KEY_KP_7               327
#define NEKO_KEY_KP_8               328
#define NEKO_KEY_KP_9               329
#define NEKO_KEY_KP_DECIMAL         330
#define NEKO_KEY_KP_DIVIDE          331
#define NEKO_KEY_KP_MULTIPLY        332
#define NEKO_KEY_KP_SUBTRACT        333
#define NEKO_KEY_KP_ADD             334
#define NEKO_KEY_KP_ENTER           335
#define NEKO_KEY_KP_EQUAL           336
#define NEKO_KEY_LEFT_SHIFT         340
#define NEKO_KEY_LEFT_CONTROL       341
#define NEKO_KEY_LEFT_ALT           342
#define NEKO_KEY_LEFT_SUPER         343
#define NEKO_KEY_RIGHT_SHIFT        344
#define NEKO_KEY_RIGHT_CONTROL      345
#define NEKO_KEY_RIGHT_ALT          346
#define NEKO_KEY_RIGHT_SUPER        347
#define NEKO_KEY_MENU               348

#define NEKO_KEY_LAST               NEKO_KEY_MENU

/*! @} */

/*! @defgroup mods Modifier key flags
 *  @brief Modifier key flags.
 *
 *  See [key input](@ref input_key) for how these are used.
 *
 *  @ingroup input
 *  @{ */

/*! @brief If this bit is set one or more Shift keys were held down.
 *
 *  If this bit is set one or more Shift keys were held down.
 */
#define NEKO_MOD_SHIFT           0x0001
/*! @brief If this bit is set one or more Control keys were held down.
 *
 *  If this bit is set one or more Control keys were held down.
 */
#define NEKO_MOD_CONTROL         0x0002
/*! @brief If this bit is set one or more Alt keys were held down.
 *
 *  If this bit is set one or more Alt keys were held down.
 */
#define NEKO_MOD_ALT             0x0004
/*! @brief If this bit is set one or more Super keys were held down.
 *
 *  If this bit is set one or more Super keys were held down.
 */
#define NEKO_MOD_SUPER           0x0008
/*! @brief If this bit is set the Caps Lock key is enabled.
 *
 *  If this bit is set the Caps Lock key is enabled and the @ref
 *  NEKO_LOCK_KEY_MODS input mode is set.
 */
#define NEKO_MOD_CAPS_LOCK       0x0010
/*! @brief If this bit is set the Num Lock key is enabled.
 *
 *  If this bit is set the Num Lock key is enabled and the @ref
 *  NEKO_LOCK_KEY_MODS input mode is set.
 */
#define NEKO_MOD_NUM_LOCK        0x0020
