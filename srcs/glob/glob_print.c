/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 16:09:40 by wescande          #+#    #+#             */
/*   Updated: 2017/01/05 16:31:36 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob.h"

void	ft_tabprint_fd(char **mytab, int fd)
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

void	glob_print(t_list *lst, t_data *data)
{
	t_token		*token;
	int			i;
	t_type		type;
	char		**glob_ret;

	while (lst)
	{
		i = 1;
		token = lst->content;
		type = token->type;
		while (type >> (i++ + 2))
			;
		glob_ret = glob(token->data, data->env);
		DG("%02i '%s'", i, token->data);
		ft_tabprint_fd(glob_ret, 2);
		lst = lst->next;
	}
}
