/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_tab_esc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 20:04:40 by wescande          #+#    #+#             */
/*   Updated: 2017/03/21 18:13:39 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char						**gen_tab(const char *pat,
		const unsigned char *esc,
		const unsigned char *esc2,
		int dup)
{
	char	**my_tab;
	int		len;

	if (!(my_tab = (char **)ft_malloc(sizeof(char *) * (esc2 ? 4 : 3))))
		return (NULL);
	if (dup)
	{
		len = ft_strlen(pat);
		my_tab[0] = ft_strdup(pat);
		my_tab[1] = (char *)dup_char_esc(esc, (len >> 3) + 1);
		if (esc2)
			my_tab[2] = (char *)dup_char_esc(esc2, (len >> 3) + 1);
	}
	else
	{
		my_tab[0] = (char *)pat;
		my_tab[1] = (char *)esc;
		if (esc2)
			my_tab[2] = (char *)esc2;
	}
	if (esc2)
		my_tab[3] = NULL;
	else
		my_tab[2] = NULL;
	return (my_tab);
}
