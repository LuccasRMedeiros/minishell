/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 00:28:34 by lrocigno          #+#    #+#             */
/*   Updated: 2022/02/26 14:10:16 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>

/**
 * Test if the token is a built-in
 */

static int	isbuiltin(const char *value)
{
	size_t	v_sz;

	v_sz = ft_strlen(value);
	if (v_sz == 0)
		return (0);
	if (ft_strncmp("echo", value, v_sz) == 0
		|| ft_strncmp("cd", value, v_sz) == 0
		|| ft_strncmp("pwd", value, v_sz) == 0
		|| ft_strncmp("export", value, v_sz) == 0
		|| ft_strncmp("unset", value, v_sz) == 0
		|| ft_strncmp("env", value, v_sz) == 0
		|| ft_strncmp("exit", value, v_sz) == 0)
	{
		return (1);
	}
	return (0);
}

t_type	get_type(const int order, const char *value)
{
	if (order == 0)
	{
		if (isbuiltin(value))
			return (BUILTIN);
		return (EXTERNAL);
	}
	else
		return (PARAMETER);
}
