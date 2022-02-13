/* Copyright 2021 marby3
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "formy46.h"

#ifdef RGB_MATRIX_ENABLE
    led_config_t g_led_config = { {
    // Key Matrix to LED Index LEFT
        {   5,  4,  3,  2,  1,  0  },
        {   6,  7,  8,  9, 10, 11  },
        {  17, 16, 15, 14, 13, 12  },
        {      18, 19, 20, 21, 22  },
    // Key Matrix to LED Index RIGHT
        {  23, 24, 25, 26, 27, 28  },
        {  34, 33, 32, 31, 30, 29  },
        {  35, 36, 37, 38, 39, 40  },
        {  45, 44, 43, 42, 41      }
    }, {
    // LED Index to Physical Position
        {     0,  3.5 }, {  15.2,    2 }, {  29.7,    1 }, {  44.2,   0.3 }, {  59.5,    0 },
        {  73.5,  2.7 }, {   1.7, 16.7 }, {  16.3, 15.3 }, {  30.6,  14.4 }, {  44.8, 13.6 },
        {  59.5, 13.3 }, {  73.5,   16 }, {   3.4, 29.9 }, {  17.4,  28.6 }, {  31.4, 27.7 },
        {  45.4,   27 }, {  59.5, 26.7 }, {  73.5, 29.3 }, {  54.6,  40.2 }, {  74.1, 44.7 },
        {  85.2, 53.6 }, {  95.1, 44.1 }, {    95, 63.9 },
        { 150.3,  2.7 }, { 164.3,    0 }, { 179.6,  0.3 }, { 194.1,     1 }, { 208.6,    2 },
        { 223.8,  3.5 }, { 150.3,   16 }, { 164.3, 13.3 }, {   179,  13.6 }, { 193.2, 14.4 },
        { 207.5, 15.3 }, { 222.1, 16.7 }, { 150.3, 29.3 }, { 164.3,  26.7 }, { 178.4,   27 },
        { 192.4, 27.7 }, { 206.4, 28.6 }, { 220.4, 29.9 }, { 128.8,  63.9 }, { 128.7, 44.1 },
        { 138.6, 53.6 }, { 149.7, 44.7 }, { 169.2, 40.2 }
    }, {
    // LED Index to Flag
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4
} };
#endif

