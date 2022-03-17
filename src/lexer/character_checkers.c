/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_checkers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.o...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:56:32 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/03/17 13:57:11 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>

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

uint8_t	is_operator(char *input)
{
	if (*input == '|')
		return (1);
	if (*input == '<')
		return (1);
	if (*input == '>')
		return (1);
	if (ft_strncmp("&&", input, 2) == 0)
		return (1);
	return (0);
}

uint8_t	is_metachar(char *input)
{
	return (is_operator(input) || is_space(*input));
}
