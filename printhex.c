/*
 * A library to print a buffer as typical hex-view with highlighted regions on the console screen. 
 * Copyright (C) 2017  Ralf Stemmer <ralf.stemmer@gmx.net>
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
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

#include <printhex.h>
#include <stdio.h>
#include <stdarg.h>

#define LIBPRINTHEX_TEXTCOLOR   "\e[1;34m"
#define LIBPRINTHEX_FRAMECOLOR  "\e[0;31m"

/*
 * Because of issue #4: https://github.com/rstemmer/libprinthex/issues/4
 * the ANSI escape sequences for saving and restoring the cursor posion
 * has been changed from "\e[s" to "\e7" and "\e[u" to "\e8".
 *
 * Following stackoverflow (must be true when written on stackoverflow 🙄)
 * ESC 7/8 is more reliable than CSI s/u.
 * https://stackoverflow.com/questions/28986776/ansi-escape-sequence-save-restore-cursor-position-support
 */
#define LIBPRINTHEX_SAVECURSORPOS       "\e7"
#define LIBPRINTHEX_RESTORECURSORPOS    "\e8"

static inline void SaveCursorPosition();
static inline void GoToColumn(int column);


int printhex(void* buffer, int size, int bytesperline, ... )
{
    // The offset variables point to the text column 
    //  where the hexadecimal value and the ascii character column starts
    int hex_offset   = 4*2 + 4; // "0x00000000: "
    int ascii_offset = bytesperline*3 - 1 /*"00 " -1 because the last entry has no space */ \
                     + hex_offset \
                     + 3; /*" | "*/

    // Text column position for the hex column and the ascii column
    int hex_col = 0;
    int asc_col = ascii_offset;

    // Setup the list of color configurations
    va_list cfg;
    va_start(cfg, bytesperline);
    int cfg_next = va_arg(cfg, int);
    
    // color holds the string for the current color setting
    const char *color;
    color = LIBPRINTHEX_TEXTCOLOR;

    unsigned char *values = (unsigned char*)buffer;
    int i = 0;
    while(i < size)
    {
        // Save the "start of line" position
        SaveCursorPosition();

        // Print the address offset and the frame for the new line
        printf(LIBPRINTHEX_FRAMECOLOR "0x%08X:", i);
        GoToColumn(ascii_offset - 3);
        printf(LIBPRINTHEX_FRAMECOLOR " | \e[%iC |", bytesperline);

        // Print the values for this line
        for(int pos=0; pos<bytesperline; pos++)
        {
            // Check if a new color setup shall be set
            if(i == cfg_next)
            {
                color = va_arg(cfg, const char*);
                cfg_next = va_arg(cfg, int);
            }

            // Print the hex encoded value
            GoToColumn(hex_offset + pos*3);
            printf("%s%02X ", color, values[i] & 0xFF);

            // Print the ASCII encoded value
            GoToColumn(ascii_offset + pos);
            printf("%s%c", color, (values[i] >= ' ' && values[i] <= 0x7E) ? values[i] : '.');


            i++;
            if(i >= size) goto end;
        }

        // Start a new line
        printf("\e[0m\n");
    }

end:
    GoToColumn(ascii_offset + bytesperline);
    printf("\e[0m");
    return 0;
}

static inline void SaveCursorPosition()
{
    printf(LIBPRINTHEX_SAVECURSORPOS);
}

static inline void GoToColumn(int column)
{
    printf("%s\e[%iC", LIBPRINTHEX_RESTORECURSORPOS, column);
}

// vim: tabstop=4 expandtab shiftwidth=4 softtabstop=4

