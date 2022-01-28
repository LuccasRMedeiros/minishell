/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vini <vini@42sp.org.br>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 19:47:25 by vini              #+#    #+#             */
/*   Updated: 2022/01/27 21:15:14 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

extern char	**environ;

char	*prompt(t_shell *sh)
{
	size_t	i;
	char	*user;
	char	*prompt;
	char	*input;

	i = 0;
	while (ft_strncmp("USER", environ[i], 4))
		++i;
	user = ft_strchr(environ[i], '=') + 1;
	if (ft_asprintf(&prompt, "\e[0;38;5;229m%s@minishell\e[0;0;0m$ ", user) == -1)
		error(sh);
	input = readline(prompt);
	free(prompt);
	return (input);
}
