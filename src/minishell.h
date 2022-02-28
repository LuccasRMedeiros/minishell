/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:44:26 by lrocigno          #+#    #+#             */
/*   Updated: 2022/02/25 22:30:59 by lrocigno         ###   ########.fr       */
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
# include <lexer/lexer.h>

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
	t_env	*env;
	t_env	*user;
	t_env	*host;
	t_env	*home;
	t_env	*pwd;
	t_env	*old_pwd;
}	t_shell;

/**
 * @brief Receive the user input, parse, execute (if it is a valid command) and 
 * stores in the history (when it isn't a empty line).
 * 
 * @param input: empty string,
 * @param sh: the shell
 */
void	interface(char *input, t_shell *sh);

/**
 * @brief Finalizes the shell
 * 
 * @param sh: the shell
 */
void	free_sh(t_shell *sh);

/**
 * @brief Finilizes the shell and exits with EXIT_FAILURE
 * 
 * @param sh: the shell
 */
void	error(t_shell *sh);

/**
 * @brief Search for name in env variables and return its value
 * 
 * @param name: the env name
 * @param sh: the shell
 * @return the value of the asked environ variable
 */
char	*get_env_value(const char *name, t_shell *sh);

/**
 * @brief Generate the argv array
 * 
 * @param tokens: the tokens aquired after the user input
 * @return the arguments array
 */
char	**gen_argv(t_token *tokens);

/**
 * @brief Generate the envp array
 * 
 * @param env: the environ linked list
 * @return the environ array
 */
char	**gen_envp(t_env *env);

/**
 * @brief Execute the command asked by the user (when it is a external command
 * or program).
 *
 * @param tokens: The tokens generated from the user input.
 * @param sh: The shell
 */
void	exec_extcmd(t_token *tokens, t_shell *sh);

#endif
