/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vini <vini@42sp.org.br>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:27:14 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/31 10:26:45 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <minishell.h>
#include <env/env.h>

int	main(void)
{
	t_shell	sh;

	ft_bzero(&sh, sizeof(t_shell));
	parse_env(&sh);
	sh.user = get_env("USER", &sh);
	sh.home = get_env("HOME", &sh);
	sh.pwd = get_env("PWD", &sh);
	sh.old_pwd = sh.pwd;
	interface(NULL, &sh);
	free_sh(&sh);
	return (EXIT_SUCCESS);
}
