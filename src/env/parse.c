/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:33:11 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/03/14 15:04:53 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <env/env.h>

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

static void	set_default_envs()
{
	g_sh->user = get_env("USER");
	if (g_sh->user == NULL)
	{
		g_sh->user = set_env("USER", "user");
		if (g_sh->user == NULL)
			error(g_sh);
	}
	g_sh->host = get_env("HOST");
	if (g_sh->host == NULL)
	{
		g_sh->host = set_env("HOST", "minishell");
		if (g_sh->host == NULL)
			error(g_sh);
	}
	g_sh->home = get_env("HOME");
	g_sh->pwd = get_env("PWD");
	if (g_sh->pwd == NULL)
		error(g_sh);
	g_sh->old_pwd = g_sh->pwd;
}

void	parse_env()
{
	size_t	i;
	t_env	*env;

	g_sh->env = ft_calloc(1, sizeof(t_env));
	i = 0;
	env = g_sh->env;
	while (environ[i] != NULL)
	{
		env->name = name(environ[i]);
		if (env->name == NULL)
			error(g_sh);
		env->value = value(environ[i]);
		if (env->value == NULL)
			error(g_sh);
		if (environ[i + 1] == NULL)
			break ;
		env->next = ft_calloc(1, sizeof(t_env));
		env = env->next;
		if (env == NULL)
			error(g_sh);
		i++;
	}
	set_default_envs();
}
