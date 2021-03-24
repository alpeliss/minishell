#include "../../include/msh.h"

void	ft_pwd(t_prog pr)
{
	char	*str;
	
	str = getcwd(NULL, 0);
	write(pr.out_fd, str, str_len(str));
	write(pr.out_fd, "\n", 1);
	free(str);
}
