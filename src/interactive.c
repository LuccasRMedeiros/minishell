/* ************************************************************************** */
/*                                                                            */
/*                                                          :::	   ::::::::   */
/*   interactive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.o...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 20:12:16 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/03/17 19:35:14 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <prompt/prompt.h>
#include <lexer/lexer.h>
#include <unistd.h>

/**
 * @brief Stores the input on the history, then validates and tokenize it.
 *
 * @param input: The user input
 * @return 1 if the input is a valid command, 0 if not.
 */
static uint8_t	validate(char **input)
{
	t_token	*token;

	if (*input != NULL && ft_strlen(*input) == 0)
		return (0);
	if (*input == NULL)
		return (1);
	add_history(*input);
	token = NULL;
	token = tokenize(*input);
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
