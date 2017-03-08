/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_home.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 14:11:46 by wescande          #+#    #+#             */
/*   Updated: 2017/03/08 23:30:32 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void						do_expand_home(t_bquote *me, char *home)
{
	char	**old_tab;
	char	**new_tab;

	old_tab = CH(*me->wk);
	new_tab = gen_tab(ft_strjoin(home, me->str + 1),
			calc_expand_esc(me->esc, 0,
				(int[2]){ft_strlen(home), 1},
				(int[2]){1, ft_strlen(me->str) - 1}),
			calc_expand_esc(me->esc2, 0,
				(int[2]){ft_strlen(home), 1},
				(int[2]){1, ft_strlen(me->str) - 1}), 0);
	(*me->wk)->content = new_tab;
	ft_tabdel(&old_tab);
}

void						expand_home(t_glob *gl, char *home)
{
	t_bquote	me;

	me = (t_bquote){NULL, NULL, NULL, NULL, NULL, NULL, NULL};
	gl->m_pat = ft_ld_front(gl->m_pat);
	while (gl->m_pat)
	{
		me.wk = &gl->m_pat;
		me.esc = UCH(gl->m_pat)[1];
		me.esc2 = UCH(gl->m_pat)[2];
		me.str = CH(gl->m_pat)[0];
		if (!is_char_esc(me.esc, me.str, me.str) && me.str[0] == '~')
			do_expand_home(&me, home);
		if (!gl->m_pat->next)
			break ;
		gl->m_pat = gl->m_pat->next;
	}
	gl->m_pat = ft_ld_front(gl->m_pat);
}
