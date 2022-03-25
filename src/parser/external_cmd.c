/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 20:19:05 by lrocigno          #+#    #+#             */
/*   Updated: 2022/03/02 12:27:41 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>
#include <env/env.h>

/**
 * @brief Try access() the cmd through each path in environment, return the
 * sucessfull one with the name of the executable
 *
 * @param cmd: The name of the command
 * @param syspath: The path environment variable
 * @return the command/executable fullname
 */
static char	*choose_path(const char *cmd, char *syspath)
{
	char	**spl_path;
	char	*test_p;
	size_t	path_i;

	if (access(cmd, F_OK) == 0)
		return ((char *)cmd);
	spl_path = ft_split(syspath, ':');
	path_i = 0;
	while (spl_path[path_i] != NULL)
	{
		ft_asprintf(&test_p, "%s/%s", spl_path[path_i], cmd);
		if (access(test_p, F_OK) >= 0)
			return (test_p);
		safe_free((void **)&test_p);
		++path_i;
	}
	return (NULL);
}

/**
 * @brief After a fork() the program acknowledge it is running in subprocess 
 * (which will became the new process) and enter this function to execve() the
 * desired command.
 *
 * @param tokens: The tokens obtained from user input
 * @param sh: The shell
 * @return the exit code from the new process
 */
static int	sub_process(t_command *command)
{
	char	*full_name;
	char	**argv;
	char	**envp;

	full_name = choose_path(command->cmd, get_env("PATH")->value);
	if (!full_name)
		exit(0);
	// envp = gen_envp(g_sh->env);
	// if (!argv || !envp)
	// 	exit(0);
	argv = (char **)command->args;
	execve(full_name, argv, __environ);
	safe_free((void **)&argv);
	safe_free((void **)&envp);
	exit (1);
}

/**
 * @brief Execute a external command
 * 
 * @param command: Structure with the command and its arguments
 */
void	exec_extcmd(t_command *command)
{
	int		wstatus;
	pid_t   new_pid;

	new_pid = fork();
	if (!new_pid)
		sub_process(command);
	else
		wait(&wstatus);
}
