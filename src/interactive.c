/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 interface.c										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: vgoncalv <vgoncalv@student.42sp.org.br>	+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2022/01/27 20:12:16 by vgoncalv		   #+#	  #+#			  */
/*   Updated: 2022/03/14 17:16:42 by vgoncalv         ###   ########.fr       */
/*																			  */
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
	if (tokens->type == EXTERNAL)
		exec_extcmd(tokens);
	clear_token_list(tokens);
	add_history(input);
	return (0);
}

void	interactive()
{
	char	*input;

	input = prompt(g_sh);
	if (validate(input))
	{
		safe_free((void **)&input);
		return ;
	}
	safe_free((void **)&input);
	interactive(input);
}
