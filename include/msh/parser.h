/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 16:03:25 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/16 16:34:26 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

//#include "carbon/llst.h"

typedef struct	s_prog
{
	int		argc;
	char	**argv;
	int		in_fd;
	int		out_fd;
}				t_prog;

//t_llst	*msh_parse(char *line);

#endif
