#ifndef BUILTINS_H
#define BUILTINS_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "unistd.h"
#include "stdio.h"
#include "stdlib.h"
#include "errno.h"
#include "string.h"
#include "parser.h"

void	builtin_exe(t_prog pr);

void	ft_pwd(t_prog pr);
void	ft_cd(t_prog pr);
void	ft_echo(t_prog pr);
void	ft_export(t_prog pr);
void	ft_unset(t_prog pr);
void	ft_env(t_prog pr);

void	unset_env(char *str);
void	delete_env(t_llst *l);


#endif
