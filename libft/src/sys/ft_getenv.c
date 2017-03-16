/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:15:45 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/01 12:29:25 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_getenv(char **env, char *key)
{
	if (!env)
		return (NULL);
	while (*env)
	{
		if (ft_strcmp(*env, key) == '=')
			return (*env + ft_strlen(key) + 1);
		env++;
	}
	return (NULL);
}
