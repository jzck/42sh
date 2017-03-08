/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 13:44:36 by wescande          #+#    #+#             */
/*   Updated: 2017/03/07 21:19:39 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*ft_memrealloc(void *ptr, size_t old_s, size_t new_s)
{
	void	*n_ptr;

	if (!ptr)
		return (ft_memalloc(new_s));
	if (!old_s)
	{
		ft_memdel(&ptr);
		return (ft_memalloc(new_s));
	}
	n_ptr = ft_memalloc(new_s);
	ft_memcpy(n_ptr, ptr, old_s);
	ft_memdel(&ptr);
	return (n_ptr);
}
