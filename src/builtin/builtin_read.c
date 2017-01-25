/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 15:01:45 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/25 16:19:50 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_read.h"

t_readopt	g_readtab[] =
{
	/* {'a', READ_OPT_LA, NULL}, */
	{'d', READ_OPT_LD, bt_read_getdelim},
	/* {'e', READ_OPT_LE, NULL}, */
	/* {'i', READ_OPT_LI, NULL}, */
	{'n', READ_OPT_LN, bt_read_getnchars},
	/* {'N', READ_OPT_UN, bt_read_getnchars}, */
	{'p', READ_OPT_LP, bt_read_getprompt},
	{'r', READ_OPT_LR, NULL},
	{'s', READ_OPT_LS, NULL},
	{'t', READ_OPT_LT, bt_read_gettimeout},
	{'u', READ_OPT_LU, bt_read_getfd},
	{0, 0, 0},
};

void		bt_read_init(t_read *data)
{
	data->opts = 0;
	data->delim = '\n';
	data->nchars = -1;
	data->prompt = NULL;
	data->timeout = -1;
	data->fd = 0;
}

t_readopt	*bt_read_getopt(char letter)
{
	int		i;

	i = 0;
	while (g_readtab[i].letter)
	{
		if (g_readtab[i].letter == letter)
			return (&g_readtab[i]);
		i++;
	}
	return (NULL);
}

int			bt_read_parse(t_read *data, char **av)
{
	int			i;
	int			j;
	int			k;
	t_readopt	*opt;

	i = 1;
	k = 0;
	while (av[i])
	{
		j = 0;
		if (av[i][j++] == '-')
		{
			if (av[i][j] == '-' && av[i][j + 1] == 0)
			{
				i++;
				break ;
			}
			while (av[i][j])
			{
				if (!(opt = bt_read_getopt(av[i][j])))
				{
					ft_dprintf(2, "{red}%s: bad option: %c{eoc}\n", SHELL_NAME, av[i][j]);
					return (2);
				}
				data->opts |= opt->flag;
				if (opt->get)
				{
					(*opt->get)(data, av[++i]);
					break ;
				}
				j++;
			}
		}
		else
			break ;
		i++;
	}
	data->names = av + i;
	return (0);
}

int		builtin_read(const char *path, char *const av[], char *const envp[])
{
	t_read	data;
	int		i;
	char	buf[2];
	char	*input;
	int		esc;

	(void)path;
	(void)envp;
	input = NULL;
	bt_read_init(&data);
	if ((bt_read_parse(&data, (char **)av)))
		return (2);
	DG("read_opts: %b", data.opts);
	DG("\ndelim=%c\nnchars=%i\nprompt=%s\ntimeout=%i\nfd=%i",
		data.delim, data.nchars, data.prompt, data.timeout, data.fd);
	ft_sstrprint(data.names, ',');
	bt_read_terminit(&data);
	i = 0;
	esc = 0;
	if (data.prompt)
		ft_printf(data.prompt);
	while (42)
	{
		if (read(data.fd, buf, 1) < 0)
			return (1);
		buf[1] = 0;
		if (!esc && *buf == data.delim)
			break ;
		esc = esc ? 0 : !(data.opts & READ_OPT_LR) && (*buf == '\\');
		ft_strappend(&input, buf);
		ft_putchar(*buf);
		i++;
		if (*buf == '\n' && !(data.opts & READ_OPT_LR))
			ft_putstr("> ");
		if ((data.opts & READ_OPT_LN) && i >= data.nchars)
			break ;
	}
	ft_putchar('\n');
	DG("input=%s", input);
	bt_read_termexit();
	return (0);
}
