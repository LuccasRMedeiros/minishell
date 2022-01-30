/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vini <vini@42sp.org.br>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 19:47:25 by vini              #+#    #+#             */
/*   Updated: 2022/01/30 01:23:15 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

extern char	**environ;

char	*prompt(t_shell *sh)
{
	char	*prompt;
	char	*input;

	if (ft_asprintf(&prompt, "%s%s@minishell%s:%s%s%s$ ",
				BGREEN,
				sh->user->value,
				COLOR_OFF,
				BLUE,
				sh->pwd->value,
				COLOR_OFF) == -1)
		error(sh);
	input = readline(prompt);
	free(prompt);
	return (input);
}
