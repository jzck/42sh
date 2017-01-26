/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curs_single.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 17:04:53 by sbenning          #+#    #+#             */
/*   Updated: 2016/12/09 16:40:41 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_curs.h"

/*
 *	Save cursor reference or return a previous saved reference
*/

t_curs				*curs_single(t_curs *curs, int set)
{
	static t_curs	*single;

	if (set)
		single = curs;
	return (single);
}
