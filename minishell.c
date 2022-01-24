/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:27:14 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/24 16:21:24 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	validate_command(char *command)
{
	if (*command)
		printf("minishell: %s: command not found\n", command);
	else
		write(1, "\n", 1);
}

int	main(void)
{
	char	*input;

	printf("\e[1;32mminishell\e[0m:\e[0;34m~\e[0m$: ");
	input = readline(NULL);
	while (ft_strncmp("exit", input, ft_strlen(input)) || !*input)
	{
		validate_command(input);
		printf("\e[1;32mminishell\e[0m:\e[0;34m~\e[0m$: ");
		free(input);
		input = readline(NULL);
	}
	free(input);
	input = NULL;
	return (0);
}
