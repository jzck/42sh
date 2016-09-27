#include "minishell.h"

int		main(void)
{
	char	*line;

	while (1)
	{
		ft_printf(SHELL_PROMPT);
		/* if (get_next_line(0, &line) == 1) */
		/* 	continue ; */
		/* if (get_next_line(0, &line) == 0) */
		/* 	ft_cmd_exec(line); */
		if (get_next_line(0, &line) == -1)
			return (1);
		ft_cmd_exec(line);
	}
	return (0);
}

