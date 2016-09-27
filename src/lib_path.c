#include "minishell.h"

char	*ft_path_findexec(char **path, char *execname)
{
	int				i;
	DIR				*dir;
	char			*execpath;
	struct dirent	*dirent;
	struct stat		statbuf;

	i = 0;
	while (path[i])
	{
		if ((dir = opendir(path[i])))
		{
			while ((dirent = readdir(dir)))
			{
				if (ft_strcmp(dirent->d_name, execname) == 0)
				{
					if (path[i][ft_strlen(path[i])] != '/')
						ft_strcat(path[i], "/");
					execpath = ft_strjoin(path[i], dirent->d_name);
					if (stat(execpath, &statbuf) == -1)
						return (NULL);
					if (access(execpath, statbuf.st_mode) == -1)
					{
						ft_printf("minishell: permission denied: %s\n", execname);
						return (NULL);
					}
					return (execpath);
				}
			}
		}
		i++;
	}
	ft_printf("minishell: command not found: %s\n", execname);
	return (NULL);
}
