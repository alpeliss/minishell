/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 14:22:40 by ancoulon          #+#    #+#             */
/*   Updated: 2021/03/16 10:51:59 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READER_H
# define READER_H

#define MSH_BUFFSIZE 1024

/*
** @brief Prompts the user with a new shell line and reads the first line
** of input
**
** @param prompt string to display before the user input
** @return char* line written by the user
*/
char	*msh_prompt(char *prompt);

#endif
