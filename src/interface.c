/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 20:12:16 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/01/28 23:45:21 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <readline/history.h>

static void	validate_input(char **input)
{
	if (**input)
	{
		add_history(*input);
		safe_free((void **)&(*input));
	}
}

void	interface(char *input, t_shell *sh)
{
	input = prompt(sh);
	if (!ft_strncmp("exit", input, ft_strlen(input)) && *input)
	{
		safe_free((void **)&input);
		exit(0);
	}
	validate_input(&input);
	interface(input, sh);
}
