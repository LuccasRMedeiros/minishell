/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 00:28:34 by lrocigno          #+#    #+#             */
/*   Updated: 2022/02/02 01:17:23 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>

/**
 * Search for a white space between quotes (the first spoted before the call for
 * this function and another one present in input).
 */

static int	isstrlit(char *input)
{
	int		presume;
	char	qot_t;

	presume = 0;
	qot_t = '\0';
	if (*input == '\"' || *input == '\'')
		qot_t = *input;
	while (*input != '\0' && *input != qot_t)
	{
		if (lex_isspace(*input))
			presume = 1;
		++input;
	}
	if (*input == '\0')
		presume = -1;
	return (presume);
}

t_type	get_type(size_t i, char *input)
{
	while (lex_isspace(*input))
		++input;
	if (isstrlit(input))
		return (STRING_LITERAL);
	else if (isstrlit(input) == -1)
		return (INVALID);
	else if (lex_isbuiltin(input))
		return (BUILTIN);
	else if (ft_isdigit(*input))
		return (INT_LITERAL);
	else if (ft_isalpha(*input) && i == 0)
		return (COMMAND);
	else if (*input == '-' || ft_isalpha(*input))
		return (PARAMETER);
	else if (*input == '#')
		return (COMMENT);
	return (INVALID);
}
