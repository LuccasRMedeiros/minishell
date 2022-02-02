/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:44:26 by lrocigno          #+#    #+#             */
/*   Updated: 2022/02/02 01:16:30 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Contains all the definitions of macros, enums, unions, structures and types
 * (and also its initializers and destroyers). The commom depedencies are
 * included here.
 */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <ft_printf.h>
# include <stdio.h>

/**
 * Hold the environment variables separatelly
 */

typedef struct s_env
{
	const char		*name;
	char			*value;
	struct s_env	*next;
}	t_env;

/**
 * Hold general information of the shell
 */

typedef struct s_shell
{
	t_env	*env;
	t_env	*user;
	t_env	*host;
	t_env	*home;
	t_env	*pwd;
	t_env	*old_pwd;
}	t_shell;

/**
 * Receive the user input, parse, execute (if it is a valid command) and stores
 * in the history (when it isn't a empty line).
 * @param input: empty string, sh: the shell
 */

void	interface(char *input, t_shell *sh);

/**
 * Tokenize the input.
 * @param input: a string received from the user
 */

void	tokenizer(char *input);

/**
 * Finalizes the shell
 * @param sh: the shell
 */

void	free_sh(t_shell *sh);

/**
 * Finilizes the shell and exits with EXIT_FAILURE
 * @param sh: the shell
 */

void	error(t_shell *sh);

#endif
