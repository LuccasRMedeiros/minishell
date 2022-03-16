/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.o...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:27:14 by lrocigno          #+#    #+#             */
/*   Updated: 2022/03/16 00:43:06 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <minishell.h>
#include <env/env.h>

t_shell	*g_sh;

/**
 * @brief Initializes the Shell
 */
static void init_shell(void)
{
	g_sh = ft_calloc(1, sizeof(t_shell));
	parse_env();
}

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	init_shell();
	interactive();
	free_sh(g_sh);
	return (EXIT_SUCCESS);
}
