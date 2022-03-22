/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:44:26 by lrocigno          #+#    #+#             */
/*   Updated: 2022/03/17 19:47:45 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Contains all the definitions of macros, enums, unions, structures and
 * types (and also its initializers and destroyers). The commom depedencies are
 * included here.
 */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <ft_printf.h>
# include <stdio.h>
# include <sys/wait.h>

/**
 * @brief Hold the environment variables separatelly
 */
typedef struct s_env
{
	const char		*name;
	char			*value;
	struct s_env	*next;
}	t_env;

/**
 * @brief Hold general information of the shell
 */
typedef struct s_shell
{
	t_env		*env;
	t_env		*user;
	t_env		*host;
	t_env		*home;
	t_env		*pwd;
	t_env		*old_pwd;
	char		*error_msg;
	uint8_t		exit_code;
}	t_shell;

extern t_shell	*g_sh;

void	interactive(void);

/**
 * @brief Finalizes the shell
 */
void	free_sh(void);

/**
 * @brief Finilizes the shell and exits with EXIT_FAILURE
 */
void	error(void);

/**
 * @brief Execute the built-in command asked by the user.
 *
 * @param tokens: The tokens generated from the user input.
 * @param sh: The shell.
 */
void	builtin_cmd(t_token *tks, t_shell *sh);

#endif
