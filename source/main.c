#include "msh.h"

int main(int ac, char **av, char **env)
{
	t_prog pr;
	

	msh_env(env);
	pr.argc = ac - 1;
	pr.argv = &av[1];
	pr.in_fd = 0;
	pr.out_fd = 1;
//	ft_pwd(pr);
//	env_print();
	builtin_exe(pr);
//	pr.argc = 1;
//	builtin_exe(pr);
//	env_print();
//	ft_pwd(pr);
	return(0);
}
