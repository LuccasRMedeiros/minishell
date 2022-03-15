/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 09:45:18 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/03/15 15:09:22 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prompt/prompt.h>

static char	*tilde_expansion(void)
{
	char	*pwd;

	if (g_sh->pwd->value[ft_strlen(g_sh->pwd->value) - 1] == '/')
	{
		if (ft_asprintf(&pwd, "~/%s",
				&g_sh->pwd->value[ft_strlen(g_sh->home->value)]) == -1)
			error();
	}
	else
		if (ft_asprintf(&pwd, "~%s",
				&g_sh->pwd->value[ft_strlen(g_sh->home->value)]) == -1)
			error();
	return (pwd);
}

char	*get_pwd(void)
{
	if (g_sh->home == NULL)
		return (ft_strdup(g_sh->pwd->value));
	if (ft_strncmp(g_sh->home->value, g_sh->pwd->value,
			ft_strlen(g_sh->home->value)) == 0)
		return (tilde_expansion());
	return (ft_strdup(g_sh->pwd->value));
}
