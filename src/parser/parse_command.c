/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.o...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 11:34:20 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/03/20 13:58:27 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>

/**
 * @brief Gets the number of arguments in a command
 *
 * @see t_command
 * @param token: the starting token
 */
static size_t	argslen(t_token *token)
{
	size_t	len;

	len = 0;
	while (token != NULL)
	{
		if (token->type != T_WORD)
			break ;
		len++;
		token = token->next;
	}
	return (len - 1);
}

/**
 * @brief Parses a command and updates the AST accordingly
 *
 * @param token: the starting token to be parsed
 * @return: the AST root node
 */
t_ast	*parse_command(t_token **token)
{
	size_t		argc;
	size_t		count;
	t_ast		*command;

	command = new_node(COMMAND);
	if (command == NULL)
		return (NULL);
	argc = argslen(*token);
	command->internal.command->args = ft_calloc(1, (argc + 1) * sizeof(char *));
	if (command->internal.command->args == NULL)
		return (parser_error(command, NULL));
	count = 0;
	while (*token != NULL)
	{
		if ((*token)->type != T_WORD)
			break ;
		if (command->internal.command->cmd == NULL)
			command->internal.command->cmd = (*token)->value;
		else if (count < argc)
			command->internal.command->args[count++] = (*token)->value;
		else
			return (parser_error(command, *token));
		*token = (*token)->next;
	}
	return (command);
}
