/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:42:42 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/09 21:50:38 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern char	**environ;
extern char PC;
extern char *UP;
extern char *BC;

void	ft_cleanup(void)
{
	struct termios	term;

	DG("cleanup. char * UP at %p", UP);
	DG("cleanup. char * BC at %p", BC);
	if (tcgetattr(0, &term) == -1)
		return ;
	term.c_lflag |= ICANON | ISIG | ECHO;
	if (tcsetattr(0, TCSANOW, &term) == -1)
		return ;
}
