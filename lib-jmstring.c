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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#ifdef __linux__

#include <lib-jmstring.h>

#else

#include "lib-jmstring.h"

#endif

/*
  This will determine if any characters in string are digits

  return true = digits found

  ARGS:
  str = string to check for digit characters
*/

bool string_has_digits(const char * str)
{
	// declare & initialize
  bool retval = false;
  
  for (int i = 0; i <= strlen(str); i++) {
    if (isdigit(str[i])) {
      retval = true;
      break;
    }
  }
  
  return(retval);
}

/*
  This will determine if any characters in string are alpha

  return true = alpha characters found (a-z)

  ARGS:
  str = string to check for alphabetic characters
*/

bool string_has_alpha(const char * str)
{
	// declare & initialize
  bool retval = false;
  
  for (int i = 0; i <= strlen(str); i++) {
    if (isalpha(str[i])) {
      retval = true;
      break;
    }
  }
  
  return(retval);
}

/*
  This will determine if any characters in string are punctuation

  return true = punctuation found

  ARGS:
  str = string to check for punctuation characters
*/

bool string_has_punct(const char * str)
{
	// declare & initialize
  bool retval = false;
  
  for (int i = 0; i <= strlen(str); i++) {
    if (ispunct(str[i])) {
      retval = true;
      break;
    }
  }
  
  return(retval);
}

/*
  This will determine if any spaces are present


  return true = spaces found

  ARGS:
  str = string to check for spaces
*/

bool string_has_space(const char * str)
{
	// declare & initialize
  bool retval = false;
  
  for (int i = 0; i <= strlen(str); i++) {
    if (strchr(str, ' ')) {
      retval = true;
      break;
    }
  }
  
  return(retval);
}

/*
  Adjusted for my own use. original source for this found at
  https://www.javatpoint.com/reverse-a-string-in-c

  This will reverse a string

  ARGS:
  str = string to flip
*/

void string_flipper(char * str)
{
	// declare & initialize
  int strsize = strlen(str);
  int temp = 0;

  for (int i = 0; i < strsize/2; i++) {
    temp = str[i];
    str[i] = str[strsize - i - 1];
    str[strsize - i - 1] = temp;
  }
}

/*
  remove trailing newline character from string

  ARGS:
  str = string to trim newline from
*/

void no_more_newline(char * str)
{
  str[strcspn(str, "\n")] = '\0';
}

/*
  return true if string is valid. direct return value check without having
  to remember it

  ARGS:
  str / strexpected = strings to compare to make sure same
*/

bool string_is_valid(char * str, char * strexpect)
{
  if  (strcmp(str, strexpect) == 0) {
    return(true);
  } else {
    return(false);
  }
}

/*
  return true if dollar value is valid

  ARGS:
  dollar = us dollar value (100.32) / (100)
*/

bool string_valid_dollar(char * dollar)
{
  // declare & initialize
  bool decimal = false;
  bool digits = true;
  bool retval = false;
  bool totalchars = false;
  int totaldigits = 0;
  int totaldec = 0;
  int len = strlen(dollar);

  // loop through deposit string to verify contents + decimal point
  for (int i = 0; i <= len; i++) {
    if (!isdigit(dollar[i])) {

      // decimal check
      if (dollar[i] == '.') {
        decimal = true;

        // valid requires a single decimal point
        totaldec++;
        if (totaldec >= 2) {
          break;
        }

        // verify legal length of deposit string
        // 2 decimal places + null terminator
        if (totalchars == false && i + 3 == len) {
          totalchars = true;
          continue;
        } else {
          break;
        }
      }

      // quit at null terminator
      if (dollar[i] == '\0') {
        break;
      }

      // anything non digit found breaks loop with false return
      digits = false;
      break;
    } else {

      // increment totaldigits for whole number validation.
      // number without decimal places.
      totaldigits++;
    }
  }
  if (totaldigits == len ||
      (digits == true &&
       decimal == true &&
       totalchars == true)) {

    retval = true;
  }
  
  return(retval);
}

/*
  return pointer to memory allocated for string
  ARGS:
  str = string to load for a return
*/

char * allocate_string_mem(char * str)
{
  char * retstr = (char*)malloc(strlen(str) * sizeof(char));
  strcpy(retstr, str);
  return(retstr);
}

/*
  return pointer to calloc allocated for string
  ARGS:
  str = string to load for a return
*/

char * callocate_string_mem(char * str)
{
  char * retstr = (char*)calloc(strlen(str),sizeof(char));
  strcpy(retstr, str);
  return(retstr);
}
