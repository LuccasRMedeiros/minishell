/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 20:21:21 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/01/28 21:27:48 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	free_env(t_shell *sh)
{
	t_env	*env;
	t_env	*next;

	env = sh->env;
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

void	free_sh(t_shell *sh)
{
	free_env(sh);
	ft_bzero(sh, sizeof(t_shell));
}
