/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 22:44:27 by lrocigno          #+#    #+#             */
/*   Updated: 2022/03/16 00:40:36 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include <minishell.h>

typedef enum e_token_type
{
  T_WORD,
  T_OPERATOR,
  TOKEN_COUNT,
}	t_token_type;

typedef struct s_token
{
	t_token_type	type;
	const char		*value;
    struct s_token	*prev;
    struct s_token	*next;
}	t_token;

t_token	*new_token(t_token_type type, t_token *prev);
t_token	*clear_tokens(t_token *token);
uint8_t	is_space(char c);
uint8_t	is_operator(char *input);
uint8_t	is_metachar(char *input);
char	*word(char *input, size_t *offset);
char	*operator(char *input, size_t *offset);
t_token	*tokenize(char *input);

#endif
