/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_interpreter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 15:27:25 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/17 16:24:38 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh/interpreter.h"

#include "msh/shared.h"
#include "msh/environement.h"
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int	msh_interpreter(t_llst *cmds)
{
	char	**envp;
	pid_t	child_pid;
	int		stat_loc;

	(void)cmds;
	envp = msh_env_all();
	child_pid = fork();
	if (child_pid < 0)
		msh_exit(1, "fork fail");
	else if (child_pid == 0)
	{
		printf("test\n");
		char *argv[] = {"sleep", "10", NULL};
		execve(argv[0], argv, envp);
	}
	else
	{
		waitpid(child_pid, &stat_loc, WUNTRACED);
	}
	return (0);
}
