/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 15:27:30 by lrocigno          #+#    #+#             */
/*   Updated: 2022/02/05 15:38:15 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>

int	isquote(char inchar)
{
	return (inchar == '\"' || inchar == '\'');
}

int	isstop(char inchar)
{
	char stop;

	stop = quote('g');
	if (!stop)
		stop = ' ';
	return (inchar == '#' || inchar == stop || inchar == '\0');
}
