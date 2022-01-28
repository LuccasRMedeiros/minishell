/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 20:21:21 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/01/28 15:58:37 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	free_env(t_shell *sh)
{
	size_t	offset;

	if (sh->env == NULL)
		return ;
	offset = 0;
	while (sh->env[offset] != NULL)
		free(sh->env[offset++]);
	free(sh->env);
}

void	free_sh(t_shell *sh)
{
	free_env(sh);
	ft_bzero(sh, sizeof(t_shell));
}
