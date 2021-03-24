#include "msh.h"

void	ft_unset(t_prog pr)
{
	int	i;

	i = 1;
	while (i < pr.argc)
	{
		if (msh_env_get(pr.argv[i]))
			unset_env(pr.argv[i]);
		i++;
	}
}
