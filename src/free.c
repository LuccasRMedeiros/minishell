/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 20:21:21 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/01/27 20:22:42 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	free_sh(t_shell *sh)
{
	ft_bzero(sh, sizeof(t_shell));
}
