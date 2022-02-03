/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_new_del.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 23:04:44 by lrocigno          #+#    #+#             */
/*   Updated: 2022/02/02 14:51:03 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>

void	del_token(t_token *del)
{
	char	*value;

	value = (char *)del->value;
	free(value);
	value = NULL;
	del->type = INVALID;
	free(del);
	del = NULL;
}

t_token	*new_token(t_type type, const char *value)
{
	t_token	*new;

	new = ft_calloc(1, sizeof (*new));
	if (!new)
		return (NULL);
	new->type = type;
	new->value = value;
	return (new);
}
