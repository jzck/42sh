/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 14:19:48 by gwojda            #+#    #+#             */
/*   Updated: 2017/01/19 16:43:16 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_init_line(void)
{
	data_singleton()->line.input = NULL;
	data_singleton()->line.prompt_size = 0;
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
	static t_list_history	*head = NULL;

	ft_prompt();
	if (tcsetattr(0, TCSADRAIN, ft_stats_term_termcaps()) == -1)
		return (-1);
	data_singleton()->line.input = ft_lecture(head);
	ft_putstr("\n");
	ft_check_quotes(&data_singleton()->line.input, head);
	if (data_singleton()->line.input)
		ft_push_back_history(&head, ft_create_history_list(data_singleton()->line.input));
	if (tcsetattr(0, TCSADRAIN, ft_save_stats_term()) == -1)
		return (-1);
	return (0);
}
