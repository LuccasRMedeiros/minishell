/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:24:48 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/03/14 15:03:00 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include <minishell.h>

/**
 * Parses the environment variables
 */
void	parse_env();

/**
 * Retrievies an environment variable as a t_env *
 * @param name: the name of the environment variable
 * @return the environment variable if it is set, otherwise it returns NULL
 */
t_env	*get_env(const char *name);

/**
 * Sets the value of a environment variable
 * @param name: the name of the environment variable
 * @param value: the value of the environment variable
 * @return the environment variable set, or NULL if there was an error
 */
t_env	*set_env(const char *name, char *value);

#endif
