/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 22:44:27 by lrocigno          #+#    #+#             */
/*   Updated: 2022/03/18 08:47:38 by vgoncalv         ###   ########.fr       */
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

/**
 * @brief Creates a new token
 *
 * @see: struct s_token
 * @param type: the type of the created token
 * @param prev: the previous token in the list
 * @return: the new token
 */
t_token			*new_token(t_token_type type, t_token *prev);

/**
 * @brief: Clears the tokens list
 *
 * @param token: the head of the token list
 * @return: always returns NULL
 */
t_token			*clear_tokens(t_token *token);

/**
 * @brief Define the token type
 *
 * @param input: The user input
 * @return the token type
 */
t_token_type	token_type(char *input);

/**
 * @brief: Evaluates if character is space, tab or new line
 *
 * @param c: the evaluated character
 * @return: a non-zero value if it is a space, tab or new line
 */
uint8_t			is_space(char c);

/**
 * @brief: Evaluates if character is operator
 *
 * @param c: the evaluated character
 * @return: a non-zero value if it is a operator
 */
uint8_t			is_operator(char c);

/**
 * @brief: Evaluates if character is metacharacter
 *
 * @param c: the evaluated character
 * @return: a non-zero value if it is a metacharacter
 */
uint8_t			is_metachar(char c);

/**
 * @brief: Gets word from current input and updates the offset
 *
 * @param input
 * @param offset
 * @return: the word value
 */
char			*word(char *input, size_t *offset);

/**
 * @brief: Gets operator from current input and updates the offset
 *
 * @param input
 * @param offset
 * @return: the operator value
 */
char			*operator(char *input, size_t *offset);

/**
 * @brief: Tokenizes the input into WORDs and OPERATORS
 *
 * @param input
 * @return: the tokens list
 */
t_token			*tokenize(char *input);

/**
 * @brief: Handles unfinished here-docs
 *
 * @param token
 * @param input
 * @param offset
 * @return: the tokens list
 */
t_token			*heredocs(t_token *token, char *input, size_t *offset);

#endif
