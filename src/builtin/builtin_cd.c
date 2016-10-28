#include "minishell.h"
#define CDOPT_L 0b001
#define CDOPT_P 0b010
#define HAS_CDOPT_P(x) (x & CD_OPT_P)
#define HAS_CDOPT_L(x) (x & CD_OPT_L)
#define CDERR_1 "cd: string not in pwd: %s\n"
#define CDERR_2 "cd: no such file or directory: %s\n"

int		builtin_cd(char **av, char ***env_p)
{
	int		i;
	int		opts;
	char	*target;
	char	*oldpwd[2];
	char	*pwd[2];

	opts = 0;
	i = builtin_cd_opts(av, &opts);
	target = builtin_cd_special(av + i, *env_p);
	oldpwd[0] = ft_strdup("OLDPWD");
	oldpwd[1] = getcwd(NULL, 0);
	if (chdir(target))
	{
		ft_printf(CDERR_2, target);
		return (1);
	}
	else if (target != av[i])
		ft_printf("%s\n", target);
	pwd[0] = ft_strdup("PWD");
	pwd[1] = getcwd(NULL, 0);
	builtin_setenv(pwd, env_p);
	builtin_setenv(oldpwd, env_p);
	/* { */
	/* 	printf(CDERR_1, av[-i]); */
	/* 	return (1) */
	/* } */
	return (0);
}

char	*builtin_cd_special(char **av, char **env)
{
	char	*target;

	if (!*av)
		target = ft_env_getval(env, "HOME");
	else if (ft_strcmp(*av, "-") == 0)
		target = ft_env_getval(env, "OLDPWD");
	else
		target = *av;
	return (target);
}

int		builtin_cd_opts(char **av, int *opts)
{
	int		i;
	int		j;
	int		tmp_opts;

	i = 1;
	tmp_opts = 0;
	if (av)
		while (av[i] && av[i][0] == '-' && av[i][1])
		{
			j = 0;
			while (av[i][++j])
			{
				if (av[i][j] == 'P')
					tmp_opts |= CDOPT_P;
				else if (av[i][j] == 'L')
					tmp_opts |= CDOPT_L;
				else
					return (i);
			}
			*opts |= tmp_opts;
			i++;
		}
	return (i);
}
