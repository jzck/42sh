/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_script.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 22:50:22 by ariard            #+#    #+#             */
/*   Updated: 2017/01/22 21:24:47 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READSCRIPT_H
# define READSCRIPT_H

/*
 * input : destination buffer
 * b_size : allocated size of the destination buffer
 * used : acutal used size in the destination buffer
 * q_size : number of elements in the queue
 * queue : list of queued lines, FIFO
*/

struct s_script 
{
	char	*buffer;
	int		b_size;
	int		q_size;
	t_list	*queue;
};

typedef struct s_script	 t_script;

/*
 * Read_script setup/cleanup
*/
	
int			ft_read_script(char *file);

#endif
