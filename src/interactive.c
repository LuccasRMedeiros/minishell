/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*   interactive.c                                      :+:      :+:    :+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: vgoncalv <vgoncalv@student.42sp.org.br>	+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2022/01/27 20:12:16 by vgoncalv		   #+#	  #+#			  */
/*   Updated: 2022/03/16 00:41:36 by lrocigno         ###   ########.fr       */
/*																			  */
/* ************************************************************************** */

#include <minishell.h>
#include <prompt/prompt.h>
#include <lexer/lexer.h>

/**
 * @brief Stores the input on the history, then validates and tokenize it.
 *
 * @param input: The user input
 * @return 1 if the input is a valid command, 0 if not.
 */
static uint8_t	validate(char *input)
{
	t_token	*token;

	if (input == NULL || ft_strlen(input) == 0)
		return (0);
	add_history(input);
	if (ft_strncmp("exit", input, ft_strlen(input)) == 0)
		return (1);
	token = tokenize(input);
	if (token == NULL && ft_strlen(input) > 0)
		ft_dprintf(STDERR_FILENO, "Error while parsing the input: %s\n", input);
	clear_tokens(token);
	return (0);
}

/**
 * @brief Print the prompt and receive input from the user
 */
void	interactive(void)
{
	char	*input;

	input = prompt(g_sh);
	if (validate(input))
	{
		safe_free((void **)&input);
		return ;
	}
	safe_free((void **)&input);
	interactive();
}
