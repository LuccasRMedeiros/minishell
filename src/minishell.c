/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:27:14 by lrocigno          #+#    #+#             */
/*   Updated: 2022/01/27 15:57:06 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	validate_command(char *command)
{
	if (*command)
	{
		printf("minishell: %s: command not found\n", command);
		add_history(command);
	}
}

static char	*gen_prompt(const char *user, const char *pwd)
{
	char	*prompt;
	size_t	prompt_size;

	prompt_size = PROMPT_SIZE + ft_strlen(user) + ft_strlen(pwd);
	prompt = ft_calloc(prompt_size, sizeof (char *));
	ft_strlcpy(prompt, "\e[1;32m", prompt_size);
	ft_strlcat(prompt, user, prompt_size);
	ft_strlcat(prompt, "@minishell\e[0m:\e[0;34m", prompt_size);
	ft_strlcat(prompt, pwd, prompt_size);
	ft_strlcat(prompt, "\e[0m$ ", prompt_size);
	return (prompt);
}

int	main(int argc, char **argv)
{
	char	*prompt;
	char	*input;

	if (argc > 1)
	{
		printf("minishell: %s: No such file or directory\n", argv[1]);
		exit(127);
	}
	prompt = gen_prompt(getenv("USERNAME"), getenv("PWD"));
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
