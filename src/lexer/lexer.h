/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 22:44:27 by lrocigno          #+#    #+#             */
/*   Updated: 2022/02/19 23:15:59 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include <libft.h>

typedef enum e_type
{
	BUILTIN,
	COMMAND,
	PARAMETER,
	STRING_LITERAL,
}	t_type;

typedef struct s_token
{
	char			*value;
	struct s_token	*next;
}	t_token;

/**
 * t_token constructor
 * @param type: which type this token is, value: the value for the token
 */

t_token	*new_token(const char *value);

/**
 * t_token destructor
 * @param del: the t_token object to be destroied
 */

void	del_token(t_token *del);

/**
 * Clear a list of tokens.
 * @param del_list: the list of tokens
 */

void	clear_token_list(t_token *del_list);

/**
 * Extract the value using the type as reference
 * @param type: which type the token is, input: the user input
 */

char	*get_value(char **input);

/**
 * Tokenizes the input sent by the user.
 * @param input: the user input
 */

t_token	*tokenizer(char *input);

/**
 * Discard all the tokens.
 * @param tokens: the array of tokens generated from tokenizer
 */

void	discard_tokens(t_token **tokens);

#endif
