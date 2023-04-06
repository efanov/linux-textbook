#include <stdio.h>
#include <stdlib.h>

extern char etext, edata, end; /* The symbols must have some type,
                                  or "gcc -Wall" complains */

int
main(int argc, char *argv[])
{
   printf("First address past:\n");
   printf("    program text (etext)      %10lp\n", &etext);
   printf("    initialized data (edata)  %10lp\n", &edata);
   printf("    uninitialized data (end)  %10lp\n", &end);

   exit(EXIT_SUCCESS);
}

