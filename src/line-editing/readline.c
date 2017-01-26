/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 14:19:48 by gwojda            #+#    #+#             */
/*   Updated: 2017/01/26 13:38:29 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_init_line(void)
{
	data_singleton()->line.input = NULL;
	data_singleton()->line.prompt_size = 0;
	data_singleton()->line.list_size = 0;
	data_singleton()->line.list_end = NULL;
	data_singleton()->line.list_beg = NULL;
	data_singleton()->line.opt = 0;
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
		term = (struct termios *)malloc(sizeof(struct termios));
		tcgetattr(0, term);
		(*term).c_lflag &= ~(ECHO | ICANON | ISIG);
		(*term).c_cc[VMIN] = 1;
		(*term).c_cc[VTIME] = 0;
	}
	return (term);
}

void	ft_reset_stats_term(int signal)
{
	char	*name_term;

	if (signal == SIGWINCH)
	{
		if ((name_term = getenv("TERM")) == NULL)
			return ;
		if (tgetent(NULL, name_term) == -1)
			return ;
	}
}

int		ft_readline(void)
{
	signal(SIGWINCH, ft_reset_stats_term);
	if (tcsetattr(0, TCSANOW, ft_stats_term_termcaps()) == -1)
		return (-1);
	if (data_singleton()->line.input)
		data_singleton()->line.input = NULL;
	ft_prompt();
	data_singleton()->line.input = ft_lecture(data_singleton()->line.list_beg);
	ft_putchar('\n');
	ft_check_quotes(&data_singleton()->line.input,
	data_singleton()->line.list_beg);
	ft_check_heredoc(&data_singleton()->line.input);
	ft_check_backslash(&data_singleton()->line.input);
	ft_history_parsing();
	if (data_singleton()->line.input)
		ft_push_back_history(&data_singleton()->line.list_beg,
		ft_create_history_list(data_singleton()->line.input));
	if (tcsetattr(0, TCSANOW, ft_save_stats_term()) == -1)
		return (-1);
	return (0);
}
