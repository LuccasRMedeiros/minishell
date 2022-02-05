/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 00:52:29 by lrocigno          #+#    #+#             */
/*   Updated: 2022/02/05 16:29:10 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <lexer/helpers.h>

/**
 * Calculate the total size of the token value.
 */

static size_t	val_len(char *input)
{
	size_t	len;

	len = 0;
	while (is_stop(*input) == 0)
	{
		if (is_quote(*input) && get_quote() == '\0')
			set_quote(input);
		else if (ft_isalnum(*input) || get_quote() != '\0')
			++len;
		++input;
	}
	return (len);
}

char	*get_value(char *input)
{
	size_t	i;
	size_t	len;
	char	*ret;

	i = 0;
	while (is_space(*input))
		++input;
	len = val_len(input);
	ret = ft_calloc(len, sizeof (*ret));
	while (is_stop(*input) == 0)
	{
		if (ft_isalnum(*input) || get_quote() != '\0')
		{
			ret[i] = *input;
			++i;
		}
		++input;
	}
	clear_quote();
	return (ret);
}
