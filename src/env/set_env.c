/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 10:50:14 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/03/14 15:28:47 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <env/env.h>

static t_env	*safe_get_env(const char *name)
{
	t_env	*res;
	t_env	*env;

	res = get_env(name);
	if (res == NULL)
	{
		res = ft_calloc(1, sizeof(t_env));
		res->name = ft_strdup(name);
		if (res->name == NULL)
		{
			safe_free((void **)&(res->name));
			safe_free((void **)&res);
			return (NULL);
		}
		env = g_sh->env;
		if (env == NULL)
			g_sh->env = env;
		else
		{
			while (env->next != NULL)
				env = env->next;
			env->next = res;
		}
	}
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
		return (NULL);
	res->value = new_value;
	return (res);
}
