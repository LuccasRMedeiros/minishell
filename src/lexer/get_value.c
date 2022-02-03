/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 00:52:29 by lrocigno          #+#    #+#             */
/*   Updated: 2022/02/02 20:34:31 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>

/**
 * Test if the inchar (input char) is equal stop. When stop is \0, isstop also
 * test if inchar is a white space.
 *
 * Return the result of the test.
 */

static int	isstop(char inchar, char stop)
{
	if (inchar == '#')
		return (1);
	if (stop == '\0')
		return (lex_isspace(inchar) == 1 || inchar == stop);
	else
		return (inchar == stop);
}

/**
 * Predict the size of string value.
 *
 * Return the predicted size of string value.
 */

static size_t	vallen(t_type type, char *input)
{
	size_t	len;
	char	stop;

	len = 0;
	if (type == STRING_LITERAL)
		stop = quote('g');
	else
		stop = '\0';
	while (*input == quote('g'))
		++input;
	while (isstop(*input, stop) == 0)
	{
		if (ft_isalnum(*input) || type == STRING_LITERAL)
			++len;
		++input;
	}
	return (len);
}

char	*get_value(t_type type, char *input)
{
	size_t	len;
	size_t	i;
	char	*ret;

	while (lex_isspace(*input))
		++input;
	len = vallen(type, input);
	i = 0;
	ret = ft_calloc(len + 1, sizeof (*ret));
	if (!ret)
		return (NULL);
	while (i < len)
	{
		if (ft_isalnum(*input)
			|| (type == STRING_LITERAL && *input != quote('g')))
		{
			ret[i] = *input;
			++i;
		}
		++input;
	}
	quote('d');
	return (ret);
}
