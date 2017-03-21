/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolz_parseur.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 16:14:46 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/21 10:03:23 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_realloc_imput(char *str, int a, size_t pos)
{
	char	tmp[2];
	char	*str_tmp;
	char	*new_str;

	tmp[0] = (char)a;
	tmp[1] = '\0';
	if (ft_strlen(str) > SIZE_LINE)
		return (str);
	if (!str)
	{
		new_str = ft_strdup(tmp);
		return (new_str);
	}
	if (!(str_tmp = ft_strndup(str, pos)))
		return (NULL);
	if (!(new_str = ft_strjoin(str_tmp, tmp)))
		return (NULL);
	free(str_tmp);
	if (!(str_tmp = ft_strjoin(new_str, str + pos)))
		return (NULL);
	free(new_str);
	free(str);
	return (str_tmp);
}

char	*ft_remove_imput(char *str, size_t pos)
{
	char	*new_str;
	char	*new_str2;

	if (!str)
		return (str);
	if (!(new_str = ft_strndup(str, pos)))
		return (NULL);
	if (!(new_str2 = ft_strjoin(new_str, &str[pos + 1])))
		return (NULL);
	free(str);
	free(new_str);
	return (new_str2);
}
