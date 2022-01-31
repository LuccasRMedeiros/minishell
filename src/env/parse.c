/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:33:11 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/01/31 11:07:19 by vgoncalv         ###   ########.fr       */
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

static void	set_default_envs(t_shell *sh)
{
	sh->user = get_env("USER", sh);
	if (sh->user == NULL)
	{
		sh->user = set_env("USER", "user", sh);
		if (sh->user == NULL)
			error(sh);
	}
	sh->host = get_env("HOST", sh);
	if (sh->host == NULL)
	{
		sh->host = set_env("HOST", "minishell", sh);
		if (sh->host == NULL)
			error(sh);
	}
	sh->home = get_env("HOME", sh);
	sh->pwd = get_env("PWD", sh);
	if (sh->pwd == NULL)
		error(sh);
	sh->old_pwd = sh->pwd;
}

void	parse_env(t_shell *sh)
{
	size_t	i;
	t_env	*env;

	sh->env = ft_calloc(1, sizeof(t_env));
	i = 0;
	env = sh->env;
	while (environ[i] != NULL)
	{
		env->name = name(environ[i]);
		if (env->name == NULL)
			error(sh);
		env->value = value(environ[i]);
		if (env->value == NULL)
			error(sh);
		if (environ[i + 1] == NULL)
			break ;
		env->next = ft_calloc(1, sizeof(t_env));
		env = env->next;
		if (env == NULL)
			error(sh);
		i++;
	}
	set_default_envs(sh);
}
