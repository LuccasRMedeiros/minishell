/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocigno <lrocigno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 15:44:50 by lrocigno          #+#    #+#             */
/*   Updated: 2022/02/05 16:29:49 by lrocigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERS_H
# define HELPERS_H

# include <libft.h>

/**
 * Return if c is a white space character.
 * @param c: the character being compared.
 */

int		is_space(char c);

/**
 * Return if c is a quote character.
 * @param c: the character being compared.
 */

int		is_quote(char inchar);

/**
 * Return if c is a loop stop character.
 * @param c: the character being compared.
 */

int		is_stop(char *input, int *close_q, int cq_sig);

/**
 * Get the setted quote.
 */

char	get_quote(void);

/**
 * See if a quote is closed, then set the character q as the quote.
 * @param q: the quote to be set.
 */

void	set_quote(char *input);

/**
 * Clear the quote;
 */

void	clear_quote(void);

#endif
