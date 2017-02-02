/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_backslash.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 13:32:52 by gwojda            #+#    #+#             */
/*   Updated: 2017/02/02 11:11:11 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_check_backslash(char **str)
{
	char	*tmp1;
	char	*tmp2;

	if (!*str || !**str)
		return ;
	if ((*str)[ft_strlen(*str) - 1] == '\\')
	{
		ft_putstr("> ");
		data_singleton()->line.prompt_size = 2;
		tmp1 = *str;
		tmp2 = ft_strjoin(tmp1, "\n");
		free(tmp1);
		tmp1 = ft_lecture(data_singleton()->line.list_beg);
		*str = ft_strjoin(tmp2, tmp1);
		free(tmp1);
		free(tmp2);
		ft_putchar('\n');
	}
}
