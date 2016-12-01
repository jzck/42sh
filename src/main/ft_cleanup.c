/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:42:42 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/01 14:46:07 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cleanup(void)
{
	struct termios	term;

	if (tcgetattr(0, &term) == -1)
		return ;
	term.c_lflag |= ICANON | ISIG | ECHO;
	if (tcsetattr(0, TCSANOW, &term) == -1)
		return ;
}
