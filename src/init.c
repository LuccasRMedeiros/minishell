/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 20:12:16 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/01/28 22:11:26 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <readline/history.h>

void	init(t_shell *sh)
{
	char	*input;

	input = prompt(sh);
	while (ft_strncmp("exit", input, ft_strlen(input)) || input == NULL)
	{
		if (input != NULL)
			free(input);
		input = prompt(sh);
	}
	if (input != NULL)
		free(input);
}
