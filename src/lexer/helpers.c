/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 00:06:32 by lrocigno          #+#    #+#             */
/*   Updated: 2022/02/13 22:26:30 by lrocigno         ###   ########.fr       */
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
	
	if (is_quote(*input) && get_quote() == '\0')
		set_quote(input);
	stop = get_quote();
	if (stop == '\0')
		stop = ' ';
	if (is_quote(stop))
	{
		if (*input == stop)
			*close_q +=1;
		if (*close_q == cq_sig)
		{
			clear_quote();
			if (ft_isalnum(*(input + 1)) == 0)
				return (1);
		}
	}
	else if (*input == stop || *input == '\0' || *input == '#')
		return (1);
	return (0);
}
