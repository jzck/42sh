/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curs_single.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 17:04:53 by sbenning          #+#    #+#             */
/*   Updated: 2017/01/21 22:23:28 by ariard           ###   ########.fr       */
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
