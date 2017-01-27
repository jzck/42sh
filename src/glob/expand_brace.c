/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_brace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 19:00:29 by wescande          #+#    #+#             */
/*   Updated: 2017/01/27 20:12:12 by wescande         ###   ########.fr       */
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

static char		**generate_tab(const char *pat, const char *esc, int dup)
{
	char	**my_tab;

	if (!(my_tab = (char **)malloc(sizeof(char*) * 3)))
		return (NULL);
	if (dup)
	{
		my_tab[0] = ft_strdup(pat);
		my_tab[1] = ft_strdup(esc);
	}
	else
	{
		my_tab[0] = (char *)pat;
		my_tab[1] = (char *)esc;
	}
	my_tab[2] = NULL;
	return (my_tab);
}

static char		*calc_expand_esc(const char *esc,
		int nb_start, int nb_middle, int nb_end)
{
	char	*new_esc;
	int		index;

	new_esc = ft_memalloc(sizeof(char) * (nb_start + nb_middle + nb_end) / 8);
	index = -1;
	while (++index < nb_start)
		new_esc[index / 8] |= (esc[index / 8] >> index % 8) & 1 << index % 8;
	//copy the nb_start first bit of esc.
	//append nb_middle bit at status 0
	//append nb_end last bit from end of esc.
	return (new_esc);
}

static int		search_brace(t_ld **wk, char *str, char *esc, int index)
{
	char	*start;
	char	*s1;
	char	**split;

	start = NULL;
	while (*str)
	{
		start = *str == '{' ? str : start;
		if (*str == '}' && start)
		{
			s1 = ft_strsub(start, 1, str - start - 1);
			split = ft_strsplit(s1, ',');
			ft_strdel(&s1);
			s1 = ft_strsub((*wk)->content, 0, start - (char *)(*wk)->content);
			while (split[++index])
				ft_ld_pushfront(wk, generate_tab(ft_strjoinf(ft_strjoin(s1,
				split[index]), str + 1, 1), calc_expand_esc(esc,
				ft_strlen(s1), ft_strlen(split[index]), ft_strlen(str +1)), 0));
			ft_strdel(&s1);
			ft_tabdel(&split);
			return (1);
		}
		++str;
	}
	return (0);
}

void			expand_brace(t_glob *gl)
{
	t_ld	*tmp;
	int		do_it;

	ft_ld_pushfront(&gl->m_pat, generate_tab("", "", 1));
	ft_ld_pushfront(&gl->m_pat, generate_tab(gl->pat, gl->esc, 1));
	do_it = 1;
	while (do_it)
	{
		do_it = 0;
		while (gl->m_pat->next)
		{
			if ((tmp = gl->m_pat) && search_brace(&gl->m_pat,
	((char **)gl->m_pat->content)[0],((char **)gl->m_pat->content)[1], -1))
			{
				ft_ld_del(&tmp, &ft_tabdel);
				do_it = 1;
			}
			gl->m_pat = gl->m_pat->next;
		}
		gl->m_pat = ft_ld_front(gl->m_pat);
	}
}
