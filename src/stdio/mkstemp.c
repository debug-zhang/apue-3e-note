#include "apue.h"
#include <errno.h>

void make_temp(char *template);

int
main()
{
	/* right way */
	char good_template[] = "/tmp/dirXXXXXX";
	/* wrong way */
	char *bad_template = "/tmp/dirXXXXXX";

	printf("trying to create first temp file...\n");
	make_temp(good_template);
	
	printf("trying to create second temp file...\n");
	make_temp(bad_template);

	/*
	 * The difference in behavior comes from 
	 * the way the two template strings are declared. 
	 * For the first template, the name is allocated on the stack, 
	 * because we use an array variable. 
	 * For the second name, however, we use a pointer.
	 * In this case, only the memory 
	 * for the pointer itself resides on the stack; 
	 * the compiler arranges for the string to be stored 
	 * in the read-only segment of the executable. 
	 * When the mkstemp function tries to modify the string, 
	 * a segmentation fault occurs.
	*/
	
	exit(0);
}

void
make_temp(char *template)
{
	int fd;
	struct stat sbuf;

	if ((fd = mkstemp(template)) < 0) {
		err_sys("can't create temp file");
	}
	printf("temp name = %s\n", template);
	close(fd);

	if (stat(template, &sbuf) < 0) {
		if (errno == ENOENT) {
			printf("file doesn't exist\n");
		} else {
			err_sys("stat failed");
		}
	} else {
		printf("file exists\n");
		unlink(template);
	}
}
