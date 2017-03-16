/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xattr_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:00:52 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/05 16:48:29 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#if defined __APPLE__

int		ft_xattr_count(char *path)
{
	ssize_t		listlen;
	char		list[FT_XATTR_SIZE];
	int			i;
	int			count;

	i = 0;
	ft_bzero(list, FT_XATTR_SIZE);
	listlen = listxattr(path, list, FT_XATTR_SIZE, XATTR_NOFOLLOW);
	if (listlen == -1)
		return (-1);
	count = 0;
	while (i < listlen)
	{
		i += ft_strlen(list) + 1;
		count++;
	}
	return (count);
}

#else

int		ft_xattr_count(char *path)
{
	ssize_t		listlen;
	char		list[FT_XATTR_SIZE];
	int			i;
	int			count;

	i = 0;
	ft_bzero(list, FT_XATTR_SIZE);
	listlen = listxattr(path, list, FT_XATTR_SIZE);
	if (listlen == -1)
		return (-1);
	count = 0;
	while (i < listlen)
	{
		i += ft_strlen(list) + 1;
		count++;
	}
	return (count);
}

#endif
