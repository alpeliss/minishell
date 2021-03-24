/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 15:26:39 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/17 16:02:51 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh/environement.h"

#include "msh/shared.h"
#include "carbon/mem.h"
#include "carbon/str.h"
#include "carbon/llst.h"
#include <stdio.h>

t_llst	*g_msh_env;

char **msh_env_all(void)
{
/*	char	**envp;
	size_t	len;
	size_t	i;
	t_llst	*node;

	len = llst_len(g_msh_env);
	envp = mem_calloc(sizeof(char *) * (len + 1));
	if (!envp)
		msh_exit(1, "nomem");
	i = 0;
	node = g_msh_env;
	while (i < len)
	{
		envp[i] = mem_calloc(str_len(((t_env *)node->data)->key) +
		str_len(((t_env *)node->data)->def) + 2);
		if (!envp[i])
			msh_exit(1, "nomem");
		sprintf(envp[i], "%s=%s", ((t_env *)node->data)->key,
		((t_env *)node->data)->def);
		node = node->next;
		i++;
	}*/
	return (NULL);
}
