/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alao <alao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 11:21:16 by alao              #+#    #+#             */
/*   Updated: 2017/02/15 19:05:04 by alao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "completion.h"

/*
** Trim if there's many commands in a raw separed with a semi colon.
*/

static char				*c_trimmer(char *cmd, int st, int nd)
{
	char				*rt;
	int					len;

	rt = NULL;
	len = ft_strlen(cmd);
	if (st == len)
		st--;
	while (st && cmd[st] && cmd[st] != ';')
		st--;
	cmd[st] == ';' ? st++ : (0);
	while (nd < len && cmd[nd] && cmd[nd] != ';' && cmd[nd] != ' ')
		nd++;
	rt = ft_strsub(cmd, st, nd - st);
	return (rt);
}

/*
** Init the completion structure by populating the default value from the main
** structure data and call for the c_matching() function.
*/

void					c_init(t_data *s, long int input)
{
	struct winsize		win;
	int					len_trail;

	if (!(s->comp = (t_comp *)malloc((sizeof(t_comp)))))
		return ;
	s->comp->rcmd = c_trimmer(s->line.input, s->line.pos, s->line.pos);
	len_trail = ft_strlen(s->line.input) - s->line.pos;
	if (ft_strlen(s->line.input) > s->line.pos)
		s->comp->trail = ft_strsub(s->line.input, s->line.pos, len_trail);
	else
		s->comp->trail = NULL;
	s->comp->ircmd = s->line.pos;
	s->comp->match = NULL;
	s->comp->cpath = NULL;
	s->comp->lst = NULL;
	ioctl(0, TIOCGWINSZ, &win);
	s->comp->win_x = win.ws_col;
	s->comp->home = ft_strdup(ft_getenv(s->env, "HOME"));
	s->comp->pwd = ft_strdup(ft_getenv(s->env, "PWD"));
	s->comp->key = input;
	s->comp->isfolder = 0;
	s->comp->prompt = s->line.prompt_size;
	c_matching(s, s->comp);
}
