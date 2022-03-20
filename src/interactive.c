/* ************************************************************************** */
/*                                                                            */
/*                                                          :::	   ::::::::   */
/*   interactive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.o...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 20:12:16 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/03/20 14:02:19 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <prompt/prompt.h>
#include <lexer/lexer.h>
#include <parser/parser.h>

/**
 * @brief Stores the input on the history, then validates and tokenize it.
 *
 * @param input: The user input
 * @return 1 if the input is a valid command, 0 if not.
 */
static uint8_t	validate(char **input)
{
	t_ast		*ast;
	t_token		*token;

	if (*input == NULL)
		return (1);
	if (ft_strlen(*input) == 0)
		return (0);
	add_history(*input);
	token = tokenize(*input);
	ast = build_ast(token);
	clear_ast(ast);
	clear_tokens(token);
	return (0);
}

void	interactive(void)
{
	char	*input;

	input = prompt();
	if (validate(&input))
	{
		safe_free((void **)&input);
		return ;
	}
	safe_free((void **)&input);
	interactive();
}
