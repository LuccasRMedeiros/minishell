/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 19:47:25 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/03/17 13:54:16 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prompt/prompt.h>

extern char	**environ;

char	*prompt(void)
{
	char	*prompt;
	char	*input;
	char	*pwd;

	pwd = get_pwd();
	if (ft_asprintf(&prompt, "%s%s@%s%s:%s%s%s$ ",
			BOLD_GREEN,
			g_sh->user->value,
			g_sh->host->value,
			RESET,
			BLUE,
			pwd,
			RESET) == -1)
		error();
	safe_free((void **)&pwd);
	input = readline(prompt);
	free(prompt);
	return (input);
}
