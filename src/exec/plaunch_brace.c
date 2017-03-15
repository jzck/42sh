/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plaunch_brace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 19:09:30 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/15 18:13:05 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				plaunch_brace(t_process *p)
{
	DG(" do brace");
	if (IS_PIPESINGLE(*p))
	{
		DG("is pipgesingle");
		if (process_redirect(p))
			set_exitstatus(1, 1);
		else
			ft_exec(&p->data.brace.content);
		return (0);
	}
	else
		return (plaunch_subshell(p));
}
