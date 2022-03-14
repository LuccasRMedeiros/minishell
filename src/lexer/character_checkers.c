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

char	is_space(char c)
{
	if (c == ' ')
		return (1);
	if (c == '\t')
		return (1);
	if (c == '\n')
		return (1);
	return (0);
}

char	is_operator(char *input)
{
	if (*input == '|')
		return (1);
	if (ft_strncmp("&&", input, 2) == 0)
		return (1);
	return (0);
}

char is_metachar(char *input)
{
	if (is_space(*input))
		return (1);
	return (is_operator(input));
}
