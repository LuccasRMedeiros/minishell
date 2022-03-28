/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_operator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.o...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 08:40:28 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/03/24 11:59:30 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>

static t_ast_type	get_type(t_token *token)
{
	if ((ft_strcmp(token->value, L_PIPE) == 0))
		return (PIPE);
	if ((ft_strcmp(token->value, L_IF_OR) == 0))
		return (IF_OR);
	if ((ft_strcmp(token->value, L_IF_AND) == 0))
		return (IF_AND);
	return (AST_COUNT);
}

/**
 * @brief Parses an operator token
 *
 * @param token: The starting token
 * @return: the operator node
 */
t_ast	*parse_operator(t_token **token)
{
	t_ast		*node;
	t_ast_type	type;

	type = get_type(*token);
	node = new_node(type);
	if (node == NULL)
		return (parser_error(NULL, *token));
	*token = (*token)->next;
	return (node);
}
