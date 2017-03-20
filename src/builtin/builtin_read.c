/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 15:01:45 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/20 14:24:19 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cliopts	g_read_opts[] =
{
	{'d', NULL, READ_OPT_LD, 0, bt_read_getdelim},
	{'n', NULL, READ_OPT_LN, 0, bt_read_getnchars},
	{'p', NULL, READ_OPT_LP, 0, bt_read_getprompt},
	{'r', NULL, READ_OPT_LR, 0, NULL},
	{'s', NULL, READ_OPT_LS, 0, NULL},
	{'t', NULL, READ_OPT_LT, 0, bt_read_gettimeout},
	{'u', NULL, READ_OPT_LU, 0, bt_read_getfd},
	{0, 0, 0, 0, 0},
};

void		bt_read_usage(void)
{
	ft_dprintf(2, "{red}read: usage: read [-ers] [-u fd] [-t timeout]");
	ft_dprintf(2, " [-p prompt] [-n nchars] [-d delim] [name ...]{eoc}\n");
}

int			bt_read_init(t_read *data, char **av)
{
	data->opts = 0;
	data->delim = '\n';
	data->nchars = -1;
	data->prompt = NULL;
	data->fd = 0;
	data->timeout = 0;
	data->input = NULL;
	if ((cliopts_get(av, g_read_opts, data)))
		return (ft_perror() ? 2 : 2);
	if (bt_read_terminit(data) < 0)
		return (-1);
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
	if (data->prompt)
		ft_printf(data->prompt);
	while (42)
	{
		if ((ret = read(data->fd, buf, 1)) <= 0)
			return (ret);
		buf[ret] = 0;
		if (!esc && *buf == data->delim)
			break ;
		esc = esc ? 0 : !(data->opts & READ_OPT_LR) && (*buf == '\\');
		ft_strappend(&data->input, buf);
		if (*buf == '\n' && !(data->opts & (READ_OPT_LR | READ_OPT_LS)))
			ft_putstr("> ");
		if ((data->opts & READ_OPT_LN) && ++i >= data->nchars)
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
		builtin_setenv("setenv", (char*[]){"setenv", *names, tok}, NULL);
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
		;
	else if ((ret = bt_read_loop(&data)))
		;
	else if (data.input && bt_read_assign(&data))
		ret = 1;
	if (ret == -1)
		exit(1);
	if (ret != 0)
		bt_read_usage();
	if (ret != 2)
		bt_read_exit(&data);
	return (ret);
}
