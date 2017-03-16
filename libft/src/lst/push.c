/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 15:59:39 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/02 20:59:42 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*push(t_list **stack, int elem)
{
	ft_lstadd(stack, ft_lstnew(&elem, sizeof(elem)));
	return (*stack);
}
