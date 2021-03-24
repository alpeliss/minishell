/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environement.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 11:02:27 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/17 15:58:07 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char **msh_env_set(char *key, char*def);

void env_print(void);

#endif
