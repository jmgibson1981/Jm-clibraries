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

#ifndef libjmfileprocessh

#include <stdio.h>

#define libjmfileprocessh

char * file_search_func(FILE * file, const char * searchstr,
                        const char * delimiter, const int field);

int file_num_lines(FILE * file);

void file_reverse_output(FILE * file, FILE * newfile, int buffer);

int highest_integer_column(FILE * file, char * delimiter, int field);

void file_null_check(FILE * file);

#endif // libjmfileprocess
