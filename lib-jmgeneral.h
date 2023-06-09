﻿/*
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

char * prompt_input_fgets(char * prompt, int a);

char * prompt_input_scanf(char * prompt, int a);

void prompt_print(char * prompt);

bool valid_input(char * str);

char * home_file_paths(char * name, char * type);

int random_gen(int low, int high);

void char_flip(char * a, char * b);

void int_flip(int * a, int * b);

void float_flip(float * a, float * b);

void prompt_fail(char * fail, char * func, char * error);

// lib-jmstring

bool string_has_digits(const char * str);

bool string_has_alpha(const char * str);

bool string_has_punct(const char * str);

bool string_has_space(const char * str);

void string_flipper(char * str);

void no_more_newline(char * str);

bool string_is_valid(char * str, char * strexpect);

bool string_valid_dollar(char * dollar);

char * allocate_string_mem(char * str);

// lib-jmfileprocess

char * file_search_func(FILE * file, const char * searchstr,
                        const char * delimiter, const int field);

int file_num_lines(FILE * file);

void file_reverse_output(FILE * file, FILE * newfile, int buffer);

int highest_integer_column(FILE * file, char * delimiter, int field);

void file_null_check(FILE * file);

#endif // libjmgeneral
