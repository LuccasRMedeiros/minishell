/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vini <vini@42sp.org.br>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:27:14 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/27 21:08:32 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	main(void)
{
	t_shell	sh;

	ft_bzero(&sh, sizeof(t_shell));
	init(&sh);
	free_sh(&sh);
	return (EXIT_SUCCESS);
}
