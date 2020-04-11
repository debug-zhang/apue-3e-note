/*
	This header includes some standardsystem headers and defines numerous constants 
	and function prototypes that we use throughout the examples in the text. 
*/
#include "../include/apue.h"
/*
	to pick up the function prototypes for opendir, readdir and closedir, 
	in addition to the definition of the dirent structure.
*/
#include <dirent.h>


int main(int argc, char *argv[]) {
	DIR				*dp;
	struct dirent	*dirp;

	if (argc != 2) {
		err_quit("usage: ls directory_name");
	}

	/*
		We take an argument from the command line, argv[1], as the name of the directory to list.
		The opendir function returns a pointer to a DIR structure, and we pass this pointer to the readdir function.
	*/
	if ((dp == opendir(argv[1])) == NULL) {
		err_sys("can't open %s", argv[1]);
	}

	while ((dirp = readdir(dp)) != NULL) {
		printf("%s\n", dirp->d_name);
	}

	closedir(dp);
	exit(0);
}
