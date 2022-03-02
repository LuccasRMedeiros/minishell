/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 12:25:02 by lrocigno          #+#    #+#             */
/*   Updated: 2022/03/02 17:22:16 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include <unistd.h>

/**
 * @brief Navigate to folder in path.
 *
 * @param path: The path to navigate to.
 * @return the result of chdir.
 */
int	cd(char *path);

#endif
