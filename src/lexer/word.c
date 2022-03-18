/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.o...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:47:28 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/03/18 08:43:22 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <lexer/lexer.h>

/**
 * @brief: Checks if a word is surrounded by quotes
 *
 * @param start: The begining of the search on the string
 * @return: the surrounding quote character
 */
static char	quoted_word(char *start)
{
	char	quote;
	size_t	offset;

	if (*start != '"' && *start != '\'')
		return (0);
	quote = 0;
	offset = 0;
	while (start[++offset] != '\0')
	{
		if (start[offset] == *start)
		{
			quote = *start;
			break ;
		}
	}
	return (quote);
}

/**
 * @brief: Calculate the size of a word
 *
 * @param input: The user input
 * @param quote: A quote char
 * @return the calculated size
 */
static size_t	wordlen(char *input, char quote)
{
	size_t		len;
	uint8_t		first_quote;

	len = 0;
	first_quote = (quote != 0);
	while (*input != '\0')
	{
		if (quote == 0 && is_metachar(input))
			break ;
		len++;
		if (quote != 0 && *input == quote)
		{
			if (first_quote == 1)
				first_quote = 0;
			else
				break ;
		}
		input += 1;
	}
	return (len);
}

char	*word(char *input, size_t *offset)
{
	size_t	len;
	char	quote;
	char	*word;

	quote = quoted_word(input + (*offset));
	len = wordlen(input + (*offset), quote);
	word = ft_substr(input, *offset, len);
	if (word == NULL)
		return (NULL);
	*offset += len;
	return (word);
}
