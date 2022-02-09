/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 00:52:29 by lrocigno          #+#    #+#             */
/*   Updated: 2022/02/08 23:22:01 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <lexer/helpers.h>

/**
 * Calculate the total size of the token value.
 */

static size_t	val_len(char *input, int open_q)
{
	size_t	len;

	len = 0;
	while (is_stop(*input) == 0 || open_q == 1)
	{
		++len;
		++input;
		if (*input == get_quote() && ++input)
			open_q += 1;
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
	while (is_space(**input) || **input == get_quote())
	{
		if (**input == get_quote() && open_q == 0)
			open_q = 1;
		++(*input);
	}
	len = val_len(*input, open_q);
	ret = ft_calloc(len + 1, sizeof (*ret));
	while (is_stop(**input) == 0 || open_q == 1)
	{
		ret[i] = **input;
		++i;
		++(*input);
		if (**input == get_quote() && ++(*input))
			open_q += 1;
	}
	clear_quote();
	return (ret);
}
