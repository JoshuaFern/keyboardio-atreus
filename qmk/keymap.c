//
// Includes
//
#include QMK_KEYBOARD_H

#include "keymap_steno.h"

//
// Defines
//
// Layers
#define MONUM MO(NUMSYM)
#define TGGAME TG(GAME)
#define TGMOUSE TG(MOUSE)
#define TGNUMPA TG(NUMPAD)
#define TGSTENO TG(STENO)
// Tap Dance
#define _F0 TD(TD_F0)
#define _F1 TD(TD_F1)
#define _F2 TD(TD_F2)
#define _F3 TD(TD_F3)
#define _F4 TD(TD_F4)
#define _F5 TD(TD_F5)
#define _F6 TD(TD_F6)
#define _F7 TD(TD_F7)
#define _F8 TD(TD_F8)
#define _F9 TD(TD_F9)
#define _FLSH TD(TD_FLSH)
#define _SYRQ TD(TD_SYRQ)
// One Shot
#define MOS_GUI OSM(MOD_LGUI)
// Mod-Tap
#define Z_SFT MT(MOD_LSFT,KC_Z)
#define SLSH_SFT MT(MOD_RSFT,KC_SLSH)

//
// Enums
//
// Customs
enum custom_keycodes {
    KC_P00 = SAFE_RANGE
};
// Tapdance
enum
{    TD_F0
,    TD_F1
,    TD_F2
,    TD_F3
,    TD_F4
,    TD_F5
,    TD_F6
,    TD_F7
,    TD_F8
,    TD_F9
,    TD_SYRQ
,    TD_FLSH };
// Layers
enum layer_names
{    BASE
,    GAME
,    MOUSE
,    NUMSYM
,    FUN
,    NUMPAD
,    STENO };

//
// Keymaps
//
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
    /*
    Base Layer
	,----------------------------------.              ,----------------------------------.
	| q    | w    | f    | p    | g    |              |    j |    l |    u |    y |    ' |
	|------+------+------+------+------|              |------+------+------+------+------|
	| a    | r    | s    | t    | d    |              |    h |    n |    e |    i |    o |
	|------+------+------+------+------+------.,------+------+------+------+------+------|
	|zshift| x    | c    | v    | b    | GAME || MOUSE|    k |    m |    , |    . |/shift|
	|------+------+------+------+------+------||------+------+------+------+------+------|
	| LCtl | LAlt | LGUI | NUM  | Spc  | PTT  ||  Tab | Bspc | LSFT | FUN  |      |  ENT |
	`-----------------------------------------'`-----------------------------------------'
    */
{ [BASE] = LAYOUT
    ( KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                      KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT
    , KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                      KC_H,    KC_N,    KC_E,    KC_I,    KC_O   
    , Z_SFT,   KC_X,    KC_C,    KC_V,    KC_B,    TGGAME,  TGMOUSE, KC_K,    KC_M,    KC_COMM, KC_DOT,  SLSH_SFT
    , KC_LCTL, KC_LALT, MOS_GUI, MONUM,   KC_SPC,  KC_F13,  KC_TAB,  KC_BSPC, KC_LSFT, MO(FUN), XXXXXXX, KC_ENT  )
    /*
    Gaming Layer
	,----------------------------------.              ,----------------------------------.
	| q    | w    | e    | r    | t    |              |    y |    u |    i |    o |    p |
	|------+------+------+------+------|              |------+------+------+------+------|
	| a    | s    | d    | f    | g    |              |    h |    j |    k |    l |    ; |
	|------+------+------+------+------+------.,------+------+------+------+------+------|
	|zshift| x    | c    | v    | b    | GAME ||      |    n |    m |    , |    . |/shift|
	|------+------+------+------+------+------||------+------+------+------+------+------|
	|      |      |      |      |      |      ||      |      |      |      |      |      |
	`-----------------------------------------'`-----------------------------------------'
    */
, [GAME] = LAYOUT
    ( KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
    , KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
    , Z_SFT,   KC_X,    KC_C,    KC_V,    KC_B,    TGGAME,  _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  SLSH_SFT
    , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ )
    /*
    Number/Symbol Layer
	,----------------------------------.              ,----------------------------------.
	| Esc  | ↑    | ~    | PgUp | Home |              |    [ |    ] |    ; |    - |    = |
	|------+------+------+------+------|              |------+------+------+------+------|
	| ←    | ↓    | →    | PgDn | End  |              |  ins |      |      |      |    \ |
	|------+------+------+------+------+------.,------+------+------+------+------+------|
	| 1    | 2    | 3    | 4    | 5    |      || STENO|    6 |    7 |    8 |    9 |    0 |
	|------+------+------+------+------+------||------+------+------+------+------+------|
	| RCtl | RAlt | RGUI |      |      |      ||      | Del |       |      |      |      |
	`-----------------------------------------'`-----------------------------------------'
    */
, [NUMSYM] = LAYOUT
    ( KC_ESC,  KC_UP,   KC_GRV,  KC_PGUP, KC_HOME,                   KC_LBRC, KC_RBRC, KC_SCLN, KC_MINS, KC_EQL
    , KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_END,                    KC_INS, _______, _______, _______, KC_BSLS
    , KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, TGSTENO, KC_6,    KC_7,    KC_8,    KC_9,    KC_0
    , KC_RCTL, KC_RALT, KC_RGUI, _______, _______, _______, _______, KC_DEL, _______, _______, _______, _______ )
    /*
    Mouse Layer
	,----------------------------------.              ,----------------------------------.
	|      |      |      |      |      |              |MClick|   W↑ |   W← |   M↑ |   W→ |
	|------+------+------+------+------|              |------+------+------+------+------|
	|      |      |      |      |      |              |RClick|LClick|   M← |   M↓ |   M→ |
	|------+------+------+------+------+------.,------+------+------+------+------+------|
	|      |      |      |      |      |      || MOUSE|   M4 |   W↓ |   M5 |   M6 |   M7 |
	|------+------+------+------+------+------||------+------+------+------+------+------|
	|      |      |      |      |      |      || SPD1 | SPD2 |      |      |      |      |
	`-----------------------------------------'`-----------------------------------------'
    */
, [MOUSE] = LAYOUT
    ( _______, _______, _______, _______, _______,                   KC_BTN3, KC_WH_U, KC_WH_L, KC_MS_U, KC_WH_R
    , _______, _______, _______, _______, _______,                   KC_BTN2, KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_R
    , _______, _______, _______, _______, _______, _______, TGMOUSE, KC_BTN4, KC_WH_D, KC_BTN5, KC_BTN6, KC_BTN7
    , _______, _______, _______, _______, _______, _______, KC_ACL1, KC_ACL2, _______, _______, _______, _______ )
    /*
    Function Layer
	,----------------------------------.              ,----------------------------------.
	|      |      |      |      | SYSRQ|              | FLASH|      |      |PauseB|PrintS|
	|------+------+------+------+------|              |------+------+------+------+------|
	|      |      |      |      | MUTE |              |      |  APP | CAPS | SLCK | NLCK |
	|------+------+------+------+------+------.,------+------+------+------+------+------|
	|F1/F11|F2/F12|F3/F13|F4/F14|F5/F15|      ||NUMPAD|F6/F16|F7/F17|F8/F18|F9/F19|F10/20|
	|------+------+------+------+------+------||------+------+------+------+------+------|
	|      |      |      |      |      |      ||      |      |      |      |      |      |
	`-----------------------------------------'`-----------------------------------------'
    */
, [FUN] = LAYOUT
    ( _______, _______, _______, KC_VOLU, _SYRQ,                     _FLSH,   _______, _______, KC_PAUS, KC_PSCR
    , _______, _______, _______, KC_VOLD, KC_MUTE,                   _______, KC_APP, KC_CAPS, KC_SLCK, KC_NLCK
    , _F1,     _F2,     _F3,     _F4,     _F5,     _______, TGNUMPA, _F6,     _F7,    _F8,     _F9,     _F0
    , _______, _______, _______, _______, KC_MPLY, _______, _______, _______, _______, _______, _______, _______ )
    /*
    Template Layer
	,----------------------------------.              ,----------------------------------.
	|      |      |      |      |      |              |    / |    7 |    8 |    9 |    + |
	|------+------+------+------+------|              |------+------+------+------+------|
	|      |      |      |      |      |              |    * |    4 |    5 |    6 |    , |
	|------+------+------+------+------+------.,------+------+------+------+------+------|
	|      |      |      |      |      | NumLk||NUMPAD|    - |    1 |    2 |    3 |    = |
	|------+------+------+------+------+------||------+------+------+------+------+------|
	|      |      |      |      |      |      ||  Tab | Bspc |    0 |   00 |    . |  Ent |
	`-----------------------------------------'`-----------------------------------------'
    */
, [NUMPAD] = LAYOUT
    ( _______, _______, _______, _______, _______,                   KC_PSLS, KC_P7,   KC_P8,   KC_P9,   KC_PPLS
    , _______, _______, _______, _______, _______,                   KC_PAST, KC_P4,   KC_P5,   KC_P6,   KC_PCMM
    , _______, _______, _______, _______, _______, KC_NLCK, TGNUMPA, KC_PMNS, KC_P1,   KC_P2,   KC_P3,   KC_PEQL
    , _______, _______, _______, _______, _______, _______, KC_TAB,  KC_BSPC, KC_P0,   KC_P00,  KC_PDOT, KC_PENT )
    /*
    Stenotype Layer
	,----------------------------------.              ,----------------------------------.
	| S1   | TL   | PL   | HL   | ST1  |              |   FR |   PR |   LR |   TR |   DR |
	|------+------+------+------+------|              |------+------+------+------+------|
	| S2   | KL   | WL   | RL   | ST2  |              |   RR |   BR |   GR |   SR |   ZR |
	|------+------+------+------+------+------.,------+------+------+------+------+------|
	| N1   | N2   | N3   | N4   | N5   |      ||      |   N6 |   N7 |   N8 |   N9 |      |
	|------+------+------+------+------+------||------+------+------+------+------+------|
	|      |      |      | A    | O    | AO   ||   EU |    E |    U |      |      |      |
	`-----------------------------------------'`-----------------------------------------'
    */
, [STENO] = LAYOUT
    ( STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1,                   STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR
    , STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2,                   STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR
    , STN_N1,  STN_N2,  STN_N3,  STN_N4,  STN_N5,  XXX,     TGSTENO, STN_N6,  STN_N7,  STN_N8,  STN_N9,  XXX
    , XXX,     XXX,     XXX,     STN_A,   STN_O,   STN_AO,  STN_EU,  STN_E,   STN_U,   XXX,     XXX,     XXX    )
    /*
    Template Layer
	,----------------------------------.              ,----------------------------------.
	|      |      |      |      |      |              |      |      |      |      |      |
	|------+------+------+------+------|              |------+------+------+------+------|
	|      |      |      |      |      |              |      |      |      |      |      |
	|------+------+------+------+------+------.,------+------+------+------+------+------|
	|      |      |      |      |      |      ||      |      |      |      |      |      |
	|------+------+------+------+------+------||------+------+------+------+------+------|
	|      |      |      |      |      |      ||      |      |      |      |      |      |
	`-----------------------------------------'`-----------------------------------------'
    */
/*, [TEMPLATE] = LAYOUT
    ( _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______
    , _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______
    , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ )    */
};

//
// Tapdance
//
void dance_fun1 (qk_tap_dance_state_t *state, void *user_data) { switch (state->count) { case 1:register_code(KC_F1);break; case 2:register_code(KC_F11);break; case 3:register_code(KC_F21);break; }}
void dance_fun1_reset (qk_tap_dance_state_t *state, void *user_data) { switch (state->count) { case 1:unregister_code(KC_F1);break; case 2:unregister_code(KC_F11);break; case 3:unregister_code(KC_F21);break; }}
void dance_fun2 (qk_tap_dance_state_t *state, void *user_data) { switch (state->count) { case 1:register_code(KC_F2);break; case 2:register_code(KC_F12);break; case 3:register_code(KC_F22);break; }}
void dance_fun2_reset (qk_tap_dance_state_t *state, void *user_data) { switch (state->count) { case 1:unregister_code(KC_F2);break; case 2:unregister_code(KC_F12);break; case 3:unregister_code(KC_F22);break; }}
void dance_fun3 (qk_tap_dance_state_t *state, void *user_data) { switch (state->count) { case 1:register_code(KC_F3);break; case 2:register_code(KC_F13);break; case 3:register_code(KC_F23);break; }}
void dance_fun3_reset (qk_tap_dance_state_t *state, void *user_data) { switch (state->count) { case 1:unregister_code(KC_F3);break; case 2:unregister_code(KC_F13);break; case 3:unregister_code(KC_F23);break; }}
void dance_fun4 (qk_tap_dance_state_t *state, void *user_data) { switch (state->count) { case 1:register_code(KC_F4);break; case 2:register_code(KC_F14);break; case 3:register_code(KC_F24);break; }}
void dance_fun4_reset (qk_tap_dance_state_t *state, void *user_data) { switch (state->count) { case 1:unregister_code(KC_F4);break; case 2:unregister_code(KC_F14);break; case 3:unregister_code(KC_F24);break; }}
// Safety keys, need to be pressed twice to activate anything.
void dance_syrq (qk_tap_dance_state_t *state, void *user_data) { switch (state->count) { case 2:register_code(KC_LALT);register_code(KC_SYRQ);break;}}
void dance_syrq_reset (qk_tap_dance_state_t *state, void *user_data) { switch (state->count) { case 2:unregister_code(KC_LALT);register_code(KC_SYRQ);break;}}
void dance_flash (qk_tap_dance_state_t *state, void *user_data) { switch (state->count) { case 2:reset_keyboard();break;}}

qk_tap_dance_action_t tap_dance_actions[] =
{    [TD_F1] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_fun1, dance_fun1_reset)
,    [TD_F2] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_fun2, dance_fun2_reset)
,    [TD_F3] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_fun3, dance_fun3_reset)
,    [TD_F4] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_fun4, dance_fun4_reset)
,    [TD_F5] = ACTION_TAP_DANCE_DOUBLE(KC_F5, KC_F15)
,    [TD_F6] = ACTION_TAP_DANCE_DOUBLE(KC_F6, KC_F16)
,    [TD_F7] = ACTION_TAP_DANCE_DOUBLE(KC_F7, KC_F17)
,    [TD_F8] = ACTION_TAP_DANCE_DOUBLE(KC_F8, KC_F18)
,    [TD_F9] = ACTION_TAP_DANCE_DOUBLE(KC_F9, KC_F19)
,    [TD_F0] = ACTION_TAP_DANCE_DOUBLE(KC_F10, KC_F20)
// Safety keys, need to be pressed twice to activate anything.
,    [TD_SYRQ] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_syrq, dance_syrq_reset)
,    [TD_FLSH] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_flash, NULL)
};

//
// Custom Keys
//
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
            case KC_P00:
                // types Numpad 0 twice
                SEND_STRING(SS_TAP(X_KP_0) SS_TAP(X_KP_0));
                return false;
        }
    }
    return true;
};

//
// Stenotype
//
void matrix_init_user() {
  steno_set_mode(STENO_MODE_GEMINI); // or STENO_MODE_BOLT
}