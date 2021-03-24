#include "msh.h"

void	change_directory_env(void)
{
	t_env	*old_pwd;
	t_env	*pwd;

	old_pwd = msh_env_get("OLDPWD");
	pwd = msh_env_get("PWD");
	if (old_pwd)
		old_pwd->def = pwd->def;
	if (pwd)
	{
		free(pwd->def);
		pwd->def = getcwd(NULL, 0);
	}
}

void	ft_cd(t_prog pr)
{
	int		i;
	t_env	*home;

	i = 0;
	if (pr.argc == 1)
	{
		if ((home = msh_env_get("HOME")))
			i = chdir(home->def);
		else
			write(pr.out_fd, "bash: cd: HOME not set\n", 23);
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
	change_directory_env();
}
