#include "apue.h"

int main(void) {
	/* getpid returns a pid_t data type */
	printf("hello world from process ID %ld\n", (long)getpid());
	exit(0);
}
