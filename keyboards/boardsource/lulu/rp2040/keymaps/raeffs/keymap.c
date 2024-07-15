
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

/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |MOD   | MODR |  S+  |  S-  |  B+  |  B-  |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |-------.    ,-------|      | Left | Down |  Up  |Right |      |
 * |------+------+------+------+------+------|RGB_TOG|    |    ]  |------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  | F10  | F11  | F12  |-------|    |-------|   +  |   -  |   =  |   [  |   ]  |   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT(
  RGB_MOD, RGB_RMOD,RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD,                     _______, _______, _______, _______, _______, _______,
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                       XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   RGB_TOG, _______,  KC_PLUS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
                             _______, _______, _______,  _______, _______,  _______, _______, _______
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
