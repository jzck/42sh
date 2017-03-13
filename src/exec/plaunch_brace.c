/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plaunch_brace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 19:09:30 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/13 20:28:57 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				plaunch_brace(t_process *p)
{
	if (process_redirect(p))
	{
		set_exitstatus(1, 1);
		return (0);
	}
	ft_exec(&p->data.subshell.content);
	return (0);
}
