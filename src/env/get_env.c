/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:24:10 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/01/28 16:24:28 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <env/env.h>

t_env	*get_env(const char *name, t_shell *sh)
{
	size_t	i;

	i = 0;
	while (sh->env[i] != NULL)
	{
		if (ft_strcmp(name, sh->env[i]->name) == 0)
			return (sh->env[i]);
		i++;
	}
	return (NULL);
}
