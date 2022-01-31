/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 09:45:18 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/01/31 10:01:46 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prompt/prompt.h>

static size_t	get_len(t_shell *sh)
{
	size_t	pwd_len;
	size_t	home_len;

	pwd_len = ft_strlen(sh->pwd->value);
	home_len = ft_strlen(sh->home->value);
	if (pwd_len > home_len)
		return (pwd_len);
	return (home_len);
}

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
				&sh->pwd->value[ft_strlen(sh->home->value)]))
			error(sh);
	return (pwd);
}

char	*get_pwd(t_shell *sh)
{
	if (sh->home == NULL)
		return (ft_strdup(sh->pwd->value));
	if (ft_strncmp(sh->home->value, sh->pwd->value, get_len(sh)) == 0)
		return (tilde_expansion(sh));
	return (ft_strdup(sh->pwd->value));
}
