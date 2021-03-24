#include "msh.h"

void	ft_invalid(t_prog pr)
{
	write(pr.out_fd,"bash: ", 6);
	write(pr.out_fd, pr.argv[0], str_len(pr.argv[0]));
	write(pr.out_fd,": command not found\n", 20);
}


void	builtin_exe(t_prog pr)
{
	if (!pr.argc || !pr.argv)
		return ;
	if (!(str_cmp(pr.argv[0], "pwd")))
		ft_pwd(pr);
	else if (!(str_cmp(pr.argv[0], "cd")))
		ft_cd(pr);
	else if (!(str_cmp(pr.argv[0], "echo")))
		ft_echo(pr);
	else if (!(str_cmp(pr.argv[0], "export")))
		ft_export(pr);
	else if (!(str_cmp(pr.argv[0], "unset")))
		ft_unset(pr);
	else if (!(str_cmp(pr.argv[0], "env")))
		ft_env(pr);
	/*else if (!(str_cmp(pr.argv[0], "exit")))
		ft_exit(pr);*/
	else
		ft_invalid(pr);
}
