#include "apue.h"

int
main(void)
{
	char name[L_tmpnam], line[MAXLINE];
	FILE *fp;

	/* first temp name */
	printf("%s\n", tmpnam(NULL));

	/* second temp name */
	tmpnam(name);
	printf("%s\n", name);

	/* create temp file */
	if ((fp = tmpfile()) == NULL) {
		err_sys("tmpfile error");
	}
	
	/* write to temp file */
	fputs("one line of output\n", fp);
	
	/* read it back */
	rewind(fp);

	if (fgets(line, sizeof(line), fp) == NULL) {
		err_sys("fgets error");
	}
	/* print the line we wrote */
	fputs(line, stdout);

	exit(0);
}
