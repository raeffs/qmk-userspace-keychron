
#include QMK_KEYBOARD_H

enum layers {
    _QWERTZ,
    _RAISE,
    _LOWER,
    _ADJUST
};

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

#define KC_AUML RALT(KC_A)
#define KC_OUML RALT(KC_O)
#define KC_UUML RALT(KC_U)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QUERTZ

 ,-----------------------------------------------------.                     ,-----------------------------------------------------.
 |  ESC   |        |        |        |        |        |                     |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+--------|
 |  TAB   |   Q    |   W    |   E    |   R    |   T    |                     |   Z    |   U    |   I    |   O    |   P    |   Ü    |
 |--------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+--------|
 | L CTRL |   A    |   S    |   D    |   F    |   G    |--------.   ,--------|   H    |   J    |   K    |   L    |   Ö    |   Ä    |
 |--------+--------+--------+--------+--------+--------|        |   |        |--------+--------+--------+--------+--------+--------|
 | L SFT  |   Y    |   X    |   C    |   V    |   B    |--------|   |--------|   N    |   M    |   ,    |   .    |   -    | R SFT  |
 `-----------------------------------------------------/        /    \        \----------------------------------------------------'
                         | L ALT  | L GUI  | LOWER  | / SPACE  /      \ ENTER  \ | RAISE  | BackSp | R GUI  |
                         `------------------------------------'        '------------------------------------'
*/
[_QWERTZ] = LAYOUT(
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                          KC_Z,    KC_U,    KC_I,    KC_O,    KC_P,    KC_UUML,
  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                          KC_H,    KC_J,    KC_K,    KC_L,    KC_OUML, KC_AUML,
  KC_LSFT, KC_Y,    KC_X,    KC_C,    KC_V,    KC_B,    XXXXXXX,     XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_MINS, KC_RSFT,
                             KC_LALT, KC_LGUI, LOWER,   KC_SPC,      KC_ENT,  RAISE,   KC_BSPC, KC_RGUI
),

/* NAVIGATION

 ,-----------------------------------------------------.                     ,-----------------------------------------------------.
 |        |        |        |        |        |        |                     |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+--------|
 |        | Insert |  Home  |   Up   |  End   |        |                     |        |   7    |   8    |   9    |        |        |
 |--------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+--------|
 |        | Delete |  Left  |  Down  | Right  |        |--------.   ,--------|        |   4    |   5    |   6    |   0    |        |
 |--------+--------+--------+--------+--------+--------|        |   |        |--------+--------+--------+--------+--------+--------|
 |        |        |  PgUp  |        | PgDown |        |--------|   |--------|        |   1    |   2    |   3    |        |        |
 `-----------------------------------------------------/        /    \        \----------------------------------------------------'
                         |        |        |        | /        /      \        \ |        |        |        |
                         `------------------------------------'        '------------------------------------'
*/
[_LOWER] = LAYOUT(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                         KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  _______, KC_INS,  KC_HOME, KC_UP,   KC_END,  XXXXXXX,                       XXXXXXX, KC_7,    KC_8,    KC_9,    XXXXXXX, XXXXXXX,
  _______, KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX,                       XXXXXXX, KC_4,    KC_5,    KC_6,    KC_0,    XXXXXXX,
  _______, XXXXXXX, KC_PGUP, XXXXXXX, KC_PGDN, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, KC_1,    KC_2,    KC_3,    XXXXXXX, _______,
                             _______, _______, _______, _______,     _______, _______, _______, _______
),

/* SYMBOL

 ,-----------------------------------------------------.                     ,-----------------------------------------------------.
 |  ESC   |        |        |        |        |        |                     |        |        |        |        |        |        |
 |--------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+--------|
 |  TAB   |   @    |   _    |   [    |   ]    |   ^    |                     |   !    |   <    |   >    |   =    |   &    |        |
 |--------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+--------|
 | L CTRL |   \    |   /    |   {    |   }    |   *    |--------.   ,--------|   ?    |   (    |   )    |   -    |   :    |        |
 |--------+--------+--------+--------+--------+--------|        |   |        |--------+--------+--------+--------+--------+--------|
 | L SFT  |   #    |   $    |   |    |   ~    |   `    |--------|   |--------|   +    |   %    |   "    |   '    |   ;    | R SFT  |
 `-----------------------------------------------------/        /    \        \----------------------------------------------------'
                         |        |        |        | /        /      \        \ |        |        |        |
                         `------------------------------------'        '------------------------------------'
*/
[_RAISE] = LAYOUT(
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  _______, S(KC_2), S(KC_MINS),KC_LBRC,KC_RBRC,S(KC_6),                       S(KC_1), S(KC_COMM),S(KC_DOT),KC_EQL,S(KC_7),XXXXXXX,
  _______, KC_BSLS, KC_SLSH, S(KC_LBRC),S(KC_RBRC),S(KC_8),                   S(KC_SLSH),S(KC_9),S(KC_0),KC_MINS,S(KC_SCLN),XXXXXXX,
  _______, S(KC_3), S(KC_4), S(KC_BSLS),S(KC_GRV),KC_GRV, XXXXXXX,   XXXXXXX, S(KC_EQL),S(KC_5),S(KC_QUOT),KC_QUOT,KC_SCLN,_______,
                             _______, _______, _______, _______,     _______, _______, _______, _______
),

/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______,  _______, _______, _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
   return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
