/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 00:06:32 by lrocigno          #+#    #+#             */
/*   Updated: 2022/02/05 16:32:22 by lrocigno         ###   ########.fr       */
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

int	is_stop(char c)
{
	char stop;

	stop = get_quote();
	if (!stop)
		stop = ' ';
	return (c == '#' || c == stop || c == '\0');
}
