/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.o...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 13:47:34 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/03/20 14:08:45 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>

/**
 * @brief Creates a new node for the AST
 *
 * @param type: The type of the node
 * @return: The created node
 */
t_ast	*new_node(t_ast_type type)
{
	t_ast		*node;

	node = ft_calloc(1, sizeof(t_ast));
	if (node == NULL)
		return (NULL);
	node->type = type;
	if (type == BUILTIN || type == COMMAND)
	{
		node->internal.command = ft_calloc(1, sizeof(t_command));
		if (node->internal.command == NULL)
			safe_free((void **)&node);
		return (node);
	}
	node->internal.child = ft_calloc(1, sizeof(t_child));
	if (node->internal.child == NULL)
		safe_free((void **)&node);
	return (node);
}

void	clear_node(t_ast	*node)
{
	if (node == NULL)
		return ;
	if (node->type == COMMAND)
	{
		safe_free((void **)&(node->internal.command->args));
		safe_free((void **)&(node->internal.command));
	}
	else
		safe_free((void **)&(node->internal.child));
	safe_free((void **)&node);
}
