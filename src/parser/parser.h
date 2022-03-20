/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.o...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 13:37:02 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/03/20 14:01:30 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <lexer/lexer.h>

# define L_PIPE "|"
# define L_IF_OR "||"
# define L_IF_AND "&&"

typedef struct s_command
{
	const char	*cmd;
	const char	**args;
}	t_command;

typedef struct s_child
{
	struct s_ast	*left;
	struct s_ast	*right;
}	t_child;

typedef enum e_ast_type
{
	BUILTIN,
	COMMAND,
	PIPE,
	IF_OR,
	IF_AND,
	AST_COUNT,
}	t_ast_type;

typedef struct s_ast
{
	t_ast_type	type;
	union u_internal {
		t_child		*child;
		t_command	*command;
	}			internal;
}	t_ast;

t_ast	*new_node(t_ast_type type);

void	clear_node(t_ast	*node);

t_ast	*parser_error(t_ast *node, t_token *token);

t_ast	*parse_command(t_token **token);

t_ast	*build_ast(t_token *token);

void	clear_ast(t_ast *ast);

#endif
