/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigttou_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 15:14:53 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/20 10:30:55 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sigttou_handler(int signo)
{
	(void)signo;
	DG("got SIGTTOU, pid=%i, pgid=%i", getpid(), getpgid(getpid()));
}
