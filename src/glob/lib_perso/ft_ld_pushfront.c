/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld_pushfront.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 18:32:40 by wescande          #+#    #+#             */
/*   Updated: 2017/01/05 14:17:46 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob.h"

void	ft_ld_pushfront(t_ld **alst, void *content)
{
	t_ld	*new;
	t_ld	*front;

	if (!alst || !*alst)
		return (ft_ld_new(alst, content));
	if ((new = (t_ld *)malloc(sizeof(t_ld))))
	{
		front = ft_ld_front(*alst);
		new->next = front;
		new->prev = NULL;
		new->content = content;
		front->prev = new;
		*alst = new;
	}
}
