/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 00:06:32 by lrocigno          #+#    #+#             */
/*   Updated: 2022/02/13 16:29:27 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/helpers.h>

int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\r')
		return (1);
	else if (c == '\n' || c == '\v' || c == '\f')
		return (1);
	return (0);
}

int	is_quote(char c)
{
	return (c == '\"' || c == '\'');
}

int	is_stop(char *input, int *close_q, int cq_sig)
{
	char	stop;

	stop = get_quote();
	if (stop == '\0' || *close_q == cq_sig)
		stop = ' ';
	if (is_quote(stop))
	{
		if (*input == get_quote())
			*close_q += 1;
		if (*close_q == cq_sig)
		{
			if (ft_isalnum(*(input + 1)) == 0)
				return (1);
		}
	}
	else if (*input == stop || *input == '#' || *input == '\0')
		return (1);
	return (0);
}
