#include "minishell.h"

int		main(void)
{
	char	*line;

	while (1)
	{
		ft_putstr(SHELL_PROMPT);
		if (get_next_line(0, &line) == -1)
			return (1);
		ft_cmd_process(line);
	}
	return (0);
}

