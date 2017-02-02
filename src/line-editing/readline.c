/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 14:19:48 by gwojda            #+#    #+#             */
/*   Updated: 2017/02/02 18:03:23 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_init_line(void)
{
	data_singleton()->line.input = NULL;
	data_singleton()->line.copy_tmp = NULL;
	data_singleton()->line.pos = 0;
	data_singleton()->line.prompt_size = 0;
	data_singleton()->line.list_size = 0;
	data_singleton()->line.list_end = NULL;
	data_singleton()->line.list_beg = NULL;
	data_singleton()->line.opt = 0;
}

void	ft_init_history(void)
{
	int		fd;
	char	*str;

	fd = open(".42sh_history", O_RDONLY);
	if (fd == -1)
		return ;
	while (get_next_line(fd, &str) > 0)
	{
		ft_push_back_history(&data_singleton()->line.list_beg,
		ft_create_history_list(str));
		free(str);
	}
	free(str);
	close(fd);
}

struct termios	*ft_save_stats_term(void)
{
	static struct termios	*term_save = NULL;

	if (!term_save)
	{
		term_save = (struct termios *)malloc(sizeof(struct termios));
		tcgetattr(0, term_save);
	}
	return (term_save);
}

struct termios	*ft_stats_term_termcaps(void)
{
	static struct termios	*term = NULL;

	if (!term)
	{
		ft_init_line();
		ft_init_history();
		term = (struct termios *)malloc(sizeof(struct termios));
		tcgetattr(0, term);
		(*term).c_lflag &= ~(ECHO | ICANON | ISIG);
		(*term).c_cc[VMIN] = 1;
		(*term).c_cc[VTIME] = 0;
	}
	return (term);
}

int		ft_readline(void)
{
	ft_save_stats_term();
	if (tcsetattr(0, TCSANOW, ft_stats_term_termcaps()) == -1)
		return (-1);
	if (data_singleton()->line.input)
		ft_strdel(&data_singleton()->line.input);
	data_singleton()->line.list_cur = data_singleton()->line.list_beg;
	data_singleton()->line.pos = 0;
	ft_prompt();
	data_singleton()->line.input = ft_read_stdin();
	ft_putchar('\n');
	ft_check_quotes(&data_singleton()->line.input);
	ft_check_heredoc(&data_singleton()->line.input);
	ft_check_backslash(&data_singleton()->line.input);
	ft_history_parsing();
	if (data_singleton()->line.input)
	{
		ft_push_back_history(&data_singleton()->line.list_beg,
		ft_create_history_list(data_singleton()->line.input));
		ft_add_in_history_file(data_singleton()->line.input);
	}
	if (tcsetattr(0, TCSANOW, ft_save_stats_term()) == -1)
		return (-1);
	return (0);
}
