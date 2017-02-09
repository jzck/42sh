/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 14:19:48 by gwojda            #+#    #+#             */
/*   Updated: 2017/02/09 17:03:16 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			ft_init_line(void)
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

void			ft_init_history(void)
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

struct termios	*ft_save_stats_term(int save)
{
	static struct termios	*term_save = NULL;

	if (save)
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

char	*readline(char *prompt)
{
	char	*input;

	ft_save_stats_term(1);
	if (tcsetattr(0, TCSANOW, ft_stats_term_termcaps()) == -1)
		return (NULL);
	if (STR)
		ft_strdel(&STR);
	data_singleton()->line.list_cur = data_singleton()->line.list_beg;
	POS = 0;
	prompt ? ft_putstr(prompt) : ft_prompt();
	input = ft_read_stdin();
	ft_putchar('\n');
	/* ft_check_line(); */
	/* ft_check_heredoc(&STR); */
	if (tcsetattr(0, TCSANOW, ft_save_stats_term(0)) == -1)
		return (NULL);
	return (input);

	/* ft_history_parsing(); */
	/* if (STR && (!data_singleton()->line.list_beg || */
	/* ft_strcmp(data_singleton()->line.list_beg->prev->str, STR))) */
	/* { */
	/* 	ft_push_back_history(&data_singleton()->line.list_beg, */
	/* 	ft_create_history_list(STR)); */
	/* 	ft_add_in_history_file(STR); */
	/* } */
}
