/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:49:35 by lrocigno          #+#    #+#             */
/*   Updated: 2022/02/26 16:10:43 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <lexer/helpers.h>

/**
 * Generate a token and return it. The subroutine exists to help to construct
 * the list of tokens.
 */

static t_token	*generate_token(INTchar **input)
{
	char	*value;

	value = get_value(input);
	if (!value)
		return (NULL);
	return (new_token(value));
}

t_token	*tokenizer(char *input)
{
	t_token	*head;
	t_token	*tokens;

	clear_quote();
	head = NULL;
	while (is_space(*input))
		++input;
	head = generate_token(&input);
	tokens = head;
	while (tokens)
	{
		tokens->next = generate_token(&input);
		tokens = tokens->next;
	}
	return (head);
}
