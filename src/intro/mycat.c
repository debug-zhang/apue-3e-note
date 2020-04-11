/*
	The constants STDIN_FILENO and STDOUT_FILENO are defined in <unistd.h> (included by apue.h) 
	and specify the file descriptors for standardinput and standardoutput.
*/
#include "apue.h"

#define BUFFSIZE	4096

int main(void) {
	int		n;
	char	buf[BUFFSIZE];

	/*
		The read function returns the number of bytes that are read, 
		and this value is used as the number of bytes to write. 
		When the end of the input file is encountered, read returns 0 and the program stops. 
		If a read error occurs, read returns −1.
	*/
	while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0) {
		if (write(STDOUT_FILENO, buf, n) != n) {
			err_sys("write error");
		}
	}

	if (n < 0) {
		err_sys("read error");
	}

	exit(0);
}

