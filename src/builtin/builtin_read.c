/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 15:01:45 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/27 19:40:12 by jhalford         ###   ########.fr       */
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

int		bt_read_loop(t_read *data)
{
	int		i;
	int		esc;
	int		ret;
	char	buf[2];

	i = 0;
	esc = 0;
	if (data->prompt)
		ft_printf(data->prompt);
	while (42)
	{
		if ((ret = read(data->fd, buf, 1)) <= 0)
			return (1);
		/* DG("got *buf=%c, ret=%i", *buf, ret); */
		buf[ret] = 0;
		if (!esc && *buf == data->delim)
			break ;
		esc = esc ? 0 : !(data->opts & READ_OPT_LR) && (*buf == '\\');
		ft_strappend(&data->input, buf);
		if (!(data->opts & READ_OPT_LS))
			ft_putchar(*buf);
		i++;
		if (*buf == '\n' && !(data->opts & READ_OPT_LR))
			ft_putstr("> ");
		if ((data->opts & READ_OPT_LN) && i >= data->nchars)
			break ;
	}
	ft_putchar('\n');
	DG("input=%s", data->input);
	return (0);
}

int		bt_read_assign(t_read *data)
{
	char	*input;
	char	**names;
	char	*IFS;
	char	*start;

	input = data->input;
	names = data->names ? data->names : (char*[]){"REPLY", NULL};
	IFS = ft_getenv(data_singleton()->env, "IFS");
	start = input;
	while (*start && *names)
	{
		if (!(names[1]) || !IFS)
		{
			builtin_setenv("setenv", (char*[]){"setenv", *names, start}, NULL);
			break ;
		}
		while (*input && !ft_strchr(IFS, *input))
			input++;
		while (input && ft_strchr(IFS, *input))
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
	bt_read_exit(&data);
	return (ret);
}
