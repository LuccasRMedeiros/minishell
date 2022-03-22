/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.o...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 12:23:46 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/03/20 12:30:55 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>

t_ast	*parser_error(t_ast *node, t_token *token)
{
	char	*fmt;

	if (token != NULL)
		fmt = "minishell: parsing error near '%s'\n";
	else
		fmt = "minishell: internal parsing error\n";
	ft_dprintf(STDERR_FILENO, fmt, token->value);
	if (node != NULL)
		clear_node(node);
	return (NULL);
}
