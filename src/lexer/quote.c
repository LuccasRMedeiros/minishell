/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:44:57 by lrocigno          #+#    #+#             */
/*   Updated: 2022/02/13 16:51:43 by lrocigno         ###   ########.fr       */
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
	int		open_q;
	char	q;

	open_q = 1;
	q = *input;
	while (open_q == 1 && *input != '\0')
	{
		++input;
		if (*input == q)
		{
			open_q = 0;
			q = *input;
		}
	}
	if (open_q == 0)
		quote(q);
}

void	clear_quote(void)
{
	quote('d');
}
