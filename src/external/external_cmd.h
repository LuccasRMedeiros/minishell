/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external_cmd.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 20:19:01 by lrocigno          #+#    #+#             */
/*   Updated: 2022/02/23 21:31:17 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTERNAL_CMD_H
# define EXTERNAL_CMD_H

# include <lexer/lexer.h>
# include <minishell.h>

void	exec_extcmd(t_token *tokens, t_shell *sh);

#endif
