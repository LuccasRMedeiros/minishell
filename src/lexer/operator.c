/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.o...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:19:40 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/03/17 14:05:26 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>

char	*operator(char *input, size_t *offset)
{
	size_t		len;
	char		operator;
	char		*value;
	const char	*start;

	len = 1;
	start = input + (*offset);
	operator = *start;
	if (operator == start[1])
	{
		len++;
	}
	value = ft_substr(input, *offset, len);
	if (value == NULL)
		return (NULL);
	*offset += len;
	return (value);
}
