#include "minishell.h"
pid_t	g_pid;
int		g_mode;

void	sig_handler(int signo)
{
	if (signo != SIGINT)
		return ;
	if (g_mode == MODE_INPUT)
	{
		ft_printf("input mode SIGINT");
	}
	else if (g_mode == MODE_EXEC)
	{
		ft_putendl("^C");
		if (g_pid)
			kill(g_pid, SIGINT);
	}
}
