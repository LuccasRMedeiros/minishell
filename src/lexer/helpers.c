/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 00:06:32 by lrocigno          #+#    #+#             */
/*   Updated: 2022/02/17 20:04:58 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/helpers.h>

int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\r')
		return (1);
	else if (c == '\n' || c == '\v' || c == '\f')
		return (1);
	return (0);
}

int	is_quote(char c)
{
	return (c == '\"' || c == '\'');
}

int	is_stop(char **input)
{
	if (**input == '\0')
		return (1);
	if (is_quote(get_quote()))
	{
		if (**input == get_quote())
		{
			++(*input);
			clear_quote();
			if (is_space(**input) || **input == '\0' || **input == '#')
				return (1);
		}
		return (0);
	}
	else if (is_space(**input) || **input == '\0' || **input == '#')
		return (1);
	return (0);
}
