/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:44:57 by lrocigno          #+#    #+#             */
/*   Updated: 2022/02/02 14:41:59 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>

char	get_quote(void)
{
	static char	fq;

	return (fq);
}

void	set_quote(char q)
{
	char	*fq;

	fq = NULL;
	*fq = get_quote();
	*fq = q;
}
