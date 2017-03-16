/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstrtostr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:27:29 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/14 16:13:24 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_dlsttostr(t_dlist *list)
{
	char	*str;

	if (!list)
		return (NULL);
	while (list->prev)
		list = list->prev;
	str = (char *)ft_strnew(sizeof(char) * (ft_dlstsize(list) + 2));
	while (list)
	{
		ft_strcat(str, (char *)list->content);
		list = list->next;
	}
	return (str);
}
