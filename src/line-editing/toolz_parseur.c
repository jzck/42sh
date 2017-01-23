/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolz_parseur.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 16:14:46 by gwojda            #+#    #+#             */
/*   Updated: 2017/01/23 13:40:41 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_realloc_imput(char *str, int a, size_t pos)
{
	int		i;
	char	tmp[2];
	char	*str_tmp;
	char	*new_str;

	i = 0;
	tmp[0] = (char)a;
	tmp[1] = '\0';
	if (!str)
	{
		new_str = ft_strdup(tmp);
		return (new_str);
	}
	str_tmp = ft_strndup(str, pos);
	new_str = ft_strjoin(str_tmp, tmp);
	free(str_tmp);
	str_tmp = ft_strjoin(new_str, str + pos);
	free(new_str);
	free(str);
	return (str_tmp);
}

char	*ft_remove_imput(char *str, size_t pos)
{
	int		i;
	char	*new_str;
	char	*new_str2;

	i = 0;
	if (!str)
		return (str);
	new_str = ft_strndup(str, pos);
	new_str2 = ft_strjoin(new_str, &str[pos + 1]);
	free(str);
	free(new_str);
	return (new_str2);
}

void	ft_found_prev_word(char *str, size_t *pos)
{
	int i;

	i = 0;
	if (!*pos)
		return ;
	if (str[*pos - 1] != '\n' && !(str[*pos] == '\n' || str[*pos] == ' '))
	{
		ft_puttermcaps("le");
		--(*pos);
	}
	while ((int)*pos - i  - 1 > 0 && str[*pos - i - 1] == ' ')
	{
		ft_puttermcaps("le");
		++i;
	}
	(*pos) = (i && str[*pos - i] == '\n') ? *pos - i + 1 : *pos - i;
	i = 0;
	if (str[*pos - 1] == '\n')
	{
		ft_puttermcaps("cd");
		(*pos) -= 2;
		ft_get_beggin(str, pos);
		ft_current_str(str, *pos);
		ft_get_next_str(str, pos);
		++(*pos);
	}
	else
	{
		if (!(str[*pos] == '\n' || str[*pos] == ' '))
		{
			ft_puttermcaps("le");
			--(*pos);
		}
		while (str[*pos - i] == '\n' || str[*pos - i] == ' ')
		{
			ft_puttermcaps("le");
			++i;
		}
		while (*pos - i && str[*pos - i] != '\n' && str[*pos - i] != ' ')
		{
			ft_puttermcaps("le");
			++i;
		}
		if (str[*pos - i] == '\n' || str[*pos - i] == ' ')
		{
			ft_puttermcaps("nd");
			++(*pos);
		}
		(*pos) -= i;
	}
}

void	ft_found_next_word(char *str, size_t *pos)
{
	int i;

	i = 0;
	while (str[i + *pos] && str[i + *pos] == ' ')
	{
		ft_putchar(str[i + *pos]);
		++i;
	}
	if (str[*pos] == '\n')
	{
		if (*pos)
		{
			--(*pos);
			ft_get_beggin_with_curs(str, pos);
		}
		ft_puttermcaps("cd");
		ft_get_next_str(str, pos);
		(*pos) += 2;
		ft_current_str(str, *pos);
		ft_get_next_str(str, pos);
		--(*pos);
		ft_get_beggin_with_curs(str, pos);
	}
	else
	{
		while (str[i + *pos] && str[i + *pos] != '\n' && str[i + *pos] != ' ')
		{
			ft_putchar(str[i + *pos]);
			++i;
		}
		*pos += i;
	}
}
