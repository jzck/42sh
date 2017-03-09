/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alao <alao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 11:21:16 by alao              #+#    #+#             */
/*   Updated: 2017/03/09 14:45:21 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "completion.h"

/*
** Trim if there's many commands in a raw separed with a semi colon.
** The cutpoint is saved and also between char **.
*/

static char				*c_trimmer(char *cmd, int st, int nd)
{
	char				*rt;
	char				*tmp;
	int					len;

	rt = NULL;
	tmp = NULL;
	len = ft_strlen(cmd);
	if (st == len)
		st--;
	while (st && cmd[st] && cmd[st] != ';')
		st--;
	cmd[st] == ';' ? st++ : (0);
	while (nd < len && cmd[nd] && cmd[nd] != ';' && cmd[nd] != ' ')
		nd++;
	rt = ft_strsub(cmd, st, nd - st);
	data_singleton()->comp->cutpoint = st;
	st = 0;
	while (rt[st] == ' ')
		st++;
	tmp = ft_strsub(rt, st, ft_strlen(rt));
	if (st)
		data_singleton()->comp->between = ft_strsub(rt, 0, st);
	rt ? ft_memdel((void *)&rt) : (0);
	return (tmp);
}

/*
** Norme function for c_init().
*/

static void				c_init_base(t_comp *c)
{
	struct winsize		win;

	ioctl(0, TIOCGWINSZ, &win);
	c->win_x = win.ws_col;
	c->win_y = win.ws_row;
	c->cutpoint = 0;
	c->between = NULL;
	c->isfolder = 0;
	c->isrematch = 0;
	c->match = NULL;
	c->cpath = NULL;
	c->lst = NULL;
	c->trail = NULL;
	c->start = NULL;
}

/*
** Init the completion structure by populating the default value from the main
** structure data and call for the c_matching() function.
*/

void				c_init(t_data *s, long int input)
{
	int					len_trail;

	if (!(s->comp = (t_comp *)malloc((sizeof(t_comp)))))
		return ;
	c_init_base(s->comp);
	s->comp->rcmd = c_trimmer(s->line.input, s->line.pos, s->line.pos);
	len_trail = ft_strlen(s->line.input) - s->line.pos;
	if (s->comp->cutpoint)
		s->comp->start = ft_strsub(s->line.input, 0, s->comp->cutpoint);
	if (ft_strlen(s->line.input) > s->line.pos)
		s->comp->trail = ft_strsub(s->line.input, s->line.pos, len_trail);
	s->comp->ircmd = s->line.pos;
	s->comp->key = input;
	s->comp->prompt = s->line.prompt_size;
	s->comp->home = ft_strdup(ft_getenv(s->env, "HOME"));
	s->comp->pwd = ft_strdup(ft_getenv(s->env, "PWD"));
	c_matching(s, s->comp);
}
