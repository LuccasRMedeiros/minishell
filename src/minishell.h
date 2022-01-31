/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:44:26 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/29 23:01:14 by lrocigno         ###   ########.fr       */
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
# include <ft_printf.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

/**
 * Carries the environment variables separatelly
 */
typedef struct s_env
{
	const char		*name;
	char			*value;
	struct s_env	*next;
}	t_env;

/**
 * Carries general information of the shell
 */
typedef struct s_shell
{
	t_env	*env;
	t_env	*user;
	t_env	*pwd;
	t_env	*old_pwd;
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

void	interface(char *input, t_shell *sh);

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

#endif
