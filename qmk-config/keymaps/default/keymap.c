// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
/*
     * ┬───┬───┬───┬───┬───┐              ┌───┬───┬───┬───┬───┐
     * │ 1 │ 2 │ 3 │ 4 | 5 |              │ 6 │ 7 │ 8 │ 9 │ 0 |
     * ┼───┼───┼───┬───┬───┐              ├───┼───┼───┼───┬───┐
     * │ Q │ W │ E │ R | T |              │ Y │ U │ I │ O │ P |
     * ┼───┼───┼───┼───┼───┐              ├───┼───┼───┼───┼───┐
     * │ A │ S │ D │ F | G |              │ H │ J │ K │ L │ ; |
     * ┼───┼───┼───┼───┼───┐              ├───┼───┼───┼───┼───┐
     * │ Z │ X │ C │ V | B |              │ N │ M │ , │ . │ / |
     * ┴───┴───┼───┼───┴───┴              ┴───┴───┼───┼───┴───┴
     *         |SPC|                              |BSP|
     *         └───┘┌───┐                    ┌───┐└───┘
     *              |TAB|                    |ENT|
     *              └───┘                    └───┘                    
     *                   ┌───┐          ┌───┐
     *                   |MAJ|          |CTL|
     *                   └───┘          └───┘                    
   

  */
#include QMK_KEYBOARD_H


// Layer names for each layer
enum layer_names {
    _MAC_DEFAULT,
    _MAC_ERGOL_ALT,
    _MAC_NAV,
    _MAC_NUMPAD,
    _MAC_MOUSE
};


//combos
const uint16_t PROGMEM switch_to_main_layer[] = {KC_N,KC_M, COMBO_END};
const uint16_t PROGMEM switch_to_nav_layer[] = {LT(2, KC_SPC),LSFT_T(KC_TAB), COMBO_END};
const uint16_t PROGMEM switch_to_num_layer[] = {LT(3,KC_ENTER),   LT(1, KC_BSPC), COMBO_END};

const uint16_t PROGMEM suppr_on_hrm[] = {LCTL_T(KC_D),   LSFT_T(KC_F), COMBO_END};


combo_t key_combos[] = {
    COMBO(switch_to_main_layer, TO(0)),
    COMBO(switch_to_nav_layer, TO(2)),
    COMBO(switch_to_num_layer, TO(3)),
    COMBO(suppr_on_hrm, KC_DELETE)
    
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    
    // Default
    [0] = LAYOUT(
        KC_1,   KC_2,    KC_3,   KC_4,    KC_5,

        KC_Q,   KC_W,    KC_E,   KC_R,    KC_T,
        LGUI_T(KC_A),   LALT_T(KC_S),   LCTL_T(KC_D),   LSFT_T(KC_F),    KC_G,
        LT(4,KC_Z),   KC_X,    KC_C,   KC_V,    KC_B,
        
        LT(2, KC_SPC),    LSFT_T(KC_TAB), KC_LSFT,

        KC_6,      KC_7,   KC_8,    KC_9,   KC_0,    

        KC_Y,      KC_U,   KC_I,    KC_O,   KC_P,   
        KC_H,      RSFT_T(KC_J),   RCTL_T(KC_K),    LALT_T(KC_L),   LGUI_T(KC_SCLN), 
        KC_N,      KC_M,   KC_COMMA,KC_DOT, KC_SLSH, 
        
        KC_LCTL  , LT(3,KC_ENTER),   LT(1, KC_BSPC)
    ),


    // Ergo-L Alt-gr
    [1] = LAYOUT(
        KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,
        
        KC_CIRC, KC_NUBS,    S(KC_NUBS), KC_DLR,  KC_PERC,      
        KC_LCBR, RALT(KC_S), RALT(KC_D), KC_RCBR, KC_EQL,       
        KC_TILD, KC_LBRC,    KC_RBRC,    KC_UNDS, S(KC_9),      
        
        KC_SPC, KC_TAB, KC_LSFT,  
        
        KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10,
        
        S(KC_0), KC_AMPR, KC_ASTR,   KC_QUOT, KC_GRV,
        KC_BSLS, KC_PLUS, KC_PMNS,   KC_PSLS, KC_DQUO,
        KC_PIPE, S(KC_O), S(KC_DOT), S(KC_N), S(KC_C),
        
        
        KC_NO, KC_NO , KC_NO
    ),

    //Nav
    [2] = LAYOUT(
        KC_NO,   KC_NO,    KC_NO,   KC_NO,    KC_NO,

        KC_ESC, KC_HOME  , KC_UP   ,  KC_END ,    KC_PAGE_UP,
        LCTL(KC_A),   KC_LEFT,   KC_DOWN,   KC_RIGHT,    KC_PAGE_DOWN,
        LCTL(KC_Z),   LCTL(KC_X),    LCTL(KC_W),   LCTL(KC_V),    KC_PRINT_SCREEN,
        
        KC_NO, KC_NO , KC_NO,

        KC_NO,      KC_NO,   KC_NO,    KC_NO,   KC_NO,    

        KC_AUDIO_VOL_UP,      KC_F7,   KC_F8,    KC_F9,   KC_F12,   
        KC_AUDIO_MUTE,      KC_F4,  KC_F5,    KC_F6,   KC_F11, 
        KC_AUDIO_VOL_DOWN,      KC_F1,   KC_F2,KC_F3, KC_F10, 
        
        KC_NO, KC_NO , KC_NO
    ),

    //Numpad
    [3] = LAYOUT(
        KC_NO,  KC_NO,   KC_NO,    KC_NO,   KC_NO,    

        KC_NO,  KC_NO,   KC_NO,    KC_NO,   KC_NO,    
        KC_NO,  KC_NO,   KC_NO,    KC_NO,   KC_NO,    
        KC_NO,  KC_NO,   KC_NO,    KC_NO,   LSFT(KC_1),    
        
        KC_NO,  KC_NO, KC_BACKSPACE,

        KC_NO,  KC_NO,   KC_NO,    KC_NO,   KC_NO,    

        KC_KP_ASTERISK,      KC_P7,   KC_P8,    KC_P9,   KC_KP_PLUS,   
        KC_PSLS,      KC_P4,   KC_P5,    KC_P6,   KC_P0, 
        KC_PDOT,      KC_P1,   KC_P2, KC_P3, KC_KP_MINUS, 
        
        KC_COMMA  , KC_ENTER,   KC_BSPC
    ),

    //Mouse
    [4] = LAYOUT(
        KC_NO,  MS_WHLL,   MS_UP,    MS_WHLR,   MS_WHLU,

        KC_NO,  MS_LEFT,   MS_DOWN,   MS_RGHT,  MS_WHLD ,
        KC_NO,  KC_NO,   KC_NO,    KC_NO,   KC_NO,
        KC_NO,  KC_NO,   KC_NO,    KC_NO,   KC_NO,
        
        MS_BTN1,  MS_BTN2,   KC_NO,

        KC_NO,  MS_WHLL,   MS_UP,    MS_WHLR,   MS_WHLU,

        KC_NO,  MS_LEFT,   MS_DOWN,    MS_RGHT,  MS_WHLD,
        KC_NO,  KC_NO,   KC_NO,    KC_NO,   KC_NO,
        KC_NO,  KC_NO,   KC_NO,    KC_NO,   KC_NO, 
        
        MS_BTN1,  MS_BTN2,   KC_NO
    )


};

#ifdef OLED_ENABLE
// Rotate OLED
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

// Draw to OLED
bool oled_task_user() {
    // set cursor position
    oled_set_cursor(0, 0);

    // Caps lock status
    led_t led_state = host_keyboard_led_state();
    oled_write_ln(led_state.caps_lock ? PSTR("Caps:\n  ON") : PSTR("Caps:\n OFF"), false);


    oled_set_cursor(0,5);
    oled_write_ln_P("Lay.:", false);
    switch(get_highest_layer(layer_state)) {
        case _MAC_DEFAULT:
        oled_write_ln(" Main", false);
            break;
        case _MAC_ERGOL_ALT:
            oled_write_ln(" Ergol", false);
            break;
        case _MAC_NAV:
            oled_write_ln("Nav", false);
            break;
        case _MAC_NUMPAD:
            oled_write_ln("Num", false);
            break;
        case _MAC_MOUSE:
            oled_write_ln("Mouse", false);
            break;
    
    
        }
    

    oled_set_cursor(0,10);
    // Get and display WPM
    uint8_t wpm = get_current_wpm();
    char wpm_str[16];
    snprintf(wpm_str, sizeof(wpm_str), "WPM:\n  %u", wpm);
    oled_write_ln(wpm_str, false);

    return false;
}


#endif
