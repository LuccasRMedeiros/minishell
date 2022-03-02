/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vini <vini@42sp.org.br>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:27:14 by lrocigno          #+#    #+#             */
/*   Updated: 2022/03/01 21:51:01 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <minishell.h>
#include <env/env.h>

int	main(void)
{
	t_shell	sh;

	ft_bzero(&sh, sizeof(t_shell));
	parse_env(&sh);
	interface(NULL, &sh);
	free_sh(&sh);
	return (EXIT_SUCCESS);
}
