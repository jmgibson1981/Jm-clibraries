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

#ifdef __linux__

#include <lib-jmfileprocess.h>
#include <lib-jmstring.h>
#include <lib-jmgeneral.h>

#else

#include "lib-jmfileprocess.h"
#include "lib-jmgeneral.h"
#include "lib-jmstring.h"

#endif

/*
  USAGE :

  char * s = file_search_func(temp, "test", ",", 1);
  // do stuff with s
  free(retval);

  if you do not free the memory of the value after using it you will cause
  a memory leak.

  ARGS :
  file = file to process
  searchstr = pattern to match
  delimiter = self explanatory
  field = example: field = 3 of "fu,bar,why,how" assuming ',' for delimiter
  will return "how"
*/

char * file_search_func(FILE * file, const char * searchstr,
                      const char * delimiter, const int field) // working
{
  // declare and initialize
  char * token = NULL;
  char * loopret = NULL;
  char * retval = NULL;
  char buffer[256];
  int counter = 0;
  long unsigned int searchsize = strlen(searchstr);

  // loop until find identifier in string. typically first field
  // tokenize once found
  while (loopret == NULL) {
    if (fgets(buffer, sizeof(buffer), file)) {
      if (strstr(buffer, searchstr)) {

        // tokenize and begin processing
        token = strtok(buffer, delimiter);
        while (token) {

          // if proper value iterate until hit called field
          if (searchsize == strlen(searchstr) &&
              counter == field) {
            loopret = token;
            break;
          } else {

          // else continue to next token until found
            counter++;
            token = strtok(NULL, delimiter);
          }
        }
      }
    }

    if (feof(file) &&
        retval == NULL) {
      rewind(file);
      return(NULL);
    }
  }

  // reset file to beginning and set return value
  rewind(file);
  retval = allocate_string_mem(loopret);

  // check valid to return
  loopret = NULL;
  token = NULL;
  return(retval);
}

/*
  ARGS:
  file = file to count lines
*/

int file_num_lines(FILE * file) // working
{
  // declare and initialize
  int a = 0;
  int b = 0;

  // loop through counting number of lines
  while ((b = fgetc(file)) != EOF) {
    if  (b == '\n') {
      a++;
    }
  }

  // reset file to beginning and return
  rewind(file);
  return(a);
}

/*
  This will flip the contents of a given file and output to either stdout
  or to a new file
  ARGS:
  file = original source file
  newfile = output point (typically temp file of sorts?). NULL pointer will
  print to stdout
*/

void file_reverse_output(FILE * file, FILE * newfile, int buffer)
{
  // declare and initialize
  int lines = file_num_lines(file);
  char buf[lines][buffer];
  char str[buffer];

  // load buffer with lines
  for (int i = lines; i > 0; i--) {
    char * ptr = fgets(str, buffer, file);
    if (!ptr) {
      printf("error on line %d. check file contents.\n", i);
      exit(1);
    }

    strcpy(buf[i], ptr);
  }

  // rewind when done extracting from source file
  rewind(file);

  // output buffer in reverse order to file or screen
  for (int i = 0; i <= lines; i++) {
    if (newfile == NULL) {
      printf("%s", buf[i]);
    } else {

      fprintf(newfile, "%s", buf[i]);

      // once lines met rewind destination file for next use
      if (i == lines) {
        rewind(newfile);
      }
    }
  }
}

/*
  returns highest integer in a column based text file.
  ARGS:
  file = to work on
  field = field in text file to return
*/

int highest_integer_column(FILE * file, char * delimiter, int field)
{
  // declare & initialize
  char buffer[256];
  char * token = NULL;
  int highnum = 0;
  int tokint = 1;
  int counter = 0;

  // iterate through each line till EOF
  for (int i = 0; i <= file_num_lines(file); ++i) {
    while (fgets(buffer, sizeof(buffer), file)) {
      token = NULL;
      token = strtok(buffer, delimiter);
      while(token) {
        if (counter == field) {

          // if field = column to search then update tokint
          tokint = atoi(token);
          if (tokint > highnum) {
            highnum = tokint;
          }
          break;

        } else {

        // continue loop if not right field
          counter++;
          token = strtok(NULL, delimiter);
        }
      }
    }

    counter = 0;
  }

  rewind(file);
  return(highnum);
}
