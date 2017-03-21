/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 17:37:53 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/21 15:43:51 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *data, int size)
{
	void	*new;

	new = ft_memalloc(size);
	ft_memcpy(new, data, ft_strlen(data));
	ft_memdel(&data);
	return (new);
}
