/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef KEYMAP_COMMON_H
#define KEYMAP_COMMON_H

#include <stdint.h>
#include <stdbool.h>
#include <avr/pgmspace.h>
#include "keycode.h"
#include "action.h"
#include "action_macro.h"
#include "report.h"
#include "host.h"
#include "print.h"
#include "debug.h"
#include "keymap.h"


extern const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS];
extern const uint16_t fn_actions[];


/* GH60 keymap definition macro
 * K2C, K31 and  K3C are extra keys for ISO
 */
#define KEYMAP( \
    K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K00A, K00B, K00C, K00D, K00E, K00F, \
    K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K10A, K10B, K10C, K10D, K10E, K10F, K110, K111, K112, K113, K114, \
    K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K20A, K20B, K20C, K20D, K20E, K20F, K210, K211, K212, K213, K214, \
    K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K30A, K30B, K30C, K30D, K30E, K30F, \
    K400, K401, K402, K403, K404, K405, K406, K407, K408, K409, K40A, K40B, K40C, K40D, K40E, K40F, K410, \
    K500, K501, K502, K503, K504, K505, K506, K507, K508, K509, K50A, K50B, K50C \
) { \
    { KC_##K002, KC_##K003, KC_##K004, KC_##K005, KC_##K006, KC_##K007, KC_##K008, KC_##K009, KC_##K00A, KC_##K00B, KC_##K00E, KC_##K111, KC_##K113 }, \
    { KC_##K001, KC_##K102, KC_##K105, KC_##K106, KC_##K108, KC_##K109, KC_##K10A, KC_##K10B, KC_##K10C, KC_##K00C, KC_##K00F, KC_##K112, KC_##K114 }, \
    { KC_##K000, KC_##K101, KC_##K104, KC_##K205, KC_##K107, KC_##K208, KC_##K20A, KC_##K20B, KC_##K10D, KC_##K00D, KC_##K110, KC_##K212, KC_##K213 }, \
    { KC_##K100, KC_##K201, KC_##K103, KC_##K204, KC_##K207, KC_##K307, KC_##K209, KC_##K20C, KC_##K20D, KC_##K10E, KC_##K10F, KC_##K211, KC_##K214 }, \
    { KC_##K200, KC_##K301, KC_##K202, KC_##K203, KC_##K206, KC_##K306, KC_##K308, KC_##K30B, KC_##K30C, KC_##K20E, KC_##K20F, KC_##K30D, KC_##K30F }, \
    { KC_##K300, KC_##K401, KC_##K302, KC_##K303, KC_##K305, KC_##K406, KC_##K309, KC_##K30A, KC_##K40B, KC_##K40C, KC_##K210, KC_##K30E, KC_##K40F }, \
    { KC_##K400, KC_##K501, KC_##K402, KC_##K304, KC_##K405, KC_##K407, KC_##K409, KC_##K40A, KC_##K506, KC_##K509, KC_##K50A, KC_##K40E, KC_##K410 }, \
    { KC_##K500, KC_##K502, KC_##K403, KC_##K404, KC_##K503, KC_##K408, KC_##K504, KC_##K505, KC_##K507, KC_##K508, KC_##K50B, KC_##K40D, KC_##K50C }, \
}

/* ANSI valiant. No extra keys for ISO */
#define KEYMAP_ANSI( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B,      K2D, \
    K30, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B,           K3D, \
    K40, K41, K42,           K45,                     K4A, K4B, K4C, K4D  \
) KEYMAP( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, NO,  K2D, \
    K30, NO,  K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, NO,  K3D, \
    K40, K41, K42,           K45,                NO,  K4A, K4B, K4C, K4D  \
)


#define KEYMAP_HHKB( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K49,\
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B,      K2D, \
    K30, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B,      K3D, K3C, \
    K40, K41, K42,           K45,                     K4A, K4B, K4C, K4D  \
) KEYMAP( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, NO,  K2D, \
    K30, NO,  K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D, \
    K40, K41, K42,           K45,                K49, K4A, K4B, K4C, K4D  \
)

#endif
