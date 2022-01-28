/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:33:11 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/01/28 16:23:52 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

extern char	**environ;

static char	*name(const char *env)
{
	if (ft_strchr(env, '=') != NULL)
		return (ft_substr(env, 0, ft_strchr(env, '=') - env));
	return (ft_strdup(env));
}

static char	*value(const char *env)
{
	char	*start;

	start = ft_strchr(env, '=');
	if (start == NULL)
		return (ft_strdup(""));
	return (ft_strdup(start + 1));
}

void	parse_env(t_shell *sh)
{
	size_t	i;
	size_t	size;

	size = 0;
	while (environ[size] != NULL)
		size++;
	sh->env = ft_calloc(size + 1, sizeof(t_env *));
	i = 0;
	while (i < size)
	{
		sh->env[i] = ft_calloc(1, sizeof(t_env));
		if (sh->env[i] == NULL)
			error(sh);
		sh->env[i]->name = name(environ[i]);
		sh->env[i]->value = value(environ[i]);
		i++;
	}
}
