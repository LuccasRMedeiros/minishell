/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vini <vini@42sp.org.br>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 19:47:25 by vini              #+#    #+#             */
/*   Updated: 2022/01/31 09:34:28 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prompt/prompt.h>

extern char	**environ;

char	*prompt(t_shell *sh)
{
	char	*prompt;
	char	*input;

	if (ft_asprintf(&prompt, "%s%s@minishell%s:%s%s%s$ ",
			BOLD_GREEN,
			sh->user->value,
			RESET,
			BLUE,
			sh->pwd->value,
			RESET) == -1)
		error(sh);
	input = readline(prompt);
	free(prompt);
	return (input);
}
