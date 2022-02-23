/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 20:19:05 by lrocigno          #+#    #+#             */
/*   Updated: 2022/02/22 23:02:37 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <external/external_cmd.h>

static char	*choose_path(char *cmd, char *syspath)
{
	char	**spl_path;
	char	*test_p;
	size_t	path_i;

	if (access(cmd, F_OK))
		return (cmd);
	spl_path = ft_split(syspath, ':');
	path_i = 0;
	while (spl_path[path_i] != NULL)
	{
		ft_asprintf(test_p, "%s/%s", spl_path[path_i], cmd);
		if (access(cmd, F_OK))
			return (test_p);
		safe_free(test_p);
		++path_i;
	}
	return (NULL);
}

static int	sub_process(t_token *tokens, t_shell *sh)
{
	char	*full_name;
	char	**argv;
	char	**envp;

	full_name = choose_path(tokens, get_env_value("PATH", sh));
	if (!full_name)
		return (0);
	argv = gen_argv(tokens);
	envp = gen_envp(sh);
	if (!argv || !envp)
		return (0);
	execve(full_name, argv, envp);
	safe_free(argv);
	safe_free(envp);
	return (1);
}

void	exec_extcmd(t_token *tokens, t_shell *sh)
{
	int	wstatus;

	new_pid = fork();
	if (!new_pid)
		sub_process(tokens, sh);
	else
		wait(&wstatus);
}
