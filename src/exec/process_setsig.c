/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_setsig.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 14:08:35 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/11 14:08:37 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	process_setsig(void)
{
	/* signal(SIGINT, SIG_DFL); */
	signal(SIGQUIT, SIG_DFL);
	signal(SIGTSTP, SIG_DFL);
	signal(SIGTTIN, SIG_DFL);
	signal(SIGTTOU, SIG_DFL);
	/* signal(SIGTTIN, sigttin_handler); */
	/* signal(SIGTTOU, sigttou_handler); */
	signal(SIGCHLD, SIG_DFL);
}
