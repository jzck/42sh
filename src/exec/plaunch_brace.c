/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plaunch_brace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 19:09:30 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/14 00:04:09 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				plaunch_brace(t_process *p)
{
	if (IS_PIPESINGLE(*p))
	{
		if (process_redirect(p))
			set_exitstatus(1, 1);
		else
			ft_exec(&p->data.brace.content);
		return (0);
	}
	else
		return (plaunch_subshell(p));
}