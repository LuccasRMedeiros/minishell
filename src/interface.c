/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 20:12:16 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/01/31 09:41:49 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <prompt/prompt.h>

static char	validate(char *input)
{
	if (input == NULL)
		return (0);
	if (ft_strncmp("exit", input, ft_strlen(input)) == 0)
		return (1);
	return (0);
}

void	interface(char *input, t_shell *sh)
{
	input = prompt(sh);
	if (validate(input))
	{
		safe_free((void **)&input);
		free_sh(sh);
		exit(EXIT_SUCCESS);
	}
	safe_free((void **)&input);
	interface(input, sh);
}
