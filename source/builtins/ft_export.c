#include "msh.h"

static t_env	*env_new(void)
{
	t_env	*entry;

	entry = mem_calloc(sizeof(t_env));
	if (!entry)
		msh_exit(1, "nomem");
	return (entry);
}

void	convert_to_env(char *str)
{
	size_t	key_len;
	t_env	*entry;
	t_llst	*node;

	entry = env_new();
	key_len = 0;
	while (str[key_len] != '=' && str[key_len])
		key_len++;
	entry->key = str_sub(str, 0, key_len);
	if (!entry->key)
		msh_exit(1, "nomem");
	entry->def = str_sub(str, key_len + 1, str_len(str));
	if (!entry->def)
		msh_exit(1, "nomem");
	if (key_len == str_len(str))
	{
		free(entry->def);
		entry->def = NULL;
	}
	node = llst_new(entry);
	if (!node)
		msh_exit(1, "nomem");
	if (is_it_there(entry->key) && !entry->def)
	{
		delete_env(node);
		return ;
	}
	unset_env(entry->key);
	llst_push(&g_msh_env, node);
}

void	export_no_val(t_prog pr)
{
	t_llst	*l;

	l = g_msh_env;
	while (l)
	{
		write(pr.out_fd, "declare -x ", 11);
		write(pr.out_fd, ((t_env *)l->data)->key, 
				str_len(((t_env *)l->data)->key));
		if (((t_env *)l->data)->def)
		{
			write(pr.out_fd, "=\"", 2);	
			write(pr.out_fd, ((t_env *)l->data)->def,
				str_len(((t_env *)l->data)->def));
			write(pr.out_fd, "\"", 1);
		}
		write(1, "\n", 1);
		l = l->next;
	}
}

void	ft_export(t_prog pr)
{
	int	i;

	if (pr.argc == 1)
		export_no_val(pr);
	else
	{
		i = 1;
		while (i < pr.argc)
		{
			convert_to_env(pr.argv[i]);
			i++;
		}
	}
}
