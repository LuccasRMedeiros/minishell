/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 20:12:16 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/02/06 22:11:43 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <prompt/prompt.h>

static char	validate(char *input)
{
	t_token	*tokens;

	if (input == NULL || ft_strlen(input) == 0)
		return (0);
	if (ft_strncmp("exit", input, ft_strlen(input)) == 0)
		return (1);
	tokens = tokenizer(input);
	// ------ remover depois
	t_token *test = tokens;
	while (test != NULL)
	{
		printf("%s\n", test->value);
		test = test->next;
	}
	// ---------------------
	clear_token_list(tokens);
	add_history(input);
	return (0);
}

void	interface(char *input, t_shell *sh)
{
	input = prompt(sh);
	if (validate(input))
	{
		safe_free((void **)&input);
		free_sh(sh);
		exit(EXIT_SUCCESS);
	}
	safe_free((void **)&input);
	interface(input, sh);
}
