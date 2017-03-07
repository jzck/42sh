/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld_copy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 19:42:23 by wescande          #+#    #+#             */
/*   Updated: 2017/03/07 20:29:28 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob.h"

t_ld	*ft_ld_copy(t_ld *src, void *(*f)(void *elem))
{
	t_ld	*dst;
	void	*content;

	dst = NULL;
	while (src)
	{
		content = (*f)(src->content);
		ft_ld_pushfront(dst, content);
		src = src->next;
	}
	ft_ld_reverse(dst);
	return (dst);
}
