/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 22:44:27 by lrocigno          #+#    #+#             */
/*   Updated: 2022/02/02 13:25:17 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include <libft.h>

typedef enum e_type
{
	INVALID = -1,
    BUILTIN,
	COMMAND,
    PARAMETER,
    STRING_LITERAL,
    INT_LITERAL,
	COMMENT,
}    t_type;

typedef struct s_token
{
    t_type        type;
    const char    *value;
}    t_token;

/**
 * Get the defined quote.
 * @param:
 */

char	get_quote(void);

/**
 * Set the quote.
 * @param q: the quote character
 */

void	set_quote(char q);

/**
 * t_token constructor
 * @param type: which type this token is, value: the value for the token
 */

t_token	*new_token(t_type type, const char *value);

/**
 * t_token destructor
 * @param del: the t_token object to be destroied
 */

void	del_token(t_token *del);

/**
 * Return if the character is a white space
 * @param c: the character being verified.
 */

int		lex_isspace(char c);

/**
 * Extract the value using the type as reference
 * @param type: which type the token is, input: the user input
 */

char	*get_value(t_type type, char *input);

/**
 * Return the type of token it is verifying
 * @param i: which token it is, input: the user input
 */

t_type	get_type(size_t i, char *input);

/**
 * Tokenizes the input sent by the user.
 * @param input: the user input
 */

t_token	**tokenizer(char *input);

/**
 * Discard all the tokens.
 * @param tokens: the array of tokens generated from tokenizer
 */

void	discard_tokens(t_token **tokens);

#endif
