/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:27:20 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/07 17:35:12 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlstnew(void const *content, size_t content_size)
{
	t_dlist	*new;

	if (!content)
	{
		new = malloc(sizeof(*new));
		if (!new)
			return (NULL);
		new->content_size = 0;
		new->content = NULL;
	}
	else
	{
		new = (t_dlist *)malloc(sizeof(*new));
		if (!new)
			return (NULL);
		new->content_size = content_size;
		new->content = ft_memalloc(content_size + 1);
		ft_memcpy(new->content, content, content_size);
	}
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
