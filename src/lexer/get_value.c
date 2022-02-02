/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 00:52:29 by lrocigno          #+#    #+#             */
/*   Updated: 2022/02/02 01:17:47 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>

char	*get_value(t_type type, char *input)
{
	size_t	len;
	char	*ret;

	len = 0;
	while (*input)
	{
		if (ft_isalnum(*input) || type == STRING_LITERAL)
			++len;
		else if (lex_isspace(*input))
			break ;
		++input;
	}
	ret = ft_calloc(len, sizeof (*ret));
	return (ret);
}
