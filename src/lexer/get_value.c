/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 00:52:29 by lrocigno          #+#    #+#             */
/*   Updated: 2022/02/28 10:05:03 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <lexer/helpers.h>
#include <stdio.h>

/**
 * @brief Count how many characters a value string will contain.
 *
 * @param input: A pointer to input string.
 * @return the predicted size.
 */
static size_t	val_len(char **input)
{
	size_t	len;
	char	*aux;

	if (!(**input))
		return (0);
	len = 0;
	while (is_space(**input))
		++(*input);
	aux = *input;
	while (is_stop(&aux) == 0)
	{
		if (is_quote(*aux) && get_quote() == '\0')
			set_quote(aux);
		if (*aux != get_quote())
			++len;
		++aux;
	}
	return (len);
}

char	*get_value(char **input)
{
	size_t	i;
	size_t	len;
	char	*ret;

	i = 0;
	len = val_len(input);
	if (!len)
		return (NULL);
	ret = malloc(sizeof (*ret) * (len + 1));
	if (!ret)
		return (NULL);
	while (is_stop(input) == 0)
	{
		if (is_quote(**input) && get_quote() == '\0')
			set_quote(*input);
		if (**input != get_quote())
		{
			ret[i] = **input;
			++i;
		}
		++(*input);
	}
	ret[i] = '\0';
	return (ret);
}
