/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 00:52:29 by lrocigno          #+#    #+#             */
/*   Updated: 2022/02/10 22:42:28 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <lexer/helpers.h>

/**
 * Calculate the total size of the token value.
 */

static size_t	val_len(char **input)
{
	size_t	len;
	char	*aux;

	len = 0;
	while (is_space(**input) || **input == get_quote())
	{
		++(*input);
		if (is_quote(**input) && get_quote() == '\0')
			set_quote(*input);
	}
	aux = *input;
	while (is_stop(*aux) == 0)
	{
		++len;
		++aux;
	}
	return (len);
}

char	*get_value(char **input)
{
	int		open_q;
	size_t	i;
	size_t	len;
	char	*ret;

	open_q = 0;
	i = 0;
	len = val_len(input);
	ret = ft_calloc(len + 1, sizeof (*ret));
	while (is_stop(**input) == 0 || open_q == 1)
	{
		ret[i] = **input;
		++i;
		++(*input);
		if (**input == get_quote())
			open_q = open_q == 0;
	}
	clear_quote();
	return (ret);
	}
