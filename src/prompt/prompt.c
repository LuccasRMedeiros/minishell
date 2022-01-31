/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vini <vini@42sp.org.br>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 19:47:25 by vini              #+#    #+#             */
/*   Updated: 2022/01/31 10:49:15 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prompt/prompt.h>

extern char	**environ;

char	*prompt(t_shell *sh)
{
	char	*prompt;
	char	*input;
	char	*pwd;

	pwd = get_pwd(sh);
	if (ft_asprintf(&prompt, "%s%s@%s%s:%s%s%s$ ",
			BOLD_GREEN,
			sh->user->value,
			sh->host->value,
			RESET,
			BLUE,
			pwd,
			RESET) == -1)
		error(sh);
	safe_free((void **)&pwd);
	input = readline(prompt);
	free(prompt);
	return (input);
}
