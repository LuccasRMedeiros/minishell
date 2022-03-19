/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 10:51:05 by lrocigno          #+#    #+#             */
/*   Updated: 2022/03/19 10:57:03 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtin/builtin.h>

/**
 * @brief Print text in stdout
 *
 * @param output: The text to be outputed
 */
void	echo(char *output, const char *opt)
{
	if (ft_strncmp(opt, "-n") == 0)
		printf (output);
	printf("%s\n", output);
}
