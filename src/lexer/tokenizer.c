/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.o...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:33:15 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/03/17 19:04:15 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <unistd.h>

/**
 * @brief Return the value for the token
 *
 * @param type: The token type
 * @param input: The user input
 * @param offset: Where the tokenization begins
 * @return the value of the token
 */
static char	*token_value(t_token_type type, char *input, size_t *offset)
{
	if (type == T_WORD)
		return (word(input, offset));
	if (type == T_OPERATOR)
		return (operator(input, offset));
	return (NULL);
}

static t_token	*unexpected_error(t_token *start, char *input, size_t offset)
{
	char	*token_value;

	token_value = word(input, &offset);
	ft_asprintf(&(g_sh->error_msg), "minishell: unexpected error near %s\n",
			   token_value);
	clear_tokens(start);
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
		type = token_type(input + offset);
		token = new_token(type, token);
		if (token == NULL)
			return (unexpected_error(start, input, offset));
		token->value = token_value(type, input, &offset);
		if (token->value == NULL)
			return (unexpected_error(start, input, offset));
		token = heredocs(token, input, &offset);
		if (token == NULL)
			return (clear_tokens(start));
		if (start == NULL)
			start = token;
	}
	return (start);
}
