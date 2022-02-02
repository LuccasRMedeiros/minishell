/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 00:06:32 by lrocigno          #+#    #+#             */
/*   Updated: 2022/02/02 10:05:00 by lrocigno         ###   ########.fr       */
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
