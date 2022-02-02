/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 00:28:34 by lrocigno          #+#    #+#             */
/*   Updated: 2022/02/02 13:25:17 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>

/**
 * Test if the token is a built-in
 */

static int	isbuiltin(char *input)
{
	if (ft_strlen(input) == 0)
		return (0);
	if (ft_strncmp("echo ", input, 5) == 0
		|| ft_strncmp("cd ", input, 3) == 0
		|| ft_strncmp("pwd ", input, 4) == 0
		|| ft_strncmp("export ", input, 7) == 0
		|| ft_strncmp("unset ", input, 6) == 0
		|| ft_strncmp("env ", input, 4) == 0
		|| ft_strncmp("exit ", input, 5) == 0)
	{
		return (1);
	}
	return (0);
}

/**
 * Search for a white space between quotes (the first spoted before the call for
 * this function and another one present in input).
 */

static int	isstrlit(char *input)
{
	int		presume;

	presume = 0;
	if (*input == '\"' || *input == '\'')
		set_quote(*input);
	else
		return (presume);
	while (*input != '\0' && *input != get_quote())
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
	char	q;

	q = *input;
	while (lex_isspace(*input))
		++input;
	if (isstrlit(input))
		return (STRING_LITERAL);
	else if (isstrlit(input) == -1)
		return (INVALID);
	while (*input == q && (q == '\"' || q == '\''))
		++input;
	if (isbuiltin(input))
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
