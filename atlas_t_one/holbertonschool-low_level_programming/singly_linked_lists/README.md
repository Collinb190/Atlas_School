Learning Objectives
At the end of this project, you are expected to be able to explain to anyone, without the help of Google:

-When and why using linked lists vs arrays
-How to build and use linked lists

Requirements
-Allowed editors: vi, vim, emacs
-All files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
-All your files should end with a new line
-A README.md file, at the root of the folder of the project is mandatory
-Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
-You are not allowed to use global variables
-No more than 5 functions per file
-The functions allowed are malloc, free and exit. Any use of functions printf, puts, calloc, realloc etc… is forbidden
-You are allowed to use _putchar
-Please use this data structure for this project:

/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @len: length of the string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct list_s
{
    char *str;
    unsigned int len;
    struct list_s *next;
} list_t; 
