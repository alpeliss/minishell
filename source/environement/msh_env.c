#include "msh.h"

t_env	*env_new(void)
{
	t_env	*entry;

	entry = mem_calloc(sizeof(t_env));
	if (!entry)
		msh_exit(1, "nomem");
	return (entry);
}

void	msh_env(char **envp)
{
	size_t	i;
	size_t	key_len;
	t_env	*entry;
	t_llst	*node;

	g_msh_env = NULL;
	i = 0;
	while (envp[i])
	{
		entry = env_new();
		key_len = 0;
		while (envp[i][key_len] != '=')
			key_len++;
		entry->key = str_sub(envp[i], 0, key_len);
		if (!entry->key)
			msh_exit(1, "nomem");
		entry->def = str_sub(envp[i], key_len + 1, str_len(envp[i]));
		if (!entry->def)
			msh_exit(1, "nomem");
		node = llst_new(entry);
		if (!node)
			msh_exit(1, "nomem");
		llst_push(&g_msh_env, node);
		i++;
	}
}

void	env_print(void)
{
	t_llst	*node;

	node = g_msh_env;
	while (node)
	{
		printf("%s = %s\n", ((t_env *)node->data)->key, ((t_env *)node->data)->def);
		node = node->next;
	}
}
