/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:44:26 by lrocigno          #+#    #+#             */
/*   Updated: 2022/03/14 14:58:34 by vgoncalv         ###   ########.fr       */
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

extern t_shell	*g_sh;

/**
 * @brief Receive the user input, parse, execute (if it is a valid command) and 
 * stores in the history (when it isn't a empty line).
 * 
 * @param input: empty string,
 */
void	interface(char *input);

/**
 * @brief Finalizes the shell
 */
void	free_sh();

/**
 * @brief Finilizes the shell and exits with EXIT_FAILURE
 */
void	error();

/**
 * @brief Search for name in env variables and return its value
 * 
 * @param name: The env name.
 * @return the value of the asked environ variable.
 */
char	*get_env_value(const char *name);

/**
 * @brief Generate the argv array
 * 
 * @param full_name: The full name of the program.
 * @param tokens: The tokens aquired after the user input.
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
 */
void	exec_extcmd(t_token *tokens);

#endif
