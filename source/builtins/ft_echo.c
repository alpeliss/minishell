#include "../../include/msh.h"

int	is_option(char *str)
{
	int	i;

	if (!str)
		return (0);
	if (str[0] != '-')
		return (0);
	if (str[1] != 'n')
		return (0);
	i = 1;
	while (str[++i])
		if (str[i] != 'n')
			return(0);
	return (1);

}


void	ft_echo(t_prog pr)
{
	int	i;
	int	opt;
	char	*str;

	i = 1;
	opt = 1;
	while (i < pr.argc  && is_option(pr.argv[i]))
	{
		i++;
		opt = 0;
	}
	while (i < pr.argc)
	{
		if (pr.argv[i][0] == '$' && pr.argv[i][1])
		{
			str = is_it_there(&pr.argv[i][1]);
			write(pr.out_fd, str, str_len(str));
		}
		write(pr.out_fd, pr.argv[i], str_len(pr.argv[i]));
		i++;
		if (i < pr.argc)	
			write(pr.out_fd, " ", 1);
	}
	if (opt)
		write(pr.out_fd, "\n", 1);
}
