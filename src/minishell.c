/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.o...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:27:14 by lrocigno          #+#    #+#             */
/*   Updated: 2022/03/14 15:05:51 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <minishell.h>
#include <env/env.h>

t_shell	*g_sh;

int	main(void)
{
	g_sh = ft_calloc(1, sizeof(t_shell));
	ft_bzero(g_sh, sizeof(t_shell));
	parse_env();
	interface(NULL);
	free_sh(g_sh);
	return (EXIT_SUCCESS);
}
