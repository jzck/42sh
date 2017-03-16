/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:04:37 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/03 18:04:37 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcut(char *str, char *cut)
{
	char	*target;

	while ((target = ft_strstr(str, cut)))
	{
		ft_strcpy(target, target + ft_strlen(cut));
	}
	return (str);
}
