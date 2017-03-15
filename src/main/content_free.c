/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 16:05:27 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/15 16:35:18 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		content_free(void *data, size_t content_size)
{
	(void)content_size;
	free(data);
}
