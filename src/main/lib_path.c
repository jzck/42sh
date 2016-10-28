#include "minishell.h"

int		ft_path_access(char *execpath, char *execname)
{
	if (access(execpath, X_OK) == -1)
	{
		ft_printf("minishell: permission denied: %s\n", execname);
		return (1);
	}
	return (0);
}

char	*ft_path_findexec(char **path, char *execname)
{
	int				i;
	DIR				*dir;
	char			*execpath;
	struct dirent	*dirent;

	i = -1;
	while (path && path[++i])
	{
		if (!(dir = opendir(path[i])))
			continue ;
		while ((dirent = readdir(dir)))
		{
			if (ft_strcmp(dirent->d_name, execname))
				continue ;
			if (path[i][ft_strlen(path[i])] != '/')
				ft_strcat(path[i], "/");
			execpath = ft_strjoin(path[i], dirent->d_name);
			return (execpath);
		}
	}
	ft_printf("minishell: command not found: %s\n", execname);
	return (NULL);
}
