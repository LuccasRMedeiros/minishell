/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:49:35 by lrocigno          #+#    #+#             */
/*   Updated: 2022/02/28 10:47:06 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <lexer/helpers.h>

/**
 * @brief Generate a token and return it. The subroutine exists to help to 
 * construct the list of tokens.
 *
 * @param order: The order the token appear on the list.
 * @param input: The pointer to the input string.
 * @return one node with one value accquired and its type.
 */
static t_token	*generate_token(int order, char **input)
{
	char	*value;
	t_type	type;

	value = get_value(input);
	if (!value)
		return (NULL);
	type = get_type(order, value);
	return (new_token(value, type));
}

t_token	*tokenizer(char *input)
{
	t_token	*head;
	t_token	*tokens;
	int		order;

	clear_quote();
	head = NULL;
	while (is_space(*input))
		++input;
	head = generate_token(0, &input);
	tokens = head;
	order = 1;
	while (tokens)
	{
		tokens->next = generate_token(order, &input);
		tokens = tokens->next;
		++order;
	}
	return (head);
}
