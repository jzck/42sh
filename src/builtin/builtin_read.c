/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 15:01:45 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/15 21:22:34 by jhalford         ###   ########.fr       */
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
	ft_dprintf(2, "{red}read: usage: read [-ers] [-u fd] [-t timeout] [-p prompt] [-a array] [-n nchars] [-d delim] [name ...]{eoc}\n");
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
	data->names = NULL;
	if ((cliopts_get(av, g_read_opts, data)))
		return(ft_perror());
	if (data->names)
		DG("%s,%s", data->names[0], data->names[1]);
	bt_read_terminit(data);
	return (0);
}
int		bt_read_loop(t_read *data)
{
	int		i;
	int		esc;
	char	buf[2];

	esc = 0;
	i = 0;
	if (data->prompt)
		ft_printf(data->prompt);
	while (42)
	{
		if (read(data->fd, buf, 1) <= 0)
			return (1);
		buf[1] = 0;
		if (!(data->opts &READ_OPT_LS))
			ft_putchar(*buf);
		if (!esc && *buf == data->delim)
			break ;
		esc = esc ? 0 : !(data->opts & READ_OPT_LR) && (*buf == '\\');
		ft_strappend(&data->input, buf);
		if (*buf == '\n' && !(data->opts & READ_OPT_LR))
			ft_putstr("> ");
		if ((data->opts & READ_OPT_LN) && ++i >= data->nchars)
			break ;
	}
	return (0);
}

int		bt_read_assign(t_read *data)
{
	char	*input;
	char	**names;
	char	*ifs;
	char	*start;

	input = data->input;
	names = data->names ? data->names : (char*[]){"REPLY", NULL};
	ifs = ft_getenv(data_singleton()->env, "IFS");
	start = input;
	while (*start && *names)
	{
		if (!(names[1]) || !ifs)
		{
			builtin_setenv("setenv", (char*[]){"setenv", *names, start}, NULL);
			break ;
		}
		while (*input && !ft_strchr(ifs, *input))
			input++;
		while (input && ft_strchr(ifs, *input))
			*(input++) = 0;
		builtin_setenv("setenv", (char*[]){"setenv", *names, start}, NULL);
		start = input;
		names++;
	}
	return (0);
}

int		builtin_read(const char *path, char *const av[], char *const envp[])
{
	t_read	data;
	int		ret;

	(void)path;
	(void)envp;
	ret = 0;
	if (bt_read_init(&data, (char **)av))
		ret = 2;
	else if (bt_read_loop(&data))
		ret = 1;
	else if (bt_read_assign(&data))
		ret = 1;
	if (ret != 0)
		bt_read_usage();
	if (ret != 2)
		bt_read_exit(&data);
	return (ret);
}
