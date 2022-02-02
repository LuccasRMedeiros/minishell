/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:49:35 by lrocigno          #+#    #+#             */
/*   Updated: 2022/02/02 01:24:11 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>

void	discard_tokens(t_token **tokens)
{
	size_t	i;

	i = 0;
	while (tokens[i]->type != INVALID)
	{
		del_token(tokens[i]);
		++i;
	}
	del_token(tokens[i]);
	safe_free((void **)&tokens); // O compilador está dizendo que a declaração é inválida.
}

/**
 * Count the amount of tokens to create a array of them.
 */

static size_t	cnt_tokens(char *input)
{
	size_t	cnt;
	size_t	i;
	int		quotes;
	int		is_word;

	cnt = 0;
	i = 0;
	quotes = 0;
	is_word = 0;
	while (input[i] != '\0' && input[i] != '#')
	{
		if (ft_isalnum(input[i]) && !is_word)
		{
			++cnt;
			is_word = 1;
		}
		else if (lex_isspace(input[i]) && quotes % 2 == 0)
			is_word = 0;
		else if (input[i] == '\"' || input[i] == '\'')
			++quotes;
		++i;
	}
	return (cnt);
}

t_token	**tokenizer(char *input)
{
	size_t	n_tokens;
	size_t	i;
	t_type	type;
	char	*value;
	t_token	**tokens;

	n_tokens = cnt_tokens(input);
	i = 0;
	tokens = ft_calloc(n_tokens + 1, sizeof (*tokens));
	while (i < n_tokens)
	{
		type = get_type(i, input);
		value = get_value(type, input);
		tokens[i] = new_token(type, value);
		++i;
	}
	tokens[i] = new_token(INVALID, NULL);
	return (tokens);
}