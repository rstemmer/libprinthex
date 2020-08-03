/*
 * A library to print a buffer as typical hex-view with highlighted regions on the console screen. 
 * Copyright (C) 2017-2020  Ralf Stemmer <ralf.stemmer@gmx.net>
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

#ifndef PRINTHEX_H
#define PRINTHEX_H

#ifdef __cplusplus
extern "C" {
#endif

int printhex(void* buffer, int size, int bytesperline, ... );
/*
 * This function prints the bytes of a buffer as a typical hex-view to the screen.
 * Further details can be found in the related readme.
 */

#ifdef __cplusplus
}
#endif

#endif

