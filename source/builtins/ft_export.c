#include "msh.h"

void	export_no_val(t_prog pr)
{
	t_llst	*l;

	l = g_msh_env;
	while (l)
	{
		write(pr.out_fd, "declare -x ", 11);
		write(pr.out_fd, ((t_env *)l->data)->key,
				str_len(((t_env *)l->data)->key));
		if (((t_env *)l->data)->def)
		{
			write(pr.out_fd, "=\"", 2);
			write(pr.out_fd, ((t_env *)l->data)->def,
				str_len(((t_env *)l->data)->def));
			write(pr.out_fd, "\"", 1);
		}
		write(1, "\n", 1);
		l = l->next;
	}
}

void	ft_export(t_prog pr)
{
	int		i;
	t_env	*entry;

	if (pr.argc == 1)
		export_no_val(pr);
	else
	{
		i = 1;
		while (i < pr.argc)
		{
			entry = extract_data(pr.argv[i]);
			msh_env_set(entry);
			i++;
		}
	}
}
