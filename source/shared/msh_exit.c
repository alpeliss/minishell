/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 10:54:59 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/02 11:54:59 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh/shared.h"

#include "carbon/fmt.h"

#include <stdlib.h>
#include <stdio.h>

void	msh_exit(int code, char *msg)
{
	if (!code)
		fmt_fprintln(2, msg);
	else
		fmt_println(msg);
	exit(code);
}
