/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handel_quote_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:36:20 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/05/17 22:56:39 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

char	*between_q(const char *s, int *i, char c)
{
	char	*str;

	str = ft_substr(s, (*i) + 1, word_len(s + (*i), c) - 1);
	(*i)++;
	while (s[*i] && !is_quote(s[*i]))
		(*i)++;
	if (s[*i])
		(*i)++;
	return (str);
}

void	skip_sapces(const char *s, int *i, char c)
{
	while (s[*i] && s[*i] == c)
		(*i)++;
}
