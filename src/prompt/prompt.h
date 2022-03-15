/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 09:29:56 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/03/15 15:03:48 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_H
# define PROMPT_H

# include <minishell.h>
# include <readline/readline.h>
# include <readline/history.h>

/**
 * Terminal Emulator ANSI Escape Colors
 */
# define RESET "\001\033[0m\002"

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

# define BOLD_BLACK "\001\033[1;30m\002"
# define BOLD_RED "\001\033[1;31m\002"
# define BOLD_GREEN "\001\033[1;32m\002"
# define BOLD_YELLOW "\001\033[1;33m\002"
# define BOLD_BLUE "\001\033[1;34m\002"
# define BOLD_PURPLE "\001\033[1;35m\002"
# define BOLD_CYAN "\001\033[1;36m\002"
# define BOLD_WHITE "\001\033[1;37m\002"

/**
 * Gets the PWD. If it is is a folder inside the user HOME, represent it with
 * ~/ (see: tilde-expansion)
 * @return the formated pwd
 */
char	*get_pwd(void);

/**
 * Generates the shell prompt
 * @return the generated prompt
 */
char	*prompt(void);

#endif
