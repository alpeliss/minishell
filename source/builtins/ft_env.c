#include "msh.h"

void	ft_env(t_prog pr)
{
	t_llst	*l;

	l = g_msh_env;
	while (l)
	{
		if (((t_env *)l->data)->def)
		{
			write(pr.out_fd, ((t_env *)l->data)->key,
					str_len(((t_env *)l->data)->key));
			write(pr.out_fd, "=\"", 2);
			write(pr.out_fd, ((t_env *)l->data)->def,
					str_len(((t_env *)l->data)->def));
			write(pr.out_fd, "\"", 1);
			write(1, "\n", 1);
		}
		l = l->next;
	}
}
