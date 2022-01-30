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
 * Reset.
 */

# define COLOR_OFF "\001\033[0m\002"

/**
 * Regular Colors.
 */

# define BLACK "\001\033[0;30m\002"
# define RED "\001\033[0;31m\002"
# define GREEN "\001\033[0;32m\002"
# define YELLOW "\001\033[0;33m\002"
# define BLUE "\001\033[0;34m\002"
# define PURPLE "\001\033[0;35m\002"
# define CYAN "\001\033[0;36m\002"
# define WHITE "\001\033[0;37m\002"

/**
 * Bold.
 */

# define BBLACK "\001\033[1;30m\002"
# define BRED "\001\033[1;31m\002"
# define BGREEN "\001\033[1;32m\002"
# define BYELLOW "\001\033[1;33m\002"
# define BBLUE "\001\033[1;34m\002"
# define BPURPLE "\001\033[1;35m\002"
# define BCYAN "\001\033[1;36m\002"
# define BWHITE "\001\033[1;37m\002"

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
