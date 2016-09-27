#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# define SHELL_PROMPT "$> "

typedef struct	s_builtin
{
	char	*name;
	int		(*f)();
}				t_builtin;

extern t_builtin	g_builtin[];

int		ft_cmd_exec(char *cmd);
char	**ft_cmd_getav(char *cmd);

int		ft_builtin_exec(char **av, char **env);
int		builtin_echo(char **av, char **env);
int		builtin_cd(char **av, char **env);
int		builtin_exit(char **av, char **env);
int		builtin_setenv(char **av, char **env);
int		builtin_unsetenv(char **av, char **env);
int		builtin_env(char **av, char **env);

void	ft_expand_vars(char **av, char **env);
char	*ft_env_getval(char **env, char *key);

int		ft_path_access(char *execpath, char *execname);
char	*ft_path_findexec(char **path, char *execname);

#endif
