/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 18:07:50 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/26 21:59:25 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	data_exit(void)
{
	t_data	*data;

	data = data_singleton();
	/* ft_strdel(&data->line.input); */
	ft_strdel(&data->binary);
	ft_sstrfree(data->env);
	ft_sstrfree(data->local_var);
	ft_sstrfree(data->argv);
	lexer_destroy(&data->lexer);
	parser_destroy(&data->parser);
	exec_destroy(&data->exec);
	ft_lstdel(&data->lst_func, &tree_func_free);
	ft_save_termios(-1);
	ft_free_hash_table();
	free_history_list(data->line.list_beg);
	free(data_singleton());
}
