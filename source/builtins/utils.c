#include "msh.h"

void	delete_env(t_llst *l)
{
	if (((t_env *)l->data)->key)
		free(((t_env *)l->data)->key);
	if (((t_env *)l->data)->def)
		free(((t_env *)l->data)->def);
	free(l->data);
}

void	unset_env(char *str)
{
	t_llst	*tmp;
	t_llst	*temp;
	t_env	*data;

	tmp = g_msh_env;
	data = tmp->data;
	if (!(str_cmp(data->key, str)))
	{
		g_msh_env = g_msh_env->next;
		delete_env(tmp);
		tmp = g_msh_env;
	}
	while (tmp && tmp->next)
	{
		data = tmp->next->data;
		if (!(str_cmp(data->key, str)))
		{
			temp = tmp->next->next;
			delete_env(tmp->next);
			tmp->next = temp;
		}
		tmp = tmp->next;
	}
}
