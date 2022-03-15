/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 20:21:21 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/03/15 14:38:48 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	free_env(void)
{
	t_env	*env;
	t_env	*next;

	env = g_sh->env;
	while (env != NULL)
	{
		next = env->next;
		safe_free((void **)&env->name);
		safe_free((void **)&env->value);
		safe_free((void **)&env);
		env = next;
	}
	g_sh->env = NULL;
}

void	free_sh(void)
{
	free_env();
	safe_free((void **)g_sh);
}
