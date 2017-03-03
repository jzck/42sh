/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 14:19:48 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/03 18:29:03 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			ft_init_line(void)
{
	data_singleton()->line.input = NULL;
	data_singleton()->line.copy_tmp = NULL;
	data_singleton()->line.pos = 0;
	data_singleton()->line.prompt_size = 0;
	data_singleton()->line.list_size = 0;
	data_singleton()->line.list_end = NULL;
	data_singleton()->line.list_beg = NULL;
	data_singleton()->line.opt = 0;
}

void			ft_init_history(void)
{
	int		fd;
	char	*str;
	char	*home;
	char	*path;

	if (!(home = ft_getenv(data_singleton()->env, "HOME")))
		return ;
	path = ft_str3join(home, "/", ".42sh_history");
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return ;
	while (get_next_line(fd, &str) > 0)
	{
		ft_push_back_history(&data_singleton()->line.list_beg,
		ft_create_history_list(str));
		free(str);
	}
	free(path);
	free(str);
	close(fd);
}

struct termios	*ft_save_termios(int save)
{
	static struct termios	*term_save = NULL;

	if (save < 0)
	{
		free(term_save);
		return (NULL);
	}
	if (save > 0)
	{
		term_save = (struct termios *)malloc(sizeof(struct termios));
		tcgetattr(0, term_save);
	}
	return (term_save);
}

void	ft_init_termios(void)
{
	struct termios	term;

	tcgetattr(0, &term);
	term.c_lflag &= ~(ECHO | ICANON | ISIG);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tcsetattr(0, TCSANOW, &term);
}

void	readline_init(int prompt)
{
	static int	beg = 0;

	if (!beg)
	{
		ft_init_line();
		ft_init_history();
		ft_save_termios(1);
		beg = 1;
	}
	ft_init_termios();
	if (STR)
		ft_strdel(&STR);
	data_singleton()->line.list_cur = data_singleton()->line.list_beg;
	POS = 0;
	prompt ? ft_putstr("> ") : ft_prompt();
}

int		readline(int fd, int prompt, char **input)
{
	if (!SH_IS_INTERACTIVE(data_singleton()->opts))
	{
		if (get_next_line(fd, input) == 0)
			return (1);
		return (0);
	}
	readline_init(prompt);
	*input = ft_read_stdin();
	ft_putchar('\n');
	if (!prompt)
		*input = ft_history_parsing();
	if (tcsetattr(0, TCSANOW, ft_save_termios(0)) == -1)
		return (-1);
	return (0);
}
