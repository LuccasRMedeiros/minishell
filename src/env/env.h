/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:24:48 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/01/28 16:27:25 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include <minishell.h>

/**
 * Parses the environment variables
 * @param sh: the shell
 */
void	parse_env(t_shell *sh);

/**
 * Retrievies an environment variable as a t_env *
 * @param name: the name of the environment variable
 * @param sh: the shell
 * @return the environment variable if it is set, otherwise it returns NULL
 */
t_env	*get_env(const char *name, t_shell *sh);

#endif
