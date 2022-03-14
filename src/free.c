/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 20:21:21 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/03/14 14:56:16 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	free_env()
{
	t_env	*env;
	t_env	*next;

	env = g_sh->env;
	while (env != NULL)
	{
		next = env->next;
		if (env->name != NULL)
			safe_free((void **)&env->name);
		if (env->value != NULL)
			safe_free((void **)&env->value);
		free(env);
		env = next;
	}
}

void	free_sh()
{
	free_env();
	safe_free((void **)g_sh);
}
