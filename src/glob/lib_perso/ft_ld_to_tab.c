/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld_to_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 16:17:00 by wescande          #+#    #+#             */
/*   Updated: 2017/03/07 21:20:05 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_ld_to_tab(t_ld *ld)
{
	char	**my_tab;
	int		nb_item;
	int		index;

	if (!ld)
		return (NULL);
	nb_item = ft_ld_size(ld);
	if (!(my_tab = (char **)malloc(sizeof(char *) * (nb_item + 1))))
		return (NULL);
	index = 0;
	while (ld)
	{
		my_tab[index++] = ft_strdup((char *)ld->content);
		ld = ld->next;
	}
	my_tab[index] = NULL;
	return (my_tab);
}
