/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 22:44:27 by lrocigno          #+#    #+#             */
/*   Updated: 2022/02/28 10:54:23 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include <libft.h>

/**
 * @brief Lists the possible types for tokens.
 */
typedef enum e_type
{
	BUILTIN,
	EXTERNAL,
	PARAMETER,
	PIPE,
	REDIRECT,
	FILE_R,
}	t_type;

/**
 * @brief Linked list that hold the value and the type of a token, also refers
 * to the next token.
 */
typedef struct s_token
{
	const char		*value;
	t_type			type;
	struct s_token	*next;
}	t_token;

/**
 * @brief t_token constructor
 *
 * @param type: Which type this token is.
 * @param value: The value for the token.
 */
t_token	*new_token(const char *value, const t_type type);

/**
 * @brief Clear a list of tokens.
 *
 * @param del_list: The list of tokens.
 */
void	clear_token_list(t_token *del_list);

/**
 * @brief Extract the value using the type as reference.
 *
 * @param type: Which type the token is, input: the user input.
 * @return a string with the value extracted from "input"
 */
char	*get_value(char **input);

/**
 * @brief Tokenizes the input sent by the user.
 *
 * @param input: The user input.
 * @return the list of tokens.
 */
t_token	*tokenizer(char *input);

/**
 * @brief Decide which type the tokens is based on its order and content.
 *
 * @param order: The order this token is on the list.
 * @param value: The value of the token.
 * @return the type of the token.
 */
t_type	get_type(const int order, const char *value);

#endif
