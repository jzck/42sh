/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_is_escaped.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:44:17 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/10 13:44:17 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"

int		ft_input_is_escaped(t_dlist *input_chain)
{
	if (*(char *)input_chain->content == '\\')
		return (1);
	else
		return (0);
}
