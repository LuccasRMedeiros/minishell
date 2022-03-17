/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.o...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:39:17 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/03/17 17:05:41 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>

t_token	*new_token(t_token_type type, t_token *prev)
{
	t_token	*token;

	token = ft_calloc(1, sizeof(t_token));
	if (token == NULL)
		return (NULL);
	token->prev = prev;
	if (prev != NULL)
		prev->next = token;
	token->type = type;
	return (token);
}

t_token	*clear_tokens(t_token *token)
{
	t_token	*next;

	while (token != NULL)
	{
		next = token->next;
		if (token->value != NULL)
			safe_free((void **)&(token->value));
		safe_free((void **)&token);
		token = next;
	}
	return (NULL);
}

t_token_type	token_type(char *input)
{
	if ((is_operator(input) != 0))
		return (T_OPERATOR);
	return (T_WORD);
}
