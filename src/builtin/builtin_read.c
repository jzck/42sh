/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 15:01:45 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/25 01:28:33 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define US_READ "read [-ers] [-u fd] [-t timeout] [-p prompt]"
#define US_READ_1 " [-n nchars] [-d delim] [name ...]"

t_cliopts	g_read_opts[] =
{
	{'d', NULL, BT_READ_LD, 0, bt_read_getdelim, 1},
	{'n', NULL, BT_READ_LN, 0, bt_read_getnchars, 1},
	{'p', NULL, BT_READ_LP, 0, bt_read_getprompt, 1},
	{'r', NULL, BT_READ_LR, 0, NULL, 0},
	{'s', NULL, BT_READ_LS, 0, NULL, 0},
	{'t', NULL, BT_READ_LT, 0, bt_read_gettimeout, 1},
	{'u', NULL, BT_READ_LU, 0, bt_read_getfd, 1},
	{0, 0, 0, 0, 0, 0},
};

int			bt_read_init(t_read *data, char **av)
{
	data->opts = 0;
	data->delim = '\n';
	data->nchars = -1;
	data->prompt = NULL;
	data->fd = 0;
	data->timeout = 0;
	data->input = NULL;
	if (isatty(STDIN))
		data->opts |= BT_READ_INTER;
	if (bt_read_terminit(data) < 0)
		exit(1);
	if ((cliopts_get(av, g_read_opts, data)))
		return (ft_perror("read"));
	return (0);
}

int			bt_read_loop(t_read *data)
{
	int		i;
	int		esc;
	int		ret;
	char	buf[2];

	esc = 0;
	i = 0;
	if (data->prompt && (data->opts & BT_READ_INTER))
		ft_printf(data->prompt);
	while (42)
	{
		if ((ret = read(data->fd, buf, 1)) <= 0)
			return (ret);
		buf[ret] = 0;
		if (!esc && *buf == data->delim)
			break ;
		esc = esc ? 0 : !(data->opts & BT_READ_LR) && (*buf == '\\');
		ft_strappend(&data->input, buf);
		if (*buf == '\n' && !(data->opts &
					(BT_READ_LR | BT_READ_LS | BT_READ_INTER)))
			ft_putstr("> ");
		if ((data->opts & BT_READ_LN) && ++i >= data->nchars)
			break ;
	}
	return (0);
}

int			bt_read_assign(t_read *data)
{
	char	*input;
	char	**names;
	char	*ifs;
	char	*tok;

	input = data->input;
	names = *data->names ? data->names : (char*[]){"REPLY", NULL};
	ifs = ft_getenv(data_singleton()->local_var, "IFS");
	if (!names[1])
		ifs = NULL;
	tok = ft_strtok(input, ifs);
	while (*names)
	{
		if (!(builtin_setenv("setenv", (char*[]){"read", *names, tok}, NULL)))
			return (1);
		ifs = names[1] ? ifs : NULL;
		tok = ft_strtok(NULL, ifs);
		names++;
	}
	return (0);
}

int			builtin_read(const char *path, char *const av[], char *const envp[])
{
	t_read	data;
	int		ret;

	(void)path;
	(void)envp;
	ret = 0;
	if ((ret = bt_read_init(&data, (char **)av)) != 0)
		SH_ERR("usage: %s%s", US_READ, US_READ_1);
	else if ((ret = bt_read_loop(&data)))
	{
		;
	}
	else if (data.input && (ret = bt_read_assign(&data)))
	{
		;
	}
	bt_read_exit(&data);
	return (ret);
}
