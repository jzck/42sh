/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_to_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 15:55:53 by wescande          #+#    #+#             */
/*   Updated: 2017/03/07 15:56:25 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char			**token_to_argv(t_ld *ld, int do_match)
{
	char	**my_tab;
	int		index;
	char	**expand;
	char	**content;

	my_tab = NULL;
	while (ld)
	{
		content = ld->content;
		if ((expand = glob(content[0],
						(unsigned char *)content[1],
						(unsigned char *)content[2], do_match)))
		{
			index = -1;
			while (expand[++index])
				my_tab = ft_sstradd(my_tab, expand[index]);
			ft_tabdel(&expand);
		}
		ld = ld->next;
	}
	return (my_tab);
}
