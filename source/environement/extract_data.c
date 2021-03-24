#include "msh.h"

t_env	*extract_data(char *str)
{
	t_env	*entry;
	size_t	key_len;

	entry = env_new();
	key_len = 0;
	while (str[key_len] != '=' && str[key_len])
		key_len++;
	entry->key = str_sub(str, 0, key_len);
	if (!entry->key)
		msh_exit(1, "nomem");
	if (key_len == str_len(str))
	{
		entry->def = NULL;
		return (entry);
	}
	entry->def = str_sub(str, key_len + 1, str_len(str));
	if (!entry->def)
		msh_exit(1, "nomem");
	return (entry);
}
