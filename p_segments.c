/* p_segments.c

   A program that does nothing in particular, but the comments indicate
   which memory segments each type of variable is allocated in.

etext  This  is  the first address past the end of the text segment (the program code).

edata  This is the first address past the end of the initialized data segment.

end    This is the first address past the end of the uninitialized data  segment (also known as the BSS segment).

program break, which defines the end of the process's data segment (i.e., the program break is the first location after the end of the uninitialized data segment).
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern char etext, edata, end; /* The symbols must have some type, or "gcc -Wall" complains */

/* Initialized data segment */
const char var_const_data[]="ABABABABABABABAB";
char var_data[]="CDCDCDCDCDCDCDCD";
/* Uninitialized data segment (BSS) */
char var_bss;		

static int
func1(int x)                   /* Allocated in frame for func1() */
{
    int result;                 /* Allocated in frame for square() */

    printf("                    result %10lp\n", &result);
    printf("                     x   %10lp\n", &x);

    result = x * x;
    return result;              /* Return value passed via register */
}

int
main(int argc, char *argv[])    /* Allocated in frame for main() */
{
    static int var_static_data = 0x4;      /* Initialized data segment */
    static char var_static_bss[1024]; /* Uninitialized data segment */
    char *var_heap; /* Allocated in frame for main() */

    printf("Program break before malloc()    %10lp\n", sbrk(0));
    printf("Past of uninitialized data (end) %10lp\n", &end);
    var_heap = malloc(1024*8); /* Points to memory in heap segment */
    printf("Program break after malloc()     %10lp\n", sbrk(0));
    printf("                     var_heap    %10lp\n", var_heap);
    printf("Past of uninitialized data (end) %10lp\n", &end);

    func1(var_static_data);

    printf("PID = %d\n", getpid());
    printf("             Address of var_heap %10lp\n", &var_heap);
    printf("                        var_heap %10lp\n", var_heap);
    printf("Program break                    %10lp\n", sbrk(0));
    printf("Past of uninitialized data (end) %10lp\n", &end);
    printf("                var_static_bss[] %10lp\n", var_static_bss);
    printf("                         var_bss %10lp\n", &var_bss);
    printf("Past of initialized data (edata) %10lp\n", &edata);
    printf("                 var_static_data %10lp\n", &var_static_data);
    printf("                        var_data %10lp\n", var_data);
    printf("                  var_const_data %10lp\n", var_const_data);
    printf("Past of program text (etext)     %10lp\n", &etext);
    printf("Address of main()                %10lp\n", &main);
    printf("Address of func1()               %10lp\n", &func1);

    getchar();

    exit(EXIT_SUCCESS);
}
