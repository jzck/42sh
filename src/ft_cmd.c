#include "minishell.h"
extern char **environ;

int		ft_cmd_exec(char *cmd)
{
	pid_t	pid;
	int		status;
	char	**path;
	char	*execpath;
	char	**argv;

	path = ft_strsplit(ft_env_getval(environ, "PATH"), ':');
	argv = ft_cmd_getav(cmd);
	ft_format_vars(argv, environ);
	if (ft_builtin_exec(argv, environ) == 0)
		return (0);
	else if (ft_strchr(argv[0], '/'))
		execpath = cmd;
	else if (!(execpath = ft_path_findexec(path, argv[0])))
		return (-1);
	/* ft_printf("%s @ %s\n", argv[0], execpath); */
	if ((pid = fork()) == -1)
		return (-1);
	if (pid == 0)
		execve(execpath, argv, environ);
	else
	{
		wait(&status);
		ft_printf("child process exited with %i\n", status);
	}
	return (0);
}

char	**ft_cmd_getav(char *cmd)
{
	return (ft_split_whitespaces(cmd));
}
