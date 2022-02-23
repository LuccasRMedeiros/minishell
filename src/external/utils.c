/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 22:05:03 by lrocigno          #+#    #+#             */
/*   Updated: 2022/02/22 23:02:38 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <external/external_cmd.h>

static int	cnt_argv(t_token *tokens)
{
	int	cnt;

	cnt = 0;
	while (tokens)
	{
		++cnt;
		tokens = tokens->next;
	}
	return (cnt);
}

char	**gen_argv(t_token *tokens)
{
	int		argc;
	char	**argv;
	size_t	i;

	argc = cnt_argv(tokens);
	argv = malloc(sizeof (char *) * argc);
	if (!argv)
		return (NULL);
	i = 0;
	while (tokens)
	{
		argv[i] = tokens->value;
		tokens = tokens->next;
		++i;
	}
	return (argv);
}

static size_t	env_size(t_shell *sh)
{
	size_t	size;
	t_env	*env

	size = 0;
	env = sh->env
	while (env)
	{
		++size;
		env = env->next;
	}
	return (size);
}

char	**gen_envp(t_shell *sh)
{
	size_t	envp_sz;
	char	**envp;
	t_env	*env;
	size_t	i;

	envp_sz = env_size(sh);
	envp = malloc(sizeof (char *) * envp_sz);
	if (!envp)
		return (NULL);
	env = sh->env;
	i = 0;
	while (env)
	{
		envp[i] = env->value;
		env = env->next;
		++i;
	}
	return (env);
}
