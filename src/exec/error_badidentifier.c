/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_badidentifier.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 18:03:51 by ariard            #+#    #+#             */
/*   Updated: 2017/03/06 18:11:26 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int			error_badidentifier(char *name)
{
	ft_putstr_fd("`", 2);
	ft_putstr(name);
	ft_putstr_fd("' not a valid identifier", 2);
	return (1);
}
