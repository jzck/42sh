/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 16:09:40 by wescande          #+#    #+#             */
/*   Updated: 2017/01/27 18:29:32 by wescande         ###   ########.fr       */
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

void print_esc(t_token *token)
{
	char *str = token->data;
	while (*str)
	{
		if (is_char_esc(token->esc, token->data, str))
			ft_dprintf(3, "\\%c", *str);
		else
			ft_dprintf(3, "%c", *str);
		++str;
	}
	ft_dprintf(3, "\n");
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
		glob_ret = glob(token->data, token->esc, data->env);
		print_esc(token);
		DG("%02i '%s'", i, token->data);
		ft_tabprint_fd(glob_ret, 3);
		lst = lst->next;
	}
}
