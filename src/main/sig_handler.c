#include "minishell.h"
pid_t	g_pid;

void	sig_handler(int signo)
{
	if (signo == SIGINT)
	{
		exit(1);
		if (g_pid)
			kill(g_pid, SIGINT);
	}
}
