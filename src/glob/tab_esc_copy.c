/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_esc_copy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 05:37:19 by wescande          #+#    #+#             */
/*   Updated: 2017/03/23 05:55:01 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*tab_esc_copy(void *content)
{
	char **ch_cont;

	ch_cont = (char **)content;
	return (gen_tab(ch_cont[0],
				(unsigned char *)ch_cont[1],
				(unsigned char *)ch_cont[2], 1));
}
