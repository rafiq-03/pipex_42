/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handel_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:36:20 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/05/16 17:20:57 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	is_quote(char c)
{
	if (c && c == 39)
		return (1);
	else if (c && c == 34)
		return (2);
	return (0);
}

void	count_in_quote(const char *s, int *count, int *i)
{
	(*i)++;
	while (s[*i] && !is_quote(s[*i]))
		(*i)++;
	if (is_quote(s[*i]))
		(*i)++;
	(*count)++;
}

int	quote_number(const char *s)
{
	int	i;
	int	q;

	i = 0;
	q = 0;
	while (s[i])
	{
		if (s[i] == 39 || s[i] == 34)
			q++;
		i++;
	}
	return (q);
}
