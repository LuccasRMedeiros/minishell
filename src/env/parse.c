/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:33:11 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/01/28 21:15:18 by vgoncalv         ###   ########.fr       */
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
	t_env	*env;
	size_t	i;

	sh->env = ft_calloc(1, sizeof(t_env));
	env = sh->env;
	i = 0;
	while (environ[i] != NULL)
	{
		env->name = name(environ[i]);
		if (env->name == NULL)
			error(sh);
		env->value = value(environ[i]);
		if (env->value == NULL)
			error(sh);
		env->next = ft_calloc(1, sizeof(t_env));
		env = env->next;
		if (env == NULL)
			error(sh);
		i++;
	}
}
