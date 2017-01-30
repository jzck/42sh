/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob_expand_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 17:10:34 by wescande          #+#    #+#             */
/*   Updated: 2017/01/30 17:12:02 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob.h"

static void		ft_tabprint_fd(char **mytab, int fd)
{
	int		i;

	if (!mytab || !*mytab)
		return ;
	i = 0;
	while (mytab[i])
	{
		ft_putendl_fd(mytab[i], fd);
		++i;
	}
}

void			glob_expand_token(t_list *lst, t_data *data)
{
	t_token		*token;
	int			i;
	t_type		type;

	while (lst)
	{
		i = 1;
		token = lst->content;
		type = token->type;
		while (type >> (i++ + 2))
			;
		token->expand_data = glob(token->data, token->esc, data->env);
		DG("EXPANSION DU TOKEN : %02i '%s'", i, token->data);
		ft_tabprint_fd(token->expand_data, 4);
		DG("FIN DE L'EXPANSION DU TOKEN");
		lst = lst->next;
	}
}
