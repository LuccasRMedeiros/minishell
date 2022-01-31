/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 09:45:18 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/01/31 11:09:42 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prompt/prompt.h>

static char	*tilde_expansion(t_shell *sh)
{
	char	*pwd;

	if (sh->pwd->value[ft_strlen(sh->pwd->value) - 1] == '/')
	{
		if (ft_asprintf(&pwd, "~/%s",
				&sh->pwd->value[ft_strlen(sh->home->value)]) == -1)
			error(sh);
	}
	else
		if (ft_asprintf(&pwd, "~%s",
				&sh->pwd->value[ft_strlen(sh->home->value)]) == -1)
			error(sh);
	return (pwd);
}

char	*get_pwd(t_shell *sh)
{
	if (sh->home == NULL)
		return (ft_strdup(sh->pwd->value));
	if (ft_strncmp(sh->home->value, sh->pwd->value,
			ft_strlen(sh->home->value)) == 0)
		return (tilde_expansion(sh));
	return (ft_strdup(sh->pwd->value));
}
