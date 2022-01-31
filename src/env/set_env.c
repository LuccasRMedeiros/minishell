/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 10:50:14 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/01/31 11:03:39 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <env/env.h>

static char	get_name_and_value(const char **name, char **value)
{
	if (*value == NULL)
		*value = ft_strdup("");
	else
		*value = ft_strdup(*value);
	*name = ft_strdup(*name);
	if (name == NULL || value == NULL)
		return (1);
	return (0);
}

t_env	*set_env(const char *name, char *value, t_shell *sh)
{
	t_env	*env;
	t_env	*res;

	if (get_name_and_value(&name, &value))
		return (NULL);
	res = get_env(name, sh);
	if (res == NULL)
		res = ft_calloc(1, sizeof(t_env));
	if (res == NULL)
		return (NULL);
	res->name = name;
	res->value = value;
	if (sh->env == NULL)
		sh->env = res;
	else
	{
		env = sh->env;
		while (env->next != NULL)
			env = env->next;
		env->next = res;
	}
	return (res);
}
