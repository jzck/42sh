/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_getoutput.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 14:01:59 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/12 15:31:34 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#define BUF_SIZE	10

char	*command_getoutput(char *command)
{
	int			fds[2];
	t_btree		*ast;
	t_astnode	item;
	char		*output;
	char		*buf;
	int			ret;

	output = NULL;
	buf = NULL;
	item.type = TK_SUBSHELL;
	item.data.sstr = malloc(4 * sizeof(char *));
	item.data.sstr[0] = ft_strdup(data_singleton()->argv[0]);
	item.data.sstr[1] = ft_strdup("-c");
	item.data.sstr[2] = ft_strdup(command);
	item.data.sstr[3] = NULL;
	ast = btree_create_node(&item, sizeof(item));
	pipe(fds);
	dup2(fds[PIPE_WRITE], 1);
	close(fds[PIPE_WRITE]);
	ft_exec(&ast);
	/* DG("gonna parse"); */
	/* token_print(token); */
	/* if (ft_parse(&ast, &token)) */
	/* 	return (NULL); */
	/* DG("gonna exec"); */
	/* if (ft_exec(&ast)) */
	/* 	return (NULL); */

	DG("gonna read from pipe");
	while ((ret = read(fds[PIPE_READ], buf, BUF_SIZE)))
	{
		buf[ret] = 0;
		DG("read '%s' from pipe", buf);
		ft_strappend(&output, buf);
	}
	DG("finished reading from pipe");
	close(fds[PIPE_READ]);
	return (output);
}
