/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 00:52:29 by lrocigno          #+#    #+#             */
/*   Updated: 2022/02/13 16:52:32 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <lexer/helpers.h>

/**
 * Calculate the total size of the token value.
 */

static char	*val_len(char **input, size_t *len)
{
	int		open_q;
	char	*aux;

	*len = 0;
	open_q = 0;
	while (is_space(**input))
		++(*input);
	aux = *input;
	while (is_stop(aux, &open_q, 1) == 0)
	{
		if (is_quote(*aux) && get_quote() == '\0')
			set_quote(aux);
		if (*aux != get_quote())
			++(*len);
		++aux;
	}
	return (*input);
}

char	*get_value(char **input)
{
	int		open_q;
	size_t	i;
	size_t	len;
	char	*ret;

	open_q = 0;
	i = 0;
	*input = val_len(input, &len);
	if (!len)
		return (NULL);
	ret = ft_calloc(len + 1, sizeof (*ret));
	if (!ret)
		return (NULL);
	while (is_stop(*input, &open_q, 2) == 0)
	{
		if (**input != get_quote())
		{
			ret[i] = **input;
			++i;
		}
		++(*input);
	}
	clear_quote();
	return (ret);
}
