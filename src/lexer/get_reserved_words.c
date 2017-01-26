/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_reserved_words.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 00:07:05 by ariard            #+#    #+#             */
/*   Updated: 2017/01/26 18:47:52 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_lexstate		get_reserved_words(char *str)
{
	if (ft_strncmp(str, "while", 5) == 0)
		return (WHILE);
	else if (ft_strncmp(str, "done", 4) == 0 
		|| ft_strncmp(str, "do" , 2) == 0)
		return (DO_GROUP);
	return (0);
}
