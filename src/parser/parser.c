/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.o...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 13:26:57 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/03/20 14:08:34 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>

/**
 * @brief Builds the AST
 *
 * @param token: The starting token
 * @return: The built AST
 */
t_ast	*build_ast(t_token *token)
{
	t_ast	*ast;

	if (token == NULL)
		return (NULL);
	ast = NULL;
	while (token != NULL)
	{
		if (token->type == T_WORD)
			ast = parse_command(&token);
		else
			error();
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
