/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_read_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 18:25:22 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/05 15:28:10 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_readopt	*bt_read_getopt(char letter)
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

int					bt_read_parse(t_read *data, char **av)
{
	int			i;
	int			j;
	t_readopt	*opt;

	i = 1;
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
	data->names = av[i] ? av + i : NULL;
//	DG("read_opts: %b", data->opts);
	DG("\ndelim=%c\nnchars=%i\nprompt=%s\ntimeout=%i\nfd=%i",
		data->delim, data->nchars, data->prompt, data->timeout, data->fd);
	return (0);
}

int					bt_read_init(t_read *data, char **av)
{
	data->opts = 0;
	data->delim = '\n';
	data->nchars = -1;
	data->prompt = NULL;
	data->fd = 0;
	data->input = NULL;
	if ((bt_read_parse(data, av)))
		return (1);
	if (data->names)
		DG("%s,%s", data->names[0], data->names[1]);
	bt_read_terminit(data);
	return (0);
}
