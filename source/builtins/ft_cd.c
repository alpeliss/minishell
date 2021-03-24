#include "msh.h"

void	ft_cd(t_prog pr)
{
	int	i;
	t_env	*home;

	i = 0;
	if (pr.argc == 1)
	{
		if ((home = is_it_there("HOME")))
			i = chdir(home->def);
		else
			write (pr.out_fd, "bash: cd: HOME not set\n", 23);
	}
	else		
		i = chdir(pr.argv[1]);
	if (i)
	{
		write(pr.out_fd, "bash: cd: ", 10);
		write(pr.out_fd, pr.argv[1], str_len(pr.argv[1]));
		write(pr.out_fd, ": ", 2);
		write(pr.out_fd, strerror(errno), str_len(strerror(errno)));
		write(1, "\n", 1);	
	}
}
