/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 23:04:44 by lrocigno          #+#    #+#             */
/*   Updated: 2022/02/28 10:50:34 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>

t_token	*new_token(const char *value, t_type type)
{
	t_token	*new;

	new = ft_calloc(1, sizeof (*new));
	if (!new)
		return (NULL);
	new->value = value;
	new->type = type;
	new->next = NULL;
	return (new);
}

void	clear_token_list(t_token *del)
{
	t_token	*aux;
	char	*value;

	while (del != NULL)
	{
		aux = del->next;
		value = (char *)del->value;
		free(value);
		value = NULL;
		free(del);
		del = NULL;
		del = aux;
	}
}
