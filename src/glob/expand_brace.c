/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_brace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 19:00:29 by wescande          #+#    #+#             */
/*   Updated: 2017/01/28 01:13:26 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob.h"

/*
** expand_brace return expansion of a string.
** pattern searched are {ab, cd}.
** return is t_ld which first param is ab and second is cd
** input parameters are :
**			-char	*pat  -> pattern string to be looking for expand
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

static unsigned char		*calc_expand_esc(const unsigned char *esc,
		int nb_start, int nb_middle, int *nb_end)
{
	unsigned char	*new_esc;
	int				index;
	int				pos;

	if (!(new_esc = ft_memalloc(sizeof(char) *
					((nb_start + nb_middle + nb_end[1]) / 8) + 1)))
		return (NULL);
	index = -1;
	while (++index < nb_start)
		new_esc[index / 8] |=
			((esc[index / 8] >> (7 - index % 8)) & 1) << (7 - index % 8);
	pos = -1;
	while (++pos < nb_middle)
	{
		new_esc[index / 8] |= 1 << (7 - index % 8);
		++index;
	}
	pos = nb_end[0];
	while (++pos <= nb_end[0] + nb_end[1])
	{
		new_esc[index / 8] |=
			((esc[pos / 8] >> (7 - pos % 8)) & 1) << (7 - index % 8);
		++index;
	}
	return (new_esc);
}

static void					iter_on_each(t_expand *me)
{
	int				i;
	char			**my_new;
	char			*first;
	unsigned char	*second;
	t_ld			*wk_tmp;

	i = -1;
	wk_tmp = *me->wk;
	while (me->split[++i])
	{
		first = ft_strjoinf(ft_strjoin(me->s1, me->split[i]), me->str + 1, 1);
		second = calc_expand_esc(me->esc,
				ft_strlen(me->s1),
				ft_strlen(me->split[i]),
				(int[2]){me->str - CH(*me->wk)[0], ft_strlen(me->str + 1)});
		my_new = gen_tab(first, second, 0);
		ft_ld_pushfront(&wk_tmp, my_new);
	}
	me->wk = &wk_tmp;
}

static int					search_brace(t_expand *me)
{
	char	*start;

	start = NULL;
	while (*me->str)
	{
		start = *me->str == '{' && !is_char_esc(me->esc,
				CH(*me->wk)[0], me->str) ? me->str : start;
		if (*me->str == '}' && start
				&& !is_char_esc(me->esc, CH(*me->wk)[0], me->str))
		{
			me->s1 = ft_strsub(start, 1, me->str - start - 1);
			me->split = ft_strsplit(me->s1, ',');
			ft_strdel(&me->s1);
			me->s1 = ft_strsub(CH(*me->wk)[0], 0, start - CH(*me->wk)[0]);
			iter_on_each(me);
			ft_strdel(&me->s1);
			ft_tabdel(&me->split);
			return (1);
		}
		++me->str;
	}
	return (0);
}

void						expand_brace(t_glob *gl)
{
	t_ld		*tmp;
	int			do_it;
	t_expand	me;

	ft_ld_pushfront(&gl->m_pat, gen_tab("", (const unsigned char *)"", 1));
	ft_ld_pushfront(&gl->m_pat, gen_tab(gl->pat, gl->esc, 1));
	me = (t_expand){NULL, NULL, NULL, NULL, NULL};
	do_it = 1;
	while (do_it)
	{
		do_it = 0;
		while (gl->m_pat->next)
		{
			me.wk = &gl->m_pat;
			me.esc = UCH(gl->m_pat)[1];
			me.str = CH(gl->m_pat)[0];
			if ((tmp = gl->m_pat) && search_brace(&me))
			{
				ft_ld_del(&tmp, &ft_tabdel);
				do_it = 1;
			}
			gl->m_pat = gl->m_pat->next;
		}
		gl->m_pat = ft_ld_front(gl->m_pat);
	}
}
