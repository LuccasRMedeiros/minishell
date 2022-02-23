/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 23:00:27 by lrocigno          #+#    #+#             */
/*   Updated: 2022/02/22 23:02:38 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*get_env_value(const char *name, t_shell *sh)
{
	t_env	*env;
	size_t	name_s;

	env = sh->env;
	name_s = ft_strlen(name);
	if (!name)
		return (NULL);
	while (env)
	{
		if (!ft_strncmp(env->name, name, name_s))
			return (env->value);
		env = env->next;
	}
	return (NULL);
}
