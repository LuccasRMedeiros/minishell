/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.o...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:39:17 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/03/16 00:40:38 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>

/**
 * @brief Creates a new token
 *
 * @see: struct s_token
 * @param type: the type of the created token
 * @param prev: the previous token in the list
 * @return: the new token
 */
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

/**
 * @brief: Clears the tokens list
 *
 * @param token: the head of the token list
 * @return: always returns NULL
 */
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
