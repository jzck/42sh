/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_process_for.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 19:38:05 by wescande          #+#    #+#             */
/*   Updated: 2017/03/14 23:12:20 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob.h"

void	*tab_esc_copy(void *content)
{
	char **ch_cont;

	ch_cont = (char **)content;
	return (gen_tab(ch_cont[0],
				(unsigned char *)ch_cont[1],
				(unsigned char *)ch_cont[2], 1));
}
