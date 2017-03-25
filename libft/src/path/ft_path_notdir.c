/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_notdir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:45:07 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/25 15:03:39 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_path_notdir(char *path)
{
	char	*slash;
	char	*ret;

	ret = path;
	if ((slash = ft_strrchr(path, '/')) && slash != path)
		ret = slash + 1;
	return (ret);
}
