#include QMK_KEYBOARD_H
#include "version.h"
#include "raw_hid.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


    /*
     * ,--------------------------------------------------.    ,--------------------------------------------------.
     * |    0   |   1  |   2  |   3  |   4  |   5  |  6   |    |  38  |  39  |  40  |  41  |  42  |  43  |   44   |
     * |--------+------+------+------+------+------+------|    |------+------+------+------+------+------+--------|
     * |    7   |   8  |   9  |  10  |  11  |  12  |  13  |    |  45  |  46  |  47  |  48  |  49  |  50  |   51   |
     * |--------+------+------+------+------+------|      |    |      |------+------+------+------+------+--------|
     * |   14   |  15  |  16  |  17  |  18  |  19  |------|    |------|  52  |  53  |  54  |  55  |  56  |   57   |
     * |--------+------+------+------+------+------|  26  |    |  58  |------+------+------+------+------+--------|
     * |   20   |  21  |  22  |  23  |  24  |  25  |      |    |      |  59  |  60  |  61  |  62  |  63  |   64   |
     * `--------+------+------+------+------+-------------'    `-------------+------+------+------+------+--------'
     *   |  27  |  28  |  29  |  30  |  31  |                                |  65  |  66  |  67  |  68  |  69  |
     *   `----------------------------------'                                `----------------------------------'
     *                                       ,-------------.  ,-------------.
     *                                       |  32  |  33  |  |  70  |  71  |
     *                                ,------+------+------|  |------+------+------.
     *                                |      |      |  34  |  |  72  |      |      |
     *                                |  35  |  36  |------|  |------|  74  |  75  |
     *                                |      |      |  37  |  |  73  |      |      |
     *                                `--------------------'  `--------------------'
     */

[0] = LAYOUT_ergodox(
// left hand

KC_ESCAPE, KC_1     , KC_2    , KC_3   , KC_4  , KC_5, KC_6     ,
KC_TAB   , KC_QUOTE , KC_COMMA, KC_DOT , KC_P  , KC_Y, KC_BSPACE,
KC_RALT  , KC_A     , KC_O    , KC_E   , KC_U  , KC_I,
KC_LSHIFT, KC_SCOLON, KC_Q    , KC_J   , KC_K  , KC_X, KC_ENTER ,
KC_LCTRL , MO(2)    , KC_LALT , KC_LGUI, KC_MEH,

// left thumb

          WEBUSB_PAIR, _______,
                       _______,
KC_SPACE, MO(1)      , MO(1)  ,

// right hand

KC_7     , KC_8, KC_9   , KC_0 , KC_LBRACKET, KC_RBRACKET, KC_GRAVE ,
KC_BSPACE, KC_F, KC_G   , KC_C , KC_R       , KC_L       , KC_SLASH ,
           KC_D, KC_H   , KC_T , KC_N       , KC_S       , KC_MINUS ,
KC_ENTER , KC_B, KC_M   , KC_W , KC_V       , KC_Z       , KC_RSHIFT,
                 KC_LEFT, KC_UP, KC_DOWN    , KC_RIGHT   , KC_RCTRL ,

// right thumb

TG(1)  , _______,
_______,
_______, MO(1)  , KC_SPACE
),

[1] = LAYOUT_ergodox(
// left hand

_______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6     ,
_______, _______, _______, _______, _______, _______, KC_DELETE ,
_______, _______, _______, _______, _______, _______,
_______, _______, _______, _______, _______, _______, KC_PSCREEN,
_______, _______, _______, _______, _______,

// left thumb

         _______, _______,
                  _______,
_______, _______, _______,

// right hand

KC_F7    , KC_F8  , KC_F9  , KC_F10 , KC_F11   , KC_F12 , _______  ,
KC_DELETE, _______, KC_KP_7, KC_KP_8, KC_KP_9  , _______, KC_BSLASH,
           _______, KC_KP_4, KC_KP_5, KC_KP_6  , _______, KC_EQUAL ,
_______  , KC_KP_0, KC_KP_1, KC_KP_2, KC_KP_3  , _______, _______  ,
                    KC_HOME, KC_PGUP, KC_PGDOWN, KC_END , _______  ,

// right thumb

_______, _______,
_______,
_______, _______, _______
),

[2] = LAYOUT_ergodox(
// left hand

KC_WWW_HOME, KC_WWW_BACK, KC_WWW_FORWARD , _______        , _______        , _______, _______,
_______    , _______    , _______        , _______        , _______        , _______, _______,
_______    , _______    , _______        , _______        , _______        , _______,
_______    , _______    , RSFT(KC_DELETE), RCTL(KC_INSERT), RSFT(KC_INSERT), _______, _______,
_______    , _______    , _______        , _______        , _______        ,

// left thumb

         _______, _______,
                  _______,
_______, _______, _______,

// right hand

_______, _______, _______          , _______           , _______, _______, KC_SYSTEM_POWER,
_______, _______, KC_AUDIO_VOL_UP  , KC_BRIGHTNESS_UP  , _______, _______, KC_SYSTEM_SLEEP,
         _______, KC_AUDIO_MUTE    , KC_MY_COMPUTER    , _______, _______, _______        ,
_______, _______, KC_AUDIO_VOL_DOWN, KC_BRIGHTNESS_DOWN, _______, _______, _______        ,
                  _______          , _______           , _______, _______, _______        ,

// right thumb

_______, _______,
_______,
_______, _______, KC_MEDIA_PLAY_PAUSE
)
};





bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {
  uint8_t layer = biton32(state);
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  ergodox_led_all_set(80);
  switch (layer) {
    case 1:
      ergodox_right_led_1_on();
      break;
    case 2:
      ergodox_right_led_2_on();
      break;
    case 3:
      ergodox_right_led_3_on();
      break;
    case 4:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      break;
    case 5:
      ergodox_right_led_1_on();
      ergodox_right_led_3_on();
      break;
    case 6:
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    case 7:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    default:
      break;
  }
  return state;
};

void raw_hid_receive(uint8_t *data, uint8_t length) {
    if (length == 0) return;
    uint8_t c = data[0];

    if (c & 0x1) {
        ergodox_right_led_1_on();
    } else {
        ergodox_right_led_1_off();
    }
    if (c & 0x2) {
        ergodox_right_led_2_on();
    } else {
        ergodox_right_led_2_off();
    }
    if (c & 0x4) {
        ergodox_right_led_3_on();
    } else {
        ergodox_right_led_3_off();
    }
}
