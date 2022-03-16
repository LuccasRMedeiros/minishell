/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_checkers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.o...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:56:32 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/03/14 18:54:19 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>

/**
 * @brief Test if the character is a whitespace
 * 
 * @param c: The character
 * @return 1 when the character is a space, 0 when not
 */
uint8_t	is_space(char c)
{
	if (c == ' ')
		return (1);
	if (c == '\t')
		return (1);
	if (c == '\n')
		return (1);
	return (0);
}

/**
 * @brief Test if the character is a operator
 * 
 * @param input: The user input
 * @return 1 when the character is a operator, 0 when not
 */
uint8_t	is_operator(char *input)
{
	if (*input == '|')
		return (1);
	if (ft_strncmp("&&", input, 2) == 0)
		return (1);
	return (0);
}

/**
 * @brief Test if the character is a metacharacter
 * 
 * @param input: The user input
 * @return 1 when it is a metacharacter, 0 when not
 */
uint8_t	is_metachar(char *input)
{
	return (is_operator(input) || is_space(*input));
}
