#ifndef ENVIRONEMENT_H
#define ENVIRONEMENT_H

#include <stddef.h>
#include "../../libcarbon/include/carbon/llst.h"

typedef struct s_env
{
	char *key;
	char *def;
} t_env;

extern t_llst *g_msh_env;

void msh_env(char **envp);

char **msh_env_all(void);

t_env *msh_env_get(char *key);
t_env *env_new(void);

t_env	*extract_data(char *str);
void	msh_env_set(t_env *entry);

void env_print(void);

#endif
