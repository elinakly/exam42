#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int picoshell(char **cmds[])
{
	int pipefd[2];
	int prev_fd = -1;
	int i = 0;
	pid_t pid;

	while (cmds[i])
	{
		int has_next = (cmds[i + 1] != 0);
		if (has_next && pipe(pipefd) == -1)
			return (1);

		pid = fork();
		if (pid == -1)
		{
			close(pipefd[0]);
			close(pipefd[1]);
			return (1);
		}
		if (pid == 0)
		{
			if (prev_fd != -1)
			{
				if (dup2(prev_fd, STDIN_FILENO) == -1)
					exit(1);
				close(prev_fd);
			}
			if (has_next)
			{
				close(pipefd[0]);
				if (dup2(pipefd[1], STDOUT_FILENO) == -1)
					exit(1);
				close(pipefd[1]);
			}
			execvp(cmds[i][0], cmds[i]);
			exit(1);
		}
		if (prev_fd != -1)
			close(prev_fd);
		if (has_next)
		{
			close(pipefd[1]);
			prev_fd = pipefd[0];
		}
		i++;
	}
	while (wait(0) > 0)
		;
	return (0);
}
