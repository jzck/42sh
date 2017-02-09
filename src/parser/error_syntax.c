/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 20:15:35 by ariard            #+#    #+#             */
/*   Updated: 2017/02/09 20:31:48 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		error_syntax(t_list **lst)
{
	(void)lst;
	ft_putstr_fd("syntax error near unexepected token ';'", 2);
	return (1);
}
