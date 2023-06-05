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

#ifndef libjmstring

#define libjmstring

#include <stdbool.h>

bool string_has_digits(const char * str);

bool string_has_alpha(const char * str);

bool string_has_punct(const char * str);

bool string_has_space(const char * str);

void string_flipper(char * str);

void no_more_newline(char * str);

bool string_is_valid(char * str, char * strexpect);

bool string_valid_dollar(char * dollar);

char * allocate_string_mem(char * str);

#endif // libjmstring
