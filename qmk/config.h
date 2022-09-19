// Mouse keys
#define MK_3_SPEED // Enable constant cursor speeds
#define MK_MOMENTARY_ACCEL // Enable momentary mode
#define MOUSEKEY_INTERVAL 8

// Tapdance
#define TAPPING_TERM 200

// One Shot
#define ONESHOT_TAP_TOGGLE 3 // Tapping this number of times holds the key until tapped once again.
#define ONESHOT_TIMEOUT 5000 // Time (in ms) before the one shot key is released

// Unicode
#define UNICODE_SELECTED_MODES UC_LNX

// Modtap
#define IGNORE_MOD_TAP_INTERRUPT

// Macros
#define DYNAMIC_MACRO_NO_NESTING // Do not allow one macro to contain another macro

// Optimizations
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#define NO_MUSIC_MODE
#define LAYER_STATE_16BIT // < 16 layers.

// Stenography
#define STENO_COMBINEDMAP