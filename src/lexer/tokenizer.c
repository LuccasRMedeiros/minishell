/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:49:35 by lrocigno          #+#    #+#             */
/*   Updated: 2022/02/05 16:37:52 by lrocigno         ###   ########.fr       */
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
		if (isword == 0)
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
	return (cnt);
}

t_token	*tokenizer(char *input)
{
	t_type	type;
	char	*value;
	t_token	*tokens;
	int		n_tks;
	int		tk_n;

	while(is_space(*input))
		++input;
	n_tks = pred_tokens(input);
	tk_n = 0;
	while (tk_n < n_tks)
	{
		value = get_value(input);
		type = get_type(tk_n, value);
		tokens = new_token(type, value);
		input += ft_strlen(value);
		++tk_n;
	}
	return (tokens);
}
