/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredocs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.o...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:54:28 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/03/18 08:25:10 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <readline/readline.h>
#include <unistd.h>

static uint8_t  is_unquoted(const char *delimiter)
{
	size_t len;

	if (delimiter[0] != '"' && delimiter[0] != '\'')
		return (1);
	len = ft_strlen(delimiter);
	if (len > 1 && (delimiter[len - 1] == delimiter[0]))
		return (0);
	return (1);
}

static uint8_t	is_delimiter(char *input, const char *delimiter)
{
	size_t	input_len;
	size_t	delimiter_len;

	if (is_unquoted(delimiter) == 0)
	{
		input_len = ft_strlen(input);
		delimiter_len = ft_strlen(delimiter) - 2;
		return ((input_len == delimiter_len)
				&& (ft_strncmp(input, delimiter + 1, delimiter_len) == 0));
	}
	return ((ft_strcmp(input, delimiter) == 0));
}

static const char	*build_heredoc(const char *heredoc, char *input)
{
	const char	*temp;

	if (heredoc == NULL)
		return (NULL);
	temp = ft_strjoin(heredoc, input);
	safe_free((void **)&heredoc);
	heredoc = ft_strjoin(temp, "\n");
	safe_free((void **)&temp);
	return (heredoc);
}

static t_token	*prompt_heredoc(t_token *token, const char *delimiter)
{
	char		*input;
	char		*quote;
	const char	*heredoc;

	input = NULL;
	quote = "'";
	if ((is_unquoted(delimiter) != 0))
		quote = "\"";
	heredoc = ft_strdup(quote);
	while (1)
	{
		safe_free((void **)&input);
		input = readline("here-doc: ");
		if (input == NULL || (is_delimiter(input, delimiter) != 0))
			break ;
		heredoc = build_heredoc(heredoc, input);
	}
	safe_free((void **)&input);
	token = new_token(T_WORD, token);
	token->value = ft_strjoin(heredoc, quote);
	safe_free((void **)&heredoc);
	if (token->value == NULL)
		return (NULL);
	return (token);
}

t_token	*heredocs(t_token *token, char *input, size_t *offset)
{
	const char		*delimiter;

	if ((token->type == T_WORD) || (ft_strcmp(token->value, "<<") != 0))
		return (token);
	while (is_space(input[*offset]) != 0)
		*offset += 1;
	if (input[*offset] == '\0')
		return (NULL);
	delimiter = word(input, offset);
	if (delimiter == NULL)
		return (NULL);
	token = prompt_heredoc(token, delimiter);
	safe_free((void **)&delimiter);
	return (token);
}
