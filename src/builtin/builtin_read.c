/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 15:01:45 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/20 19:32:44 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_read.h"

t_readopt	g_readtab[] =
{
	{'a', READ_OPT_LA, NULL},
	{'d', READ_OPT_LD, NULL},
	{'e', READ_OPT_LE, NULL},
	{'i', READ_OPT_LI, NULL},
	{'n', READ_OPT_LN, NULL},
	{'N', READ_OPT_UN, NULL},
	{'p', READ_OPT_LP, NULL},
	{'r', READ_OPT_LR, NULL},
	{'s', READ_OPT_LS, NULL},
	{'t', READ_OPT_LT, NULL},
	{'u', READ_OPT_LU, NULL},
	{0, 0, 0},
};

void	bt_read_init(t_read *data)
{
	data.delim = '\n';
	data.nchars = -1;
	data.prompt = NULL;
	data.timeout = -1;
	data.fd = 0;
}

t_readopt	bt_read_getopt(char letter)
{
	int		i;

	i = 0;
	while (g_readtab[i].letter)
	{
		if (g_readtab[i].letter == letter)
			return (g_readtab[i]);
	}
	return (NULL);
}

int		bt_read_parse(t_read *data, char **av)
{
	int			i;
	int			j;
	int			k;
	t_readopt	opt;

	while (av[i])
	{
		j = 0;
		if (av[i][j++] == '-')
		{
			if (av[i][j] == '-')
			{
				i++;
				break ;
			}
			while (av[i][j])
			{
				if (!(opt = bt_read_getopt(av[i][j])))
				{
					ft_dprintf(2, "%s: bad option: %c", SHELL_NAME, av[i][j]);
					return (2);
				}
				data->opts |= opt.flag;
				if (data->get)
				{
					(*data->get)(data, av[i + 1]);
					break ;
				}
				j++;
			}
		}
		i++;
	}
	if (av[i])
		bt_read_getnames(())
	return (0);
}

int		builtin_read(const char *path, char *const av[], char *const envp[])
{
	t_read	data;
	int		i;

	(void)path;
	(void)envp;
	bt_read_init(&data);
	if ((i = bt_read_parse(&data, (char **)av)))
		return (i);
}
