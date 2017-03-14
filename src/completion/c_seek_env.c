/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_seek_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 15:50:24 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/14 10:10:19 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	c_storing(t_comp *c, char *value)
{
	t_clst			*tmp;

	if (!(tmp = (t_clst *)malloc(sizeof(t_clst))))
		return (-1);
	tmp->name = value;
	tmp->len = ft_strlen(tmp->name);
	tmp->type = 10;
	tmp->cursor = 0;
	c_add_to_lst(c, tmp);
	return (0);
}

int			c_seek_env(t_comp *c, char *current_word)
{
	char	*match;
	char	**env;
	int		i;

	i = 0;
	env = data_singleton()->env;
	match = ft_strdupi_w(current_word + 1);
	while (env[i])
	{
		if (!ft_strncmp(match, env[i], ft_strlen(match)))
			c_storing(c, ft_strndup(env[i], ft_strchr(env[i], '=') - env[i]));
		++i;
	}
	return (0);
}
