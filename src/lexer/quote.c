/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:44:57 by lrocigno          #+#    #+#             */
/*   Updated: 2022/02/05 16:34:08 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/helpers.h>

static char	quote(char flag)
{
	static char	fq;

	if (flag == '\"' || flag == '\'')
		fq = flag;
	else if (flag == 'd')
		fq = '\0';
	return (fq);
}

char	get_quote(void)
{
	return (quote('g'));
}

void	set_quote(char *input)
{
	char	q;

	q = '\0';
	while (*input != q)
	{
		if (is_quote(*input))
		{
			if (q == '\0')
				q = *input;
			else if (*input == q)
			{
				quote(*input);
				return ;
			}
		}
		++input;
	}
}

void	clear_quote(void)
{
	quote('d');
}
