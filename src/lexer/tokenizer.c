/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.o...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:33:15 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/03/17 13:48:41 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>

static t_token_type	get_type(char *input)
{
	if ((is_operator(input) != 0))
		return (T_OPERATOR);
	return (T_WORD);
}

static char	*token_value(t_token_type type, char *input, size_t *offset)
{
	if (type == T_WORD)
		return (word(input, offset));
	if (type == T_OPERATOR)
		return (operator(input, offset));
	return (NULL);
}

t_token	*tokenize(char *input)
{
	size_t			offset;
	t_token_type	type;
	t_token			*start;
	t_token			*token;

	offset = 0;
	start = NULL;
	token = NULL;
	while (input[offset] != '\0')
	{
		if ((is_space(input[offset]) != 0) && ++offset)
			continue ;
		type = get_type(input + offset);
		token = new_token(type, token);
		if (token == NULL)
			return (clear_tokens(start));
		token->value = token_value(type, input, &offset);
		if (start == NULL)
			start = token;
		if (input[offset] != '\0')
			offset++;
	}
	return (start);
}
