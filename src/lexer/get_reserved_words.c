/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_reserved_words.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 00:07:05 by ariard            #+#    #+#             */
/*   Updated: 2017/01/31 21:11:47 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_lexstate		get_reserved_words(char *str)
{
	if (ft_strncmp(str, "while", 5) == 0)
		return (WHILE);
	else if (ft_strncmp(str, "done", 4) == 0 && ft_isalpha(*(str + 4)) == 0)
		return (DONE);
	else if	(ft_strncmp(str, "do" , 2) == 0 && ft_isalpha(*(str + 2)) == 0)
		return (DO);
	return (0);
}
