/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vini <vini@42sp.org.br>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:44:26 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/27 21:54:59 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Contains all the definitions of macros, enums, unions, structures and types
 * (and also its initializers and destroyers). The commom depedencies are
 * included here.
 */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <libft.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_shell
{
}	t_shell;

/**
 * Generates the shell prompt
 * @return the generated prompt
 */
char	*prompt(t_shell *sh);

/**
 * Initializes the shell
 * @param sh: the shell
 */
void	init(t_shell *sh);

/**
 * Finilizes the shell
 * @param sh: the shell
 */
void	free_sh(t_shell *sh);

/**
 * Finilizes the shell and exits with EXIT_FAILURE
 * @param sh: the shell
 */
void	error(t_shell *sh);

# define PROMPT_SIZE 36

#endif
