#include QMK_KEYBOARD_H

enum sofle_layers {
    _QWERTY,
    _SYM,
    _MOV,
    _FN,
};

enum custom_keycodes {
    ENC_LL = QK_USER,
    ENC_LR,
    ENC_RL,
    ENC_RR,
    MOV_ENC_LL,
    MOV_ENC_LR,
    MOV_ENC_RL,
    MOV_ENC_RR,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                     ,-----------------------------------------.
 * |  `~  |  1!  |  2@  |  3#  |  4$  |  5%  |                     |  6^  |  7&  |  8*  |  9(  |  0)  | Bspc |
 * |------+------+------+------+------+------|                     |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                     |   Y  |   U  |   I  |   O  |   P  |Enter |
 * |------+------+------+------+------+------|                     |------+------+------+------+------+------|
 * | ESC  |   A  |   S  |   D  |   F  |   G  |                     |   H  |   J  |   K  |   L  |  ;:  |  '"  |
 * |------+------+------+------+------+------|-------.     ,-------|------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |       |     |       |   N  |   M  |  ,<  |  .>  |  /?  |RShift|
 * `-----------------------------------------/-------/     \-------\-----------------------------------------'
 *            | LCTL |  FN  |LSuper| LALT | /T:Space/       \  MOV  \  | RALT |RSuper|  App | RCTL |
 *            |      |      |      |      |/ H:SYM /         \       \ |      |      |      |      |
 *            `-----------------------------------'           '-------''---------------------------'
 */

[_QWERTY] = LAYOUT(

  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,

  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_ENT,

  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,

  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    XXXXXXX,          XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,

               KC_LCTL, MO(_FN), KC_LGUI,   KC_LALT,    LT(_SYM, KC_SPC), MO(_MOV),   KC_RALT,   KC_RGUI, KC_APP,  KC_RCTL
),

/*
 * SYM
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `~  |  1!  |  2@  |  3#  |  4$  |  5%  |                    |  6^  |  7&  |  8*  |  9(  |  0)  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |      |      |      |      |      |                    |      |      |  -_  |  =+  |      |Enter |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |      |      |      |      |      |                    |      |  \|  |  [{  |  ]}  |  ;:  |  '"  |
 * |------+------+------+------+------+------|-------.    ,-------|------+------+------+------+------+------|
 * |LShift|      |      |      |      |      |       |    |       |      |      |  ,<  |  .>  |  /?  |RShift|
 * `-----------------------------------------/-------/     \-------\----------------------------------------'
 *            | LCTL |      |LSuper| LALT | /HHHHHHH/       \       \  | RALT |RSuper|  App | RCTL |
 *            |      |      |      |      |/HHHHHHH/         \       \ |      |      |      |      |
 *            `---------------------------------- '           '------ ''---------------------------'
 */

[_SYM] = LAYOUT(

  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,    KC_7,    KC_8,    KC_9,   KC_0,    KC_BSPC,

  KC_TAB,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, KC_MINS, KC_EQL, XXXXXXX, KC_ENT,

  KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, KC_BSLS, KC_LBRC, KC_RBRC, KC_SCLN, KC_QUOT,

  KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,

               KC_LCTL, XXXXXXX, KC_LGUI,   KC_LALT,    XXXXXXX,     XXXXXXX,    KC_RALT,   KC_RGUI, KC_APP,  KC_RCTL
),

/* MOV
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      | Del  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  |MouseL|MouseU|MouseD|MouseR|      |                    |      | Left | Down |  Up  | Rigth|      |
 * |------+------+------+------+------+------|-------.    ,-------|------+------+------+------+------+------|
 * |Shift |ScrlL |ScrlUp|ScrlDn|ScrlR |      |MClick |    |RClick |      | Home | PgDn | PgUp | End  |RShift|
 * `-----------------------------------------/-------/     \-------\----------------------------------------'
 *           | LCTL |      |LSuper | LALT | /LClick /       \HHHHHHH\  |      |      |      |      |
 *           |      |      |       |      |/       /         \HHHHHHH\ |      |      |      |      |
 *           `------------------------------------'          '- -----  ---------------------------'
 */
[_MOV] = LAYOUT(

  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL,

  KC_TAB,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, MS_ACL1, MS_ACL2, XXXXXXX, XXXXXXX,

  KC_ESC,  MS_LEFT, MS_UP,   MS_DOWN, MS_RGHT, XXXXXXX,                        XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,

  KC_LSFT, MS_WHLL, MS_WHLU, MS_WHLD, MS_WHLR, XXXXXXX, MS_BTN3,      MS_BTN2, XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_RSFT,

               KC_LCTL, XXXXXXX, KC_LGUI,   KC_LALT,    MS_BTN1,      XXXXXXX,    XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX
),

/* FN
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | CAPS |      |      |      |      |      |                    |      |PrtScn|ScrLk |Pause |Insert|      |
 * |------+------+------+------+------+------|-------.    ,-------|------+------+------+------+------+------|
 * |LShift|      |      |      |      |      |       |    |       |      |      |      |      |      |RShift|
 * `-----------------------------------------/-------/     \-------\----------------------------------------'
 *            | LCTL |HHHHHH|LSuper| LALT | /Space  /       \      \  | RALT |RSuper|  App | RCTL |
 *            |      |HHHHHH|      |      |/       /         \      \ |      |      |      |      |
 *            `-----------------------------------'           '------''---------------------------'
 */
[_FN] = LAYOUT(

  XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                          KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,

  KC_TAB,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F12,

  KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, KC_PSCR, KC_SCRL, KC_PAUS, KC_INS, XXXXXXX,

  KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RSFT,

               KC_LCTL, XXXXXXX, KC_LGUI,   KC_LALT,    KC_SPC,       XXXXXXX,    KC_RALT,   KC_RGUI, KC_APP,  KC_RCTL
),
};

#ifdef OLED_ENABLE

static void print_status_narrow(void) {
    // Print current layer
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Base"), false);
            break;
        case _SYM:
            oled_write_ln_P(PSTR("Sym"), false);
            break;
        case _MOV:
            oled_write_ln_P(PSTR("Mov"), false);
            break;
        case _FN:
            oled_write_ln_P(PSTR("Fn"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }

    oled_write_P(PSTR("\n\n"), false);

    led_t led_usb_state = host_keyboard_led_state();
    if (led_usb_state.caps_lock) {
        oled_write_ln_P(PSTR("CPSLK"), true);
    } else {
        // we need to write an empty line to clear CPSLK
        oled_write_ln_P(PSTR(""), false);
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    }
    return false;
}

#endif

// todo: switching mouse speeds? macos remapping?
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ENC_LL:
            if (record->event.pressed) { tap_code16(LCTL(LSFT(KC_Z))); }
            return false;
        case ENC_LR:
            if (record->event.pressed) { tap_code16(LCTL(KC_Z)); }
            return false;
        case ENC_RL:
            if (record->event.pressed) { tap_code16(KC_VOLD); }
            return false;
        case ENC_RR:
            if (record->event.pressed) { tap_code16(KC_VOLU); }
            return false;
        case MOV_ENC_LL:
            if (record->event.pressed) { tap_code16(LCTL(LSFT(KC_TAB))); }
            return false;
        case MOV_ENC_LR:
            if (record->event.pressed) { tap_code16(LCTL(KC_TAB)); }
            return false;
        case MOV_ENC_RL:
            if (record->event.pressed) { tap_code16(LALT(LSFT(KC_TAB))); }
            return false;
        case MOV_ENC_RR:
            if (record->event.pressed) { tap_code16(LALT(KC_TAB)); }
            return false;
    }
    return true;
}

#ifdef ENCODER_MAP_ENABLE

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_QWERTY] = { ENCODER_CCW_CW(ENC_LL, ENC_LR),         ENCODER_CCW_CW(ENC_RL, ENC_RR) },
    [_SYM]    = { ENCODER_CCW_CW(XXXXXXX, XXXXXXX),       ENCODER_CCW_CW(XXXXXXX, XXXXXXX) },
    [_MOV]    = { ENCODER_CCW_CW(MOV_ENC_LL, MOV_ENC_LR), ENCODER_CCW_CW(MOV_ENC_RL, MOV_ENC_RR) },
    [_FN]     = { ENCODER_CCW_CW(XXXXXXX, XXXXXXX),       ENCODER_CCW_CW(XXXXXXX, XXXXXXX) },
};

#endif
