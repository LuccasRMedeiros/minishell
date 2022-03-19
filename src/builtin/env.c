/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 10:58:56 by lrocigno          #+#    #+#             */
/*   Updated: 2022/03/19 11:14:23 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtin/builtin.h>

void	env(void)
{
	t_env	*environ;

	environ = sh->env;
	while (environ)
	{
		printf("%s\n", environ->value);
		environ = environ->next;
	}
}
