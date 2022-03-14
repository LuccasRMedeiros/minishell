/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:24:10 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/03/14 15:02:49 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <env/env.h>

t_env	*get_env(const char *name)
{
	t_env	*env;

	env = g_sh->env;
	while (env != NULL)
	{
		if (ft_strncmp(name, env->name, ft_strlen(name)) == 0)
			return (env);
		env = env->next;
	}
	return (NULL);
}
