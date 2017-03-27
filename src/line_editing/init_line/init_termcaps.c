/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_termcaps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 17:33:41 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/27 17:37:40 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

struct termios	*ft_save_termios(int save)
{
	static struct termios	*term_save = NULL;

	if (save < 0)
	{
		free(term_save);
		return (NULL);
	}
	if (save > 0)
	{
		term_save = (struct termios *)ft_malloc(sizeof(struct termios));
		tcgetattr(0, term_save);
	}
	return (term_save);
}

void			ft_init_termios(void)
{
	struct termios	term;

	tcgetattr(0, &term);
	term.c_lflag &= ~(ECHO | ICANON | ISIG);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tcsetattr(0, TCSANOW, &term);
}
