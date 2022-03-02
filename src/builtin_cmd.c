/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:30:01 by lrocigno          #+#    #+#             */
/*   Updated: 2022/03/02 17:08:35 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	builtin_cmd(t_token *tks, t_shell *sh)
{
	if (ft_strncmp(tks->value, "cd", ft_strlen(tks->value)) == 0)
		cd((char *)tks->next->value);
	if (sh) {}
}
