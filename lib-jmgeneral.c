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
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifdef __linux__

#include <lib-jmgeneral.h>
#include <lib-jmstring.h>

#else

#include "lib-jmgeneral.h"
#include "lib-jmstring.h"

#endif

/*
  clear terminal output
*/

void clear_stdout()
{
  #ifdef _WIN32
  system("cls");
  #endif // _WIN32

  #ifdef __linux__
  printf("\e[1;1H\e[2J");
  #endif // __linux__
}

/*
  prompt for input with variable message
  ARGS:
    prompt = message for prompt
    a = size of buffer
*/

char * prompt_input(char * prompt, int a, char * type) // working
{
  // declare & initialize
  char temp[a];
	char * test = NULL;
  
  if (!string_is_valid("fgets", type) &&
      !string_is_valid("scanf", type)) {
  	prompt_fail(998);
  }
  
  
  printf("%s -> ", prompt);
  if (string_is_valid("fgets", type)) {
  	if ((test = fgets(temp, a, stdin) == NULL)) {
			prompt_fail(999);
		}
	} else if (string_is_valid("scanf", type)) {
		if ((test = scanf("%s", temp) == NULL)) {
  		prompt_fail(999);
 		}
 	}
  
  // clean up and set return pointer
  test = NULL;
  char * retval = allocate_string_mem(temp);

  return(retval);
}

/*
  prompt to validate input
*/

bool valid_input(char * str) // working
{
  // declare & initialize
  char temp = '0';
  bool retval = false;

  // prompt + verify input. if (y) return true
  printf("you entered %s. is this correct? (y|n) --> ", str);
  scanf(" %c", &temp);
  if (temp == 'y') {
    retval = true;
  }

  return(retval);
}

#if defined(_WIN32) || defined(__linux)

char * home_file_paths(char * name, char * type)
{
  char * retval = NULL;
  // valid to run function
  if (name != NULL && string_is_valid(type, "local")) {

    // length of paths for buffer allocation
    int pathlen = strlen(name);

    #ifdef __linux__
    
    int homelen = strlen(getenv("HOME"));
    
    #endif

    #ifdef _WIN32
    
    int homelen = strlen(getenv("USERPROFILE"));
    
    #endif

    char * buffer = (char*)malloc((homelen + pathlen) * sizeof(char));

    // load buffer and return
    #ifdef __linux__
    
    strcpy(buffer, getenv("HOME"));
  
  	#endif

    #ifdef _WIN32
    
    strcpy(buffer, getenv("USERPROFILE"));
    
    #endif
    
    strcat(buffer, name);
    retval = buffer;
  }

  return(retval);
}

#endif

/*
  linux uses libsodium to return a random. all else srand / rand
  ARGS:
  low = minimum number to return
  high = max number to be generated
*/

int random_gen(int low, int high)
{ 
  // declare & initialize
  int retval = 0;
  
  do {
    #ifdef __linux__
    
    #include <sodium.h>
    retval = randombytes_uniform(high);
    
    #else
    
    time_t t;
    srand((unsigned) time(&t));
    retval = rand() % high;
    
    #endif
  } while (retval < low);

  return(retval);
}

/*
  reverses a string
  ARGS:
  a, b = *a, *b
*/

void char_flip(char * a, char * b)
{
  char temp = '0';
  temp = *a;
  *a = *b;
  *b = temp;
}

/*
  flip 2 int variables
  ARGS:
  a, b = *a, *b
*/

void int_flip(int * a, int * b)
{
  int temp = 0;
  temp = *a;
  *a = *b;
  *b = temp;
}

/*
  flip 2 float variables
  ARGS:
  a, b = *a, *b
*/

void float_flip(float * a, float * b)
{
  float temp = 0.0;
  temp = *a;
  *a = *b;
  *b = temp;
}

void prompt_fail(int a)
{
	printf("failed to get input. exiting with code %d\n");
	exit(1);
}
