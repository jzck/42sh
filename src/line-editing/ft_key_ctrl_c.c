/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_ctrl_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:44:24 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/10 13:44:24 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"

int		ft_key_ctrl_c(t_data *data, t_dlist **input_chain, char *buf)
{
	(void)data;
	(void)buf;
	char	null;

	null = '\0';
	ft_dlstdel(input_chain, ft_lst_cfree);
	*input_chain = ft_dlstnew(&null, sizeof(char));
	ft_putendl("");
	ft_prompt();
	return (0);
}
