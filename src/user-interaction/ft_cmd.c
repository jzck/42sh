#include "minishell.h"

int		ft_cmd_process(char **argv, char ***env_p)
{
	char	**path;
	char	*execpath;

	path = ft_strsplit(ft_env_getval(*env_p, "PATH"), ':');
	ft_expand_dollar(argv, *env_p);
	if (ft_builtin(argv, env_p))
		return (0);
	else if (ft_strchr(argv[0], '/'))
		execpath = argv[0];
	else if (!(execpath = ft_path_findexec(path, argv[0])))
		return (-1);
	ft_printf("%s @ %s\n", argv[0], execpath);
	return (ft_cmd_exec(execpath, argv, env_p));
}

int		ft_cmd_exec(char *execpath, char **argv, char ***env_p)
{
	pid_t	pid;
	int		status;
	char	**environ;
	char	**sstr;

	sstr = NULL;
	if (ft_path_access(execpath, argv[0]))
		return (-1);
	if ((pid = fork()) == -1)
		return (-1);
	else if (pid == 0)
	{
		environ = ft_sstrdup(*env_p);
		execve(execpath, argv, environ);
	}
	else
	{
		wait(&status);
		sstr = ft_sstradd(sstr, "?");
		sstr = ft_sstradd(sstr, ft_itoa(status));
		builtin_setenv(sstr, env_p);
	}
	return (0);
}

char	**ft_cmd_getav(char *cmd)
{
	return (ft_split_whitespaces(cmd));
}
