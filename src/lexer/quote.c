/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:44:57 by lrocigno          #+#    #+#             */
/*   Updated: 2022/02/02 20:31:11 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>

char	quote(char flag)
{
	static char	fq;

	if (flag == '\"' || flag == '\'')
		fq = flag;
	else if (flag == 'd')
		fq = '\0';
	return (fq);
}
