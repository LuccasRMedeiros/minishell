/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:24:10 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/01/28 21:23:25 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <env/env.h>

t_env	*get_env(const char *name, t_shell *sh)
{
	while (sh->env != NULL)
	{
		if (ft_strcmp(name, sh->env->name) == 0)
			return (sh->env);
		sh->env = sh->env->next;
	}
	return (NULL);
}
