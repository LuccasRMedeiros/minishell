/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 22:05:03 by lrocigno          #+#    #+#             */
/*   Updated: 2022/03/02 12:07:11 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*get_env_value(const char *name, t_shell *sh)
{
	t_env	*env;
	size_t	name_s;

	env = sh->env;
	name_s = ft_strlen(name);
	if (!name)
		return (NULL);
	while (env)
	{
		if (name_s && !ft_strncmp(env->name, name, name_s))
			return (env->value);
		env = env->next;
	}
	return (NULL);
}

/**
 * @brief Count how many strings will be in the argv array (aka argc).
 * 
 * @param tokens: The tokens generated after user input 
 * @return the amount of arguments
 */
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
	argv = malloc(sizeof (char *) * (argc + 1));
	if (!argv)
		return (NULL);
	i = 0;
	while (tokens)
	{
		argv[i] = (char *)tokens->value;
		tokens = tokens->next;
		++i;
	}
	argv[i] = NULL;
	return (argv);
}

/**
 * @brief Calculate the total size of the environ array before the creation of
 * such object
 * 
 * @param env: the environ linked list 
 * @return the size of the array
 */
static size_t	env_size(t_env *env)
{
	size_t	size;
	
	size = 0;
	while (env)
	{
		++size;
		env = env->next;
	}
	return (size);
}

char	**gen_envp(t_env *env)
{
	size_t	envp_sz;
	char	**envp;
	size_t	i;

	envp_sz = env_size(env);
	envp = malloc(sizeof (char *) * (envp_sz + 1));
	if (!envp)
		return (NULL);
	i = 0;
	while (env)
	{
		envp[i] = env->value;
		env = env->next;
		++i;
	}
	envp[i] = NULL;
	return (envp);
}
