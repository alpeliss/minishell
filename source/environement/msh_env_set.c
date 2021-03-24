#include "msh.h"

void	replace_data(t_env *old, t_env *new)
{
	if (new->def)
		old->def = new->def;
	free(new->key);
	free(new->def);
}

void	add_data(t_env *new)
{
	t_llst	*node;

	node = llst_new(new);
	if (!node)
		msh_exit(1, "nomem");
	llst_push(&g_msh_env, node);
}

void	msh_env_set(t_env *entry)
{
	t_env	*old;

	if ((old = msh_env_get(entry->key)))
		replace_data(old, entry);
	else
		add_data(entry);
}
