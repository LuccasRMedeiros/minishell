/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 interface.c										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: vgoncalv <vgoncalv@student.42sp.org.br>	+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2022/01/27 20:12:16 by vgoncalv		   #+#	  #+#			  */
/*   Updated: 2022/03/14 15:34:05 by vgoncalv         ###   ########.fr       */
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

void	interface(char *input)
{
	input = prompt(g_sh);
	if (validate(input))
	{
		safe_free((void **)&input);
		return ;
	}
	safe_free((void **)&input);
	interface(input);
}
