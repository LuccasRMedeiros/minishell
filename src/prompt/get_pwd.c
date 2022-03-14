/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 09:45:18 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/03/14 14:54:54 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prompt/prompt.h>

static char	*tilde_expansion()
{
	char	*pwd;

	if (g_sh->pwd->value[ft_strlen(g_sh->pwd->value) - 1] == '/')
	{
		if (ft_asprintf(&pwd, "~/%s",
				&g_sh->pwd->value[ft_strlen(g_sh->home->value)]) == -1)
			error(g_sh);
	}
	else
		if (ft_asprintf(&pwd, "~%s",
				&g_sh->pwd->value[ft_strlen(g_sh->home->value)]) == -1)
			error(g_sh);
	return (pwd);
}

char	*get_pwd()
{
	if (g_sh->home == NULL)
		return (ft_strdup(g_sh->pwd->value));
	if (ft_strncmp(g_sh->home->value, g_sh->pwd->value,
			ft_strlen(g_sh->home->value)) == 0)
		return (tilde_expansion(g_sh));
	return (ft_strdup(g_sh->pwd->value));
}
