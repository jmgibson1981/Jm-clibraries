/*
Copyright <2023> <Jason Gibson>

This program is free software: you can redistribute it and/or modify it under
the terms of the GNU Lesser General Public License as published by the Free
Software Foundation, either version 3 of the License, or (at your option) any
later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along
with this program. If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef libjmgeneral

#include <stdbool.h>

#define libjmgeneral

void clear_stdout(void);

char * prompt_scan_f(char * prompt, int a);

bool valid_input(char * str);

char * home_file_paths(char * name, char * type);

int random_gen(int low, int high);

void char_flip(char * a, char * b);

void int_flip(int * a, int * b);

void float_flip(float * a, float * b);

#endif // libjmgeneral
