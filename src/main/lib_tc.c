#include "minishell.h"

int		ft_tc_init(t_data *data)
{
	char	*term_name;
	struct termios	term;

	if ((term_name = ft_env_getval(data->env, "TERM")) == NULL)
		return (-1);
	if (tgetent(NULL, term_name) != 1)
		return (-1);
	if (tcgetattr(0, &term) == -1)
		return (-1);
	term.c_lflag &= ~(ICANON); // Met le terminal en mode canonique.
	term.c_lflag &= ~(ECHO); // les touches tapées ne s'inscriront plus dans le terminal
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (-1);
	return (0);
}
