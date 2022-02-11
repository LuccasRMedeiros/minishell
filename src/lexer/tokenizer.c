/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:49:35 by lrocigno          #+#    #+#             */
/*   Updated: 2022/02/07 22:43:30 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <lexer/helpers.h>

/**
 * Predict the amount of tokens.
 */

static int	pred_tokens(char *input)
{
	int	cnt;
	int	isword;

	cnt = 0;
	isword = 0;
	clear_quote();
	while(*input != '\0')
	{
		if (is_quote(*input) && get_quote() == '\0')
			set_quote(input);
		else if (isword == 0)
		{
			if (is_stop(*input) == 0)
			{
				++cnt;
				isword = 1;
			}
		}
		else if (is_stop(*input))
			isword = 0;
		++input;
	}
	clear_quote();
	return (cnt);
}

/**
 * Generate a token and return it. The subroutine exists to help to construct
 * the list of tokens.
 */

static t_token	*generate_token(char **input, int tk_n)
{
	t_type	type;
	char	*value;

	value = get_value(input);
	type = get_type(tk_n, value);
	return (new_token(type, value));
}

t_token	*tokenizer(char *input)
{
	int		n_tks;
	t_token	*head;
	t_token	*tokens;
	int		tk_n;

	head = NULL;
	while(is_space(*input))
		++input;
	n_tks = pred_tokens(input);
	head = generate_token(&input, 0);
	tokens = head;
	tk_n = 1;
	while (tk_n < n_tks)
	{
		tokens->next = generate_token(&input, tk_n);
		tokens = tokens->next;
		++tk_n;
	}
	return (head);
}
