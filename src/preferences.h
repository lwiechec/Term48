/*
 * Copyright (c) 2013 Todd Mortimer
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef PREFERENCES_H_
#define PREFERENCES_H_

#include <sys/keycodes.h>
#include <libconfig.h>
#include "SDL.h"

#define PREFS_COLOR_NUM_ELEMENTS 3
#define PREFS_SYMKEYS_DEFAULT_NUM_ROWS 2

static int PREFS_VERSION = 9;

typedef struct symkey_entry_t {
	const char* name;
	const char* c;
	char flash;
	UChar* uc;
	int x, y, off_x, off_y;
	SDL_Surface* background;
	SDL_Surface* symbol;
	SDL_Surface* flash_symbol;
	SDL_Surface* key;
} symkey_entry_t;

typedef struct keypair_t {
	char from;
	char *to;
} keymap_t;

typedef struct pref_t {
	char *font_path;
	int font_size, font_color[PREFS_COLOR_NUM_ELEMENTS],
		background_color[PREFS_COLOR_NUM_ELEMENTS], screen_idle_awake,
		auto_show_vkb, metamode_doubletap_key, metamode_doubletap_delay,
		keyhold_actions, metamode_hold_key, allow_resize_columns,
		metamode_hitbox[4];
	char *tty_encoding;
	keymap_t **metamode_keys, metamode_sticky_keys, metamode_func_keys,
		sym_keys;
	int sticky_sym_key, sticky_shift_key, sticky_alt_key, *keyhold_actions_exempt;
} pref_t;

#define DEFAULT_FONT_PATH "/usr/fonts/font_repository/monotype/cour.ttf",
#define DEFAULT_FONT_SIZE 40
#define DEFAULT_TEXT_COLOR {255, 255, 255}
#define DEFAULT_BACKGROUND_COLOR {0, 0, 0}
#define DEFAULT_SCREEN_IDLE_AWAKE 0
#define DEFAULT_AUTO_SHOW_VKB 1
#define DEFAULT_METAMODE_DOUBLETAP_KEY KEYCODE_RIGHT_SHIFT
#define DEFAULT_METAMODE_DOUBLETAP_DELAY 500000000
#define DEFAULT_KEYHOLD_ACTIONS 1
#define DEFAULT_METAMODE_HOLD_KEY KEYCODE_SPACE
#define DEFAULT_ALLOW_RESIZE_COLUMNS 0
#define DEFAULT_METAMODE_HITBOX {0, 0, 100, 100}
#define DEFAULT_TTY_ENCODING "UTF-8"
#define DEFAULT_METAMODE_KEYS {{'e', "\x1b"}, {'t', "\x09"}, NULL}
#define DEFAULT_METAMODE_STICKY_KEYS {{'k', "kcuu1"}, \
                                      {'j', "kcud1"}, \
                                      {'l', "kcuf1"}, \
                                      {'h', "kcub1"}, NULL}
p#define DEFAULT_METAMODE_FUNC_KEYS {{'a', "alt_down"}, \
                                    {'c', "ctrl_down"}, \
                                    {'s', "rescreen"}, \
                                    {'v', "paste_clipboard"}, NULL}
#define DEFAULT_SYM_KEYS {{'a', "="}, {'s', "-"}, {'d', "*"}, {'f', "/"}, {'g', "\\"}, \
                          {'h', "|"}, {'j', "&"}, {'k', "'"}, {'l', "\""}, {'q', "~"}, \
                          {'w', "`"}, {'e', "{"}, {'r', "}"}, {'t', "["}, {'y', "]"},  \
                          {'u', "<"}, {'i', ">"}, {'o', '^'}, {'p', "%"}, NULL}
#define DEFAULT_STICKY_SYM_KEY 0
#define DEFAULT_STICKY_SHIFT_KEY 0
#define DEFAULT_STICKY_ALT_KEY 0
#define DEFAULT_KEYHOLD_ACTIONS_EXEMPT {KEYCODE_BACKSPACE, KEYCODE_RETURN}

int preferences_guess_best_font_size(int target_cols);

pref_t* preferences_init(const char* filename);
struct symkey_entry** construct_symkey_entries(pref_t *prefs, keymap_t **keymap_arr);

const char* keystroke_lookup(char keystroke, keymap_t **keymap_arr);

int preferences_is_keyhold_exempt(int keystroke);

#define NUM_SIZES 251;
int font_widths[NUM_SIZES] = {0, 1, 1, 2, 2, 3, 4, 4, 5, 5, 6,
                              7, 7, 8, 8, 9, 10, 10, 11, 11, 12,
                              13, 13, 14, 14, 15, 16, 16, 17, 17,
                              18, 19, 19, 20, 20, 21, 22, 22, 23,
                              23, 24, 25, 25, 26, 26, 27, 28, 28,
                              29, 29, 30, 31, 31, 32, 32, 33, 34,
                              34, 35, 35, 36, 37, 37, 38, 38, 39,
                              40, 40, 41, 41, 42, 43, 43, 44, 44,
                              45, 46, 46, 47, 47, 48, 49, 49, 50,
                              50, 51, 52, 52, 53, 53, 54, 55, 55,
                              56, 56, 57, 58, 58, 59, 59, 60, 61,
                              61, 62, 62, 63, 64, 64, 65, 65, 66,
                              67, 67, 68, 68, 69, 70, 70, 71, 71,
                              72, 73, 73, 74, 74, 75, 76, 76, 77,
                              77, 78, 79, 79, 80, 80, 81, 82, 82,
                              83, 83, 84, 85, 85, 86, 86, 87, 88,
                              88, 89, 89, 90, 91, 91, 92, 92, 93,
                              94, 94, 95, 95, 96, 97, 97, 98, 98,
                              99, 100, 100, 101, 101, 102, 103, 103,
                              104, 104, 105, 106, 106, 107, 107, 108,
                              109, 109, 110, 110, 111, 112, 112, 113,
                              113, 114, 115, 115, 116, 116, 117, 118,
                              118, 119, 119, 120, 121, 121, 122, 122,
                              123, 124, 124, 125, 125, 126, 127, 127,
                              128, 128, 129, 130, 130, 131, 131, 132,
                              133, 133, 134, 134, 135, 136, 136, 137,
                              137, 138, 139, 139, 140, 140, 141, 142,
                              142, 143, 143, 144, 145, 145, 146, 146,
                              147, 148, 148, 149, 149};

#endif /* PREFERENCES_H_ */
