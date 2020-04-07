#include QMK_KEYBOARD_H


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _GAME 1
#define _NUMS 2
#define _ADJUST 13

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  GAME,
  NUMS,
  ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Default QWERTY layer. Double space on thumb, other changes. Right enter is shift when held.
 * ,-----------------------------------------.  ,-----------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |  |   Y  |   U  |   I  |   O  |   P  | GAME |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |LCtrl | LAlt |  Gui |ADJUST| NUMS | Bksp |  |Space |Space | Left | Down |  Up  |Right |
 * `-----------------------------------------'  `-----------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12( \
  KC_TAB,   KC_Q,    KC_W,   KC_E,   KC_R, KC_T,    KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    GAME, \
  KC_ESC,   KC_A,    KC_S,   KC_D,   KC_F, KC_G,    KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT,  KC_Z,    KC_X,   KC_C,   KC_V, KC_B,    KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_ENT), \
  KC_LCTRL, KC_LALT, KC_LGUI, ADJUST, NUMS, KC_BSPC, KC_SPC, KC_SPC, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

/* Game Mode. For things that require numbers and some QWERTY. Is a switch layer. Alt included, Z moved over.
 * ,-----------------------------------------.  ,-----------------------------------------.
 * |   ~  |   1  |   2  |   3  |   4  |   5  |  |   6  |   7  |   8  |   9  |   0  |QWERTY|
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |  |   Y  |   U  |   I  |   O  |   P  |  |   |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |LShift|   A  |   S  |   D  |   F  |   G  |  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |LCtrl | LAlt |   Z  |   X  |   C  |   V  |  |Space |Space | Left | Down |   Up |Right |
 * `-----------------------------------------'  `-----------------------------------------'
 */
[_GAME] = LAYOUT_ortho_4x12( \
  KC_TILD, KC_1,    KC_2,  KC_3,  KC_4, KC_5, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    QWERTY, \
  KC_TAB,  KC_Q,    KC_W,  KC_E,  KC_R, KC_T, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_PIPE, \
  _______, KC_A,    KC_S,  KC_D,  KC_F, KC_G, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, _______, \
  _______, _______, KC_Z,  KC_X,  KC_C, KC_V, _______, _______, _______, _______, _______, _______ \
),

/* Numbers (on top row), can be shifted (right or left) to get symbols. Easy thumb del+enter access, Fkeys, PgUp+Dn.
 * ,-----------------------------------------.  ,-----------------------------------------.
 * |   ~  |  1   |  2   |  3   |  4   |  5   |  |  6   |  7   |  8   |  9   |  0   | Bksp |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * | Esc  |  F1  |  F2  |  F3  |  F4  |  F5  |  |  F6  |      |      |   -  |   +  |  |   |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |LShift|  F7  |  F8  |  F9  |  F10 |  F11 |  |  F12 |      |   [  |   ]  |   \  |Enter |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |      |      |  Del |  |Enter |Enter | Next | PgDn | PgUp | Play |
 * `-----------------------------------------'  `-----------------------------------------'
 */
[_NUMS] = LAYOUT_ortho_4x12( \
  KC_TILD, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,  KC_F6,  _______, _______, KC_MINS, KC_PLUS, KC_PIPE, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, KC_F12, _______, KC_LBRC, KC_RBRC, KC_BSLS, _______, \
  _______, _______, _______, _______, _______, KC_DEL, KC_ENT, KC_ENT,  KC_MNXT, KC_PGDN, KC_PGUP, KC_MPLY \
),

/* Adjust settings of keyboard. Reset, Audio and RGB. Lots of space here for you to add whatever you want!
 * ,-----------------------------------------.  ,-----------------------------------------.
 * |RESET |      |      |      |      |      |  |      |      |      |      |      |RESET |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|  |AGswap|Qwerty| Game |      |      |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |LShift|      |      |      |      |      |  |      |      |      |      |      |Enter |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |RESET |      |      |      |      |  |RGBHUE|RGBHUE|RGBSAT|RGBBRI|RGBTOG|RGBMOD|
 * `-----------------------------------------'  `-----------------------------------------'
 */
[_ADJUST] =  LAYOUT_ortho_4x12( \
  RESET,     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET, \
  _______,   _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  GAME,    _______, _______, _______, \
  KC_LSHIFT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______,   _______, _______, _______, _______, _______, RGB_HUI, RGB_HUI, RGB_SAI, RGB_VAI, RGB_TOG, RGB_MOD \
)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case GAME:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_GAME);
      }
      return false;
      break;
    case NUMS:
      if (record->event.pressed) {
        layer_on(_NUMS);
      } else {
        layer_off(_NUMS);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
