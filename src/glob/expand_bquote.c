/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_bquote.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 17:47:53 by wescande          #+#    #+#             */
/*   Updated: 2017/02/17 18:18:36 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob.h"

/*
** expand_bquote return expansion of a string after subshell execution
** input parameters are :
**			-t_glob		*gl  -> struct of expanding
*/

static char					**gen_tab(const char *pat,
		const unsigned char *esc, int dup)
{
	char	**my_tab;

	if (!(my_tab = (char **)malloc(sizeof(char *) * 3)))
		return (NULL);
	if (dup)
	{
		my_tab[0] = ft_strdup(pat);
		my_tab[1] = ft_strdup((const char *)esc);
	}
	else
	{
		my_tab[0] = (char *)pat;
		my_tab[1] = (char *)esc;
	}
	my_tab[2] = NULL;
	return (my_tab);
}

static void					iter_on_each(t_expand *me)
{
	int				i;
	char			**my_new;
	char			*first;
	unsigned char	*second;
	t_ld			*wk_tmp;

	i = ft_tablen(me->split);
	wk_tmp = *me->wk;
	while (i--)
	{
		first = ft_strjoinf(ft_strjoin(me->s1, me->split[i]), me->str + 1, 1);
		second = calc_expand_esc(me->esc,
				ft_strlen(me->s1),
				(int [2]){ft_strlen(me->split[i]), 0},
				(int [2]){me->str - CH(*me->wk)[0], ft_strlen(me->str + 1)});
		modify_esc_split(second, me->m_esc[i],
				ft_strlen(me->s1), ft_strlen(me->split[i]));
		my_new = gen_tab(first, second, 0);
		ft_ld_pushfront(&wk_tmp, my_new);
	}
	me->wk = &wk_tmp;
}

static int					init_expand(t_expand *me, char *start)
{
	unsigned char	*esc;

	me->s1 = ft_strsub(start, 1, me->str - start - 1);
	esc = ft_sub_esc(me->esc, start - CH(*me->wk)[0] + 1, me->str - start);
	me->split = ft_strsplit_spe(me->s1, esc, ',');
	me->m_esc = ft_strsplit_esc(me->s1, esc, ',');
	ft_strdel(&me->s1);
	ft_strdel((char **)&esc);
	me->s1 = ft_strsub(CH(*me->wk)[0], 0, start - CH(*me->wk)[0]);
	iter_on_each(me);
	ft_strdel(&me->s1);
	ft_tabdel(&me->split);
	ft_tabdel((char ***)&me->m_esc);
	return (1);
}

static int					search_bquote(t_expand *me)
{
	char			*start;

	start = NULL;
	while (*me->str)
	{
		start = *me->str == '`' && !is_char_esc(me->esc, CH(*me->wk)[0],
				me->str) && !start ? me->str : start;
		if (start && start != me->str &&
			*me->str == '`' && !is_char_esc(me->esc, CH(*me->wk)[0], me->str))
		{
			return (init_expand(me, start));
//			set_char_esc(me->esc, CH(*me->wk)[0], start);
//			set_char_esc(me->esc, CH(*me->wk)[0], me->str);
//			return (2);
		}
		++me->str;
	}
	return (0);
}

void						expand_bquote(t_glob *gl)
{
	t_ld		*tmp;
	int			do_it;
	t_expand	me;

	me = (t_expand){NULL, NULL, NULL, NULL, NULL, NULL};
	do_it = 1;
	while (do_it)
	{
		do_it = 0;
		while (gl->m_pat->next && !do_it)
		{
			me.wk = &gl->m_pat;
			me.esc = UCH(gl->m_pat)[1];
			me.str = CH(gl->m_pat)[0];
			if ((tmp = gl->m_pat) &&
					(do_it = search_bquote(&me)) == 1)
				ft_ld_del(&tmp, &ft_tabdel);
			gl->m_pat = gl->m_pat->next;
		}
		gl->m_pat = ft_ld_front(gl->m_pat);
	}
}
