/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:55:40 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/07 17:29:54 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_dlstdelback(t_dlist **alst, void (*del)(void *, size_t))
{
	if (alst && *alst && del)
	{
		ft_dlstdelback(&(*alst)->prev, del);
		ft_dlstdelone(alst, del);
	}
}

static void	ft_dlstdelfront(t_dlist **alst, void (*del)(void *, size_t))
{
	if (alst && *alst && del)
	{
		ft_dlstdelfront(&(*alst)->next, del);
		ft_dlstdelone(alst, del);
	}
}

void		ft_dlstdel(t_dlist **alst, void (*del)(void *, size_t))
{
	if (alst && *alst && del)
	{
		ft_dlstdelback(&(*alst)->prev, del);
		ft_dlstdelfront(&(*alst)->next, del);
		ft_dlstdelone(alst, del);
	}
}
