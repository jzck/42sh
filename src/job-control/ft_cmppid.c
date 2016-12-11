#include "minishell.h"

int		ft_cmppid(t_job *job, pid_t *pid)
{
	return (job->pid - *pid);
}
