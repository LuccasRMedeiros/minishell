/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 00:28:34 by lrocigno          #+#    #+#             */
/*   Updated: 2022/02/05 16:23:12 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>

/**
 * Test if the token is a built-in
 */

static int	isbuiltin(char *value)
{
	if (ft_strlen(value) == 0)
		return (0);
	if (ft_strncmp("echo", value, 4) == 0
		|| ft_strncmp("cd", value, 2) == 0
		|| ft_strncmp("pwd", value, 3) == 0
		|| ft_strncmp("export", value, 6) == 0
		|| ft_strncmp("unset", value, 5) == 0
		|| ft_strncmp("env", value, 3) == 0
		|| ft_strncmp("exit", value, 4) == 0)
	{
		return (1);
	}
	return (0);
}

t_type	get_type(size_t i, char *value)
{
	if (i == 0)
	{
		if (isbuiltin(value))
			return (BUILTIN);
		return (COMMAND);
	}
	else
		return (PARAMETER);
}
