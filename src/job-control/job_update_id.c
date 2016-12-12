/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_update_id.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 13:33:08 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/12 17:27:59 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	job_update_id(void)
{
	int		*id;
	t_jobc	*jobc;
	t_list	*start;

	jobc = &data_singleton()->jobc;
	id = &jobc->current_id;
	start = jobc->list;
	while (ft_lst_find(start, id, job_cmp_id))
	{
		*id += 1;
		DG("id = %i", *id);
	}
}
