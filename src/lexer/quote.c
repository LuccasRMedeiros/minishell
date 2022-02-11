/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:44:57 by lrocigno          #+#    #+#             */
/*   Updated: 2022/02/09 22:38:18 by lrocigno         ###   ########.fr       */
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

	open_q = 0;
	q = '\0';
	while ((*input != ' ' || open_q == 1) && *input != '\0' && *input != '#')
	{
		if (is_quote(*input) && (q == '\0' || *input == q))
		{
			open_q += 1;
			q = *input;
		}
		++input;
	}
	if (open_q == 2)
		quote(q);
}

void	clear_quote(void)
{
	quote('d');
}
