/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 00:06:32 by lrocigno          #+#    #+#             */
/*   Updated: 2022/02/16 22:47:03 by lrocigno         ###   ########.fr       */
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
	char	nx_c;
	
	nx_c = **(input + 1);
	if (is_quote(get_quote()) && **input == get_quote())
	{
		*input++;
		clear_quote();
		if (is_space(nx_c) || nx_c == '\0' || nx_c == '#')
			return (1);
	}
	else if (is_space(**input) || **input == '\0' || **input == '#')
		return (1);
	return (0);
}
