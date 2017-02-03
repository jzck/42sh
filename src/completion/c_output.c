/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_output.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alao <alao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 13:10:38 by alao              #+#    #+#             */
/*   Updated: 2017/02/03 13:52:01 by alao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "completion.h"

/*
** Output function. Will update the data->line.input along with the
** position of the cursor in data->line.pos. If the autocompletion occur in
** the middle of the command, it will join the trailing part of it. Therefor
** recreating the commands completed.
** Once that done, it will clear all the memory related and return zero.
*/

int			c_updater(t_comp *c)
{
	char		*tmp;
	char		*rt;
	int			new_pos;

	DG("\tUpdater");
	DG("RCMD [%s] match [%s] Candidat [%s]", c->rcmd, c->match, c->lst->name);
	tmp = NULL;
	rt = NULL;
	new_pos = c->ircmd + (ft_strlen(c->lst->name) - ft_strlen(c->match)) + 1;
	tmp = ft_strsub(c->rcmd, 0, ft_strlen(c->rcmd) - ft_strlen(c->match));
	rt = ft_strjoin(tmp, c->lst->name);
	tmp ? ft_memdel((void *)&tmp) : (0);
	if (c->trail)
		data_singleton()->line.input = ft_strjoin(rt, c->trail);
	else
		data_singleton()->line.input = ft_strdup(rt);
	data_singleton()->line.pos = new_pos;
	DG("Resulting RCMD [%s] with pos [%d] from [%d]", rt, new_pos, c->ircmd);
	rt ? ft_memdel((void *)&rt) : (0);
	c_clear(data_singleton());
	return (0);
}

/*
** Placeholder to clear the memory if an other key than tab is pressed to know
** if the command should be updated or not before clearing the memory.
*/

int			c_gtfo(t_comp *c, long int keypress)
{
	DG("It's time to GTFO. Keypress [%d]", keypress);
	(void)c;
	return (0);
}
