/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 10:50:14 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/03/15 15:08:23 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <env/env.h>

static t_env	*new_env(const char *name)
{
	t_env	*env;

	env = ft_calloc(1, sizeof(t_env));
	if (env == NULL)
		return (NULL);
	env->name = ft_strdup(name);
	if (env->name == NULL)
	{
		safe_free((void **)&(env->name));
		safe_free((void **)&env);
	}
	return (env);
}

static t_env	*safe_get_env(const char *name)
{
	t_env	*res;
	t_env	*env;

	res = get_env(name);
	if (res == NULL)
	{
		res = new_env(name);
		if (res == NULL)
			return (NULL);
		env = g_sh->env;
		if (env == NULL)
			g_sh->env = res;
		else
		{
			while (env->next != NULL)
				env = env->next;
			env->next = res;
		}
	}
	safe_free((void **)&(res->value));
	return (res);
}

t_env	*set_env(const char *name, char *value)
{
	t_env	*res;
	char	*new_value;

	if (value == NULL)
		new_value = ft_strdup("");
	else
		new_value = ft_strdup(value);
	if (new_value == NULL)
		return (NULL);
	res = safe_get_env(name);
	if (res == NULL)
	{
		safe_free((void **)&new_value);
		return (NULL);
	}
	res->value = new_value;
	return (res);
}
