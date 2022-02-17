/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 00:52:29 by lrocigno          #+#    #+#             */
/*   Updated: 2022/02/15 23:35:37 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <lexer/helpers.h>

/**
 * Calculate the total size of the token value.
 */

static size_t	val_len(char **input)
{
	char	*aux;
	size_t	len;

	len = 0;
	while (is_space(**input))
		++(*input);
	aux = *input;
	while (is_stop(&aux) == 0)
	{
		if (is_quote(*aux) && get_quote() == '\0')
			set_quote(aux);
		else if (*aux != get_quote())
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
	ret = ft_calloc(len + 1, sizeof (*ret));
	if (!ret)
		return (NULL);
	while (is_stop(input) == 0)
	{
		if (is_quote(**input) && get_quote() == '\0')
			set_quote(*input);
		else
		{
			ret[i] = **input;
			++i;
		}
		++(*input);
	}
	return (ret);
}
