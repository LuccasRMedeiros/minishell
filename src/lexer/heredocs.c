/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredocs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.o...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:54:28 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/03/17 19:34:42 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <lexer/lexer.h>
#include <readline/readline.h>
#include <unistd.h>

static const char	*get_delimiter(t_token *token, char *input, size_t *offset)
{
	if (token == NULL)
		return (NULL);
	while (is_space(input[*offset]) != 0)
		*offset += 1;
	return (word(input, offset));
}

static const char	*build_heredoc(const char *heredoc, char *input)
{
	const char	*temp;

	temp = ft_strjoin(heredoc, input);
	safe_free((void **)&heredoc);
	heredoc = ft_strjoin(temp, "\n");
	safe_free((void **)&temp);
	return (heredoc);
}

static t_token	*prompt_heredoc(t_token *token, const char *delimiter)
{
	char		*input;
	const char	*heredoc;

	input = NULL;
	heredoc = ft_strdup("");
	while (1)
	{
		safe_free((void **)&input);
		input = readline("here-doc: ");
		if (input == NULL || (ft_strcmp(input, delimiter) == 0))
			break ;
		heredoc = build_heredoc(heredoc, input);
	}
	safe_free((void **)&input);
	if (heredoc == NULL)
		return (NULL);
	token = new_token(T_WORD, token);
	token->value = heredoc;
	return (token);
}

t_token	*heredocs(t_token *token, char *input, size_t *offset)
{
	const char		*delimiter;

	if ((token->type == T_WORD) || (ft_strcmp(token->value, "<<") != 0))
		return (token);
	delimiter = get_delimiter(token, input, offset);
	if (delimiter == NULL)
		return (NULL);
	token = prompt_heredoc(token, delimiter);
	safe_free((void **)&delimiter);
	return (token);
}
