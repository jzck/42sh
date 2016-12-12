/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 17:37:04 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/12 17:51:20 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern char	**environ;
extern char PC;
extern char *UP;
extern char *BC;

void	shell_exit(void)
{
	DG("cleanup. char * UP at %p", UP);
	DG("cleanup. char * BC at %p", BC);
	data_exit();
	tcsetattr(0, TCSANOW, &data_singleton()->jobc.shell_tmodes);
}
