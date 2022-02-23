/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:44:26 by lrocigno          #+#    #+#             */
/*   Updated: 2022/02/21 23:07:19 by lrocigno         ###   ########.fr       */
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
# include <lexer/lexer.h>

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
 * Finalizes the shell
 * @param sh: the shell
 */

void	free_sh(t_shell *sh);

/**
 * Finilizes the shell and exits with EXIT_FAILURE
 * @param sh: the shell
 */

void	error(t_shell *sh);

/**
 * Search for name in env variables and return its value.
 * @param name: the env name, @param sh: the shell.
 */

char	*get_env_value(const char *name, t_shell *sh);

#endif
