/*
 *       ▄████████     ███        ▄████████    ▄████████ ███    █▄     ▄████████
 *      ███    ███ ▀█████████▄   ███    ███   ███    ███ ███    ███   ███    ███
 *      ███    ███    ▀███▀▀██   ███    ███   ███    █▀  ███    ███   ███    █▀
 *      ███    ███     ███   ▀  ▄███▄▄▄▄██▀  ▄███▄▄▄     ███    ███   ███
 *    ▀███████████     ███     ▀▀███▀▀▀▀▀   ▀▀███▀▀▀     ███    ███ ▀███████████
 *      ███    ███     ███     ▀███████████   ███    █▄  ███    ███          ███
 *      ███    ███     ███       ███    ███   ███    ███ ███    ███    ▄█    ███
 *      ███    █▀     ▄████▀     ███    ███   ██████████ ████████▀   ▄████████▀
 *                               ███    ███
 *
 * Web: https://kaleidoscope.readthedocs.io/en/latest/
 * Github: https://github.com/keyboardio/Kaleidoscope
 * ATmega32U4: https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7766-8-bit-AVR-ATmega16U4-32U4_Datasheet.pdf
 *
 */

#include "Kaleidoscope.h"
#include "Kaleidoscope-EEPROM-Settings.h"
#include "Kaleidoscope-HostOS.h"
#include "Kaleidoscope-Macros.h"
#include "Kaleidoscope-MouseKeys.h"
#include "Kaleidoscope-Qukeys.h"
#include "Kaleidoscope-Steno.h"
#include "Kaleidoscope-TapDance.h"
#include "Kaleidoscope-Turbo.h"
#include "Kaleidoscope-USB-Quirks.h"
#include "Kaleidoscope-Unicode.h"
#include "Kaleidoscope-OneShot.h"
#include "Kaleidoscope-OneShotMetaKeys.h"
#include "Kaleidoscope-Escape-OneShot.h"
#include "Kaleidoscope-Cycle.h"
#include "Kaleidoscope-Syster.h"

KEYMAPS (
/* 0 COLEMAK
 * ,-------------------.       ,-------------------.
 * | q | w | f | p | g |       | j | l | u | y | ' |
 * |---+---+---+---+---|       |---+---+---+---+---|
 * | a | r | s | t | d |       | h | n | e | i | o |
 * |---+---+---+---+---+-------+---+---+---+---+---|
 * | z | x | c | v | b |ll1|ll4| k | m | , | . | / |
 * |---+---+---+---+---+---+---+---+---+---+---+---|
 * |ctr|alt|gui|sl2|spc|ptt|tab|bsp|xxx|fun|tur|ent|
 * `-----------------------------------------------'
 */
  [0] = KEYMAP_STACKED (
       Key_Q           ,Key_W         ,Key_F         ,Key_P        ,Key_G
      ,Key_A           ,Key_R         ,Key_S         ,Key_T        ,Key_D
      ,Key_Z           ,Key_X         ,Key_C         ,Key_V        ,Key_B      ,LockLayer(1)
      ,Key_LeftControl ,Key_LeftAlt       ,Key_LeftGui   ,ShiftToLayer(2)        ,Key_Space  ,Key_F13

                       ,Key_J         ,Key_L         ,Key_U        ,Key_Y      ,Key_Quote
                       ,Key_H         ,Key_N         ,Key_E        ,Key_I      ,Key_O
      ,LockLayer(4)           ,Key_K         ,Key_M         ,Key_Comma    ,Key_Period ,Key_Slash
      ,Key_Tab     ,Key_Backspace ,XXX ,ShiftToLayer(3)        ,Key_Cycle     ,Key_Enter
  ),
/* 1 QWERTY/GAME
 * ,-------------------.       ,-------------------.
 * | q | w | e | r | t |       | y | u | i | o | p |
 * |---+---+---+---+---|       |---+---+---+---+---|
 * | a | s | d | f | g |       | h | j | k | l | ; |
 * |---+---+---+---+---+-------+---+---+---+---+---|
 * | z | x | c | v | b |qwr|___| n | m | , | . | / |
 * |---+---+---+---+---+---+---+---+---+---+---+---|
 * |___|___|___|___|___|___|___|___|___|___|___|___|
 * `-----------------------------------------------'
 */
  [1] = KEYMAP_STACKED (
       Key_Q ,Key_W ,Key_E ,Key_R     ,Key_T
      ,Key_A ,Key_S ,Key_D ,Key_F     ,Key_G
      ,Key_Z ,Key_X ,Key_C ,Key_V     ,Key_B      ,UnlockLayer(1)
      ,___   ,___   ,___   ,___       ,___        ,___

             ,Key_Y ,Key_U ,Key_I     ,Key_O      ,Key_P
             ,Key_H ,Key_J ,Key_K     ,Key_L      ,Key_Semicolon
      ,___   ,Key_N ,Key_M ,Key_Comma ,Key_Period ,Key_Slash
      ,___   ,___   ,___   ,___       ,___        ,___
  ),
/* 2 NUMBER
 * ,-------------------.       ,-------------------.
 * |esc| ↑ | ` |pup|hom|       | [ | ] | ; | - | = |
 * |---+---+---+---+---|       |---+---+---+---+---|
 * | ← | ↓ | → |pdn|end|       |___|sys|___|___|___|
 * |---+---+---+---+---+-------+---+---+---+---+---|
 * | 1 | 2 | 3 | 4 | 5 |___|___| 6 | 7 | 8 | 9 | 0 |
 * |---+---+---+---+---+---+---+---+---+---+---+---|
 * |ctl|alt|gui|___|___|___|___|___|___|___|___|___|
 * `-----------------------------------------------'
 */
  [2] = KEYMAP_STACKED (
       Key_Escape      ,Key_UpArrow     ,Key_Backtick   ,Key_PageUp           ,Key_Home
      ,Key_LeftArrow   ,Key_DownArrow   ,Key_RightArrow ,Key_PageDown         ,Key_End
      ,Key_1           ,Key_2           ,Key_3          ,Key_4                ,Key_5    ,LockLayer(5)
      ,Key_RightControl,Key_RightAlt    ,Key_RightGui   ,___                  ,___      ,___

                       ,Key_LeftBracket ,Key_RightBracket ,Key_Semicolon         ,Key_Minus ,Key_Equals
                       ,Key_Turbo       ,SYSTER           ,OneShot_MetaStickyKey ,OneShot_ActiveStickyKey ,Key_Backslash
      ,___             ,Key_6           ,Key_7            ,Key_8         ,Key_9  ,Key_0
      ,___             ,___             ,___              ,___           ,___    ,___
   ),
/* 3 FUNCTION
 * ,-------------------.       ,-------------------.
 * |___|___|___|___|___|       |___|___|___|___|___|
 * |---+---+---+---+---|       |---+---+---+---+---|
 * |___|___|___|___|___|       |___|___|___|___|___|
 * |---+---+---+---+---+-------+---+---+---+---+---|
 * |F01|F02|F03|F04|F05|___|___|F06|F07|F08|F09|F10|
 * |---+---+---+---+---+---+---+---+---+---+---+---|
 * |___|___|___|___|___|___|___|___|___|___|___|___|
 * `-----------------------------------------------'
 */
  [3] = KEYMAP_STACKED (
       ___  ,___  ,___  ,___ ,___
      ,___  ,___  ,___  ,___ ,___
      ,TD(1) ,TD(2) ,TD(3) ,TD(4) ,TD(5) ,___
      ,___     ,___     ,___     ,___     ,___ ,___

           ,___  ,___  ,___  ,___  ,___
           ,___  ,___  ,___  ,___  ,___
      ,___ ,TD(6) ,TD(7) ,TD(8) ,TD(9) ,TD(0)
      ,___ ,___     ,___     ,___     ,___     ,___
   ),
/* 4 MOUSE
 * ,-------------------.       ,-------------------.
 * |___|___|___|___|___|       |PaU|ScU|ScL| U |ScR|
 * |---+---+---+---+---|       |---+---+---+---+---|
 * |___|___|___|___|___|       |MB2|MB1| L | D | R |
 * |---+---+---+---+---+-------+---+---+---+---+---|
 * |___|___|___|___|___|___|mou|PaD|ScD|___|___|___|
 * |---+---+---+---+---+---+---+---+---+---+---+---|
 * |___|___|___|___|___|___|___|MoS|___|___|___|___|
 * `-----------------------------------------------'
 */
  [4] = KEYMAP_STACKED (
       ___ ,___ ,___ ,___ ,___
      ,___ ,___ ,___ ,___ ,___
      ,___ ,___ ,___ ,___ ,___ ,___
      ,___ ,___ ,___ ,___ ,___ ,___

                 ,Key_PageUp    ,Key_mouseScrollUp ,Key_mouseScrollL ,Key_mouseUp ,Key_mouseScrollR
                 ,Key_mouseBtnR ,Key_mouseBtnL     ,Key_mouseL       ,Key_mouseDn ,Key_mouseR
      ,UnlockLayer(4)     ,Key_PageDown  ,Key_mouseScrollDn ,XXX              ,XXX         ,XXX
      ,___       ,M(1)          ,___               ,___              ,___         ,___
   ),
/* 5 STENO
 * ,-------------------.       ,-------------------.
 * |s1 |tl |pl |hl |st1|       |fr |pr |lr |tr |dr |
 * |---+---+---+---+---|       |---+---+---+---+---|
 * |s2 |kl |wl |rl |st2|       |rr |br |gr |sr |zr |
 * |---+---+---+---+---+-------+---+---+---+---+---|
 * |n1 |n2 |n3 |n4 |n5 |   |   | n6| n7| n8| n9|XXX|
 * |---+---+---+---+---+---+---+---+---+---+---+---|
 * |XXX|XXX|XXX| a | o |   |   | e | u |XXX|XXX|XXX|
 * `-----------------------------------------------'
 * The provided keys are: NA, NB, NC, RE1, RE2, PWR, START, ST3, ST4
 */
  [5] = KEYMAP_STACKED (
       S(S1) ,S(TL) ,S(PL) ,S(HL) ,S(ST1)
      ,S(S2) ,S(KL) ,S(WL) ,S(RL) ,S(ST2)
      ,S(N1) ,S(N2) ,S(N3) ,S(N4) ,S(N5) ,XXX
      ,XXX   ,XXX   ,XXX   ,S(A)  ,S(O)  ,XXX

             ,S(FR) ,S(PR) ,S(LR) ,S(TR) ,S(DR)
             ,S(RR) ,S(BR) ,S(GR) ,S(SR) ,S(ZR)
      ,XXX   ,S(N6) ,S(N7) ,S(N8) ,S(N9) ,XXX
      ,XXX   ,S(E)  ,S(U)  ,XXX   ,XXX   ,XXX
   ),
/* 6 NUMPAD
 * ,-------------------.       ,-------------------.
 * |XXX|XXX|XXX|XXX|XXX|       | * | 7 | 8 | 9 | - |
 * |---+---+---+---+---|       |---+---+---+---+---|
 * |XXX|XXX|XXX|XXX|XXX|       | / | 4 | 5 | 6 | + |
 * |---+---+---+---+---+-------+---+---+---+---+---|
 * |XXX|XXX|XXX|XXX|XXX|XXX| n |XXX| 1 | 2 | 3 | = |
 * |---+---+---+---+---+---+---+---+---+---+---+---|
 * |XXX|XXX|XXX|XXX|XXX|XXX|tab|bsp| 0 | 00| . |ent|
 * `-----------------------------------------------'
 */

  [6] = KEYMAP_STACKED (
       XXX ,XXX ,XXX ,XXX ,XXX
      ,XXX ,XXX ,XXX ,XXX ,XXX
      ,XXX ,XXX ,XXX ,XXX ,XXX ,XXX
      ,XXX ,XXX ,XXX ,XXX ,XXX ,XXX

                     ,Key_KeypadMultiply  ,Key_Keypad7 ,Key_Keypad8  ,Key_Keypad9   ,Key_KeypadSubtract
                     ,Key_KeypadSubtract  ,Key_Keypad4 ,Key_Keypad5  ,Key_Keypad6   ,Key_KeypadAdd
      ,XXX           ,Key_KeypadNumLock   ,Key_Keypad1 ,Key_Keypad2  ,Key_Keypad3   ,Key_KeypadEquals
      ,Key_KeypadTab ,Key_KeypadBackspace ,Key_Keypad0 ,Key_Keypad00 ,Key_KeypadDot ,Key_KeypadEnter
   )

/* BLANK TEMPLATE
 * ,-------------------.       ,-------------------.
 * |XXX|XXX|XXX|XXX|XXX|       |XXX|XXX|XXX|XXX|XXX|
 * |---+---+---+---+---|       |---+---+---+---+---|
 * |XXX|XXX|XXX|XXX|XXX|       |XXX|XXX|XXX|XXX|XXX|
 * |---+---+---+---+---+-------+---+---+---+---+---|
 * |XXX|XXX|XXX|XXX|XXX|XXX|XXX|XXX|XXX|XXX|XXX|XXX|
 * |---+---+---+---+---+---+---+---+---+---+---+---|
 * |XXX|XXX|XXX|XXX|XXX|XXX|XXX|XXX|XXX|XXX|XXX|XXX|
 * `-----------------------------------------------'
 */
 /*
  [BLANK] = KEYMAP_STACKED (
       XXX ,XXX ,XXX ,XXX ,XXX
      ,XXX ,XXX ,XXX ,XXX ,XXX
      ,XXX ,XXX ,XXX ,XXX ,XXX ,XXX
      ,XXX ,XXX ,XXX ,XXX ,XXX ,XXX

           ,XXX ,XXX ,XXX ,XXX ,XXX
           ,XXX ,XXX ,XXX ,XXX ,XXX
      ,XXX ,XXX ,XXX ,XXX ,XXX ,XXX
      ,XXX ,XXX ,XXX ,XXX ,XXX ,XXX
   ),
    */
)

void systerAction(kaleidoscope::plugin::Syster::action_t action,
                  const char *symbol) {
  switch (action) {
  case kaleidoscope::plugin::Syster::StartAction:
    Unicode.type(0x2328);
    break;
  case kaleidoscope::plugin::Syster::EndAction:
    handleKeyswitchEvent(Key_Backspace, UnknownKeyswitchLocation,
                         IS_PRESSED | INJECTED);
    Kaleidoscope.hid().keyboard().sendReport();
    handleKeyswitchEvent(Key_Backspace, UnknownKeyswitchLocation,
                         WAS_PRESSED | INJECTED);
    Kaleidoscope.hid().keyboard().sendReport();
    break;
  case kaleidoscope::plugin::Syster::SymbolAction:
    Kaleidoscope.serialPort().print("systerAction: symbol=");
    Kaleidoscope.serialPort().println(symbol);
    if (strcmp(symbol, "coffee") == 0) {
      Unicode.type(0x2615);
    }
  }
}

void cycleAction(Key previous_key, uint8_t cycle_count) {
  bool is_shifted = previous_key.getFlags() & SHIFT_HELD;
  if (previous_key.getKeyCode() == Key_A.getKeyCode() && is_shifted)
      Unicode.type(0x00C4);
  if (previous_key.getKeyCode() == Key_A.getKeyCode() && !is_shifted)
      Unicode.type(0x00E4);
  if (previous_key.getKeyCode() == Key_E.getKeyCode() && !is_shifted)
      Unicode.type(0x00E9);
  if (previous_key.getKeyCode() == Key_O.getKeyCode() && is_shifted)
      Unicode.type(0x00D6);
  if (previous_key.getKeyCode() == Key_O.getKeyCode() && !is_shifted)
      Unicode.type(0x00F6);
  if (previous_key.getKeyCode() == Key_S.getKeyCode() && !is_shifted)
      Unicode.type(0x00DF);
  if (previous_key.getKeyCode() == Key_U.getKeyCode() && is_shifted)
      Unicode.type(0x00DC);
  if (previous_key.getKeyCode() == Key_U.getKeyCode() && !is_shifted)
      Unicode.type(0x00FC);
}

KALEIDOSCOPE_INIT_PLUGINS(EEPROMSettings, GeminiPR, Macros, MouseKeys, TapDance,
                          USBQuirks, HostOS, Unicode, Turbo, Qukeys, OneShot, OneShotMetaKeys, EscapeOneShot, Cycle);

const macro_t *macroAction(uint8_t macroIndex, uint8_t keyState) {
  switch (macroIndex) {
  case 0:
    break;
  case 1:
    if (keyIsPressed(keyState)) {
      MouseKeys.speed = 30;
    }
    if (keyToggledOff(keyState)) {
      MouseKeys.speed = 10;
    }
    break;
  case 2:
    if (keyToggledOn(keyState)) {
      USBQuirks.toggleKeyboardProtocol();
    }
    break;
  default:
    break;
  }
  return MACRO_NONE;
}

void tapDanceAction(
    uint8_t tap_dance_index, KeyAddr key_addr, uint8_t tap_count,
    kaleidoscope::plugin::TapDance::ActionType tap_dance_action) {
  switch (tap_dance_index) {
  case 0:
    return tapDanceActionKeys(tap_count, tap_dance_action, Key_F10, Key_F20);
  case 1:
    return tapDanceActionKeys(tap_count, tap_dance_action, Key_F1, Key_F11, Key_F21);
  case 2:
    return tapDanceActionKeys(tap_count, tap_dance_action, Key_F2, Key_F12, Key_F22);
  case 3:
    return tapDanceActionKeys(tap_count, tap_dance_action, Key_F3, Key_F13, Key_F23);
  case 4:
    return tapDanceActionKeys(tap_count, tap_dance_action, Key_F4, Key_F14, Key_F24);
  case 5:
    return tapDanceActionKeys(tap_count, tap_dance_action, Key_F5, Key_F15);
  case 6:
    return tapDanceActionKeys(tap_count, tap_dance_action, Key_F6, Key_F16);
  case 7:
    return tapDanceActionKeys(tap_count, tap_dance_action, Key_F7, Key_F17);
  case 8:
    return tapDanceActionKeys(tap_count, tap_dance_action, Key_F8, Key_F18);
  case 9:
    return tapDanceActionKeys(tap_count, tap_dance_action, Key_F9, Key_F19);
  }
}

void setup() {
  Kaleidoscope.serialPort().begin(9600);
  Kaleidoscope.setup();
  MouseKeys.speed = 10;
  MouseKeys.accelSpeed = 0;
  HostOS.os(kaleidoscope::hostos::LINUX);
  EEPROMSettings.default_layer(0);
  QUKEYS(
      /* Qukeys
       * ,-------------------.       ,-------------------.
       * |0,0|0,1|0,2|0,3|0,4|       |0,7|0,8|0,9|010|011|
       * |---+---+---+---+---|       |---+---+---+---+---|
       * |1,0|1,1|1,2|1,3|1,4|       |1,7|1,8|1,9|110|111|
       * |---+---+---+---+---+-------+---+---+---+---+---|
       * |2,0|2,1|2,2|2,3|2,4|2,5|2,6|2,7|2,8|2,9|210|211|
       * |---+---+---+---+---+---+---+---+---+---+---+---|
       * |3,0|3,1|3,2|3,3|3,4|3,5|3,6|3,7|3,8|3,9|310|311|
       * `-----------------------------------------------'
       */
      kaleidoscope::plugin::Qukey(0, KeyAddr(2, 0), Key_LeftShift), // Z/shift
      kaleidoscope::plugin::Qukey(0, KeyAddr(2, 11),
                                  Key_RightShift), // fs/shift
  )
  Qukeys.setHoldTimeout(1000);
  Qukeys.setOverlapThreshold(50); // roll-over - allow modifier key to be
                                  // released before the modified key
  Qukeys.setMinimumHoldTime(100);
  Qukeys.setMinimumPriorInterval(80);
}

void loop() { Kaleidoscope.loop(); }
