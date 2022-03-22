/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.o...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 13:26:57 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/03/22 11:32:01 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>

static t_ast	*insert_node(t_ast *ast, t_ast *node, t_token *token)
{
	if (node == NULL)
		return (parser_error(node, token));
	if (node->type == COMMAND || node->type == BUILTIN)
	{
		if (ast == NULL)
			return (node);
		if (ast->type == COMMAND)
		{
			clear_ast(ast);
			return (parser_error(node, token));
		}
		ast->internal.child->right = node;
		return (ast);
	}
	if (ast == NULL)
		return (parser_error(node, token));
	if (node->type == PIPE)
	{
		node->internal.child->left = ast;
		return (node);
	}
	clear_node(node);
	return (NULL);
}

/**
 * @brief Builds the AST
 *
 * @param token: The starting token
 * @return: The built AST
 */
t_ast	*build_ast(t_token *token)
{
	t_ast	*ast;
	t_ast	*node;

	ast = NULL;
	node = NULL;
	while (token != NULL)
	{
		if (token->type == T_WORD)
			node = parse_command(&token);
		else
			node = parse_operator(&token);
		ast = insert_node(ast, node, token);
		if (ast == NULL)
			return (NULL);
	}
	return (ast);
}

/**
 * @brief Clears the AST
 *
 * @param ast: The AST to be cleared
 */
void	clear_ast(t_ast *ast)
{
	t_ast	*left;
	t_ast	*right;

	if (ast == NULL)
		return ;
	if (ast->type == COMMAND)
	{
		clear_node(ast);
		return ;
	}
	left = ast->internal.child->left;
	right = ast->internal.child->right;
	clear_ast(left);
	clear_ast(right);
	clear_node(ast);
}
