/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:27:14 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/25 19:31:22 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	validate_command(char *command)
{
	if (*command)
		printf("minishell: %s: command not found\n", command);
}

static char	*gen_prompt(char **envp)
{
	size_t	i;
	char	*user;
	char	*prompt;

	i = 0;
	while (ft_strncmp("USER", envp[i], 4))
		++i;
	user = ft_strjoin("\e[1;32m", ft_strchr(envp[i], '=') + 1);
	prompt = ft_strjoin(user, "@minishell\e[0m:\e[0;34m~\e[0m$: ");
	free(user);
	user = NULL;
	return (prompt);
}

int	main(int argc, char **argv, char **envp)
{
	char	*prompt;
	char	*input;

	if (argc > 1)
	{
		printf("minishell: %s: No such file or directory\n", argv[1]);
		exit(127);
	}
	prompt = gen_prompt(envp);
	input = readline(prompt);
	while (ft_strncmp("exit", input, ft_strlen(input)) || !*input)
	{
		validate_command(input);
		free(input);
		input = readline(prompt);
	}
	free(input);
	free(prompt);
	input = NULL;
	prompt = NULL;
	return (0);
}
