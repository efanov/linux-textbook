/*
 * man get_phys_pages(3)
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>

int
main(int argc, char *argv[])
{
   printf("This system has %ld pages of physical memory and "
	   "%ld pages of physical memory available.\n",
	   get_phys_pages(), get_avphys_pages());
   exit(EXIT_SUCCESS);
}
