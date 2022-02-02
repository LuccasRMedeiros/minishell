/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 00:06:32 by lrocigno          #+#    #+#             */
/*   Updated: 2022/02/02 01:18:36 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>

/**
 * Test if the character is a white space.
 */

int	lex_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\r')
		return (1);
	else if (c == '\n' || c == '\v' || c == '\f')
		return (1);
	return (0);
}

/**
 * Test if the token is a built-in
 */

int	lex_isbuiltin(char *input)
{
	if (ft_strlen(input) == 0)
		return (0);
	if (ft_strncmp("echo", input, 4) == 0
		|| ft_strncmp("cd", input, 2) == 0
		|| ft_strncmp("pwd", input, 3) == 0
		|| ft_strncmp("export", input, 6) == 0
		|| ft_strncmp("unset", input, 5) == 0
		|| ft_strncmp("env", input, 3) == 0
		|| ft_strncmp("exit", input, 4) == 0)
	{
		return (1);
	}
	return (0);
}
