/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:33:11 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/03/17 13:49:43 by vgoncalv         ###   ########.fr       */
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

static void	set_default_envs(void)
{
	g_sh->user = get_env("USER");
	if (g_sh->user == NULL)
	{
		g_sh->user = set_env("USER", "user");
		if (g_sh->user == NULL)
			error();
	}
	g_sh->host = get_env("HOST");
	if (g_sh->host == NULL)
	{
		g_sh->host = set_env("HOST", "minishell");
		if (g_sh->host == NULL)
			error();
	}
	g_sh->home = get_env("HOME");
	g_sh->pwd = get_env("PWD");
	if (g_sh->pwd == NULL)
		error();
	g_sh->old_pwd = g_sh->pwd;
	g_sh->local_vars = NULL;
}

void	parse_env(void)
{
	size_t	i;
	t_env	*env;
	char	*e_name;
	char	*e_value;

	i = -1;
	while (environ[++i] != NULL)
	{
		e_name = name(environ[i]);
		e_value = value(environ[i]);
		env = set_env(e_name, e_value);
		safe_free((void **)&e_name);
		safe_free((void **)&e_value);
		if (env == NULL)
			error();
	}
	set_default_envs();
}
