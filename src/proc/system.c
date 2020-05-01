#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>

int
system(const char *cmdstring)	/* version without signal handling */
{
	pid_t pid;
	int status;

	if (cmdstring == NULL) {
		return (1);				/* fsalways a command processor with UNIX */
	}

	if ((pid = fork()) < 0) {
		status = -1;			/* probably out of processes */
	} else if (pid == 0) {		/* child */
		execl("/bin/sh", "sh", "-c", cmdstring, (char *)0);
		/* 
		 * Note that we call _exit instead of exit.
		 * We do this to prevent any standard I/O buffers, 
		 * which would have been copied from the parent to the child 
		 * across the fork, from being flushed in the child.
		 */
		_exit(127);				/* execl error */
	} else {					/* parent */
		while (waitpid(pid, &status, 0) < 0) {
			if (errno != EINTR) {
				status = -1;	/* error other than EINTR from waitpid() */
				break;
			}
		}
	}

	return (status);
}
