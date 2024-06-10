/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:36:20 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/05/25 15:26:12 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	is_quote(char c)
{
	if (c == 39)
		return (1);
	else if (c == 34)
		return (2);
	return (0);
}

void	count_in_quote(char *str, int *i, char c, int *count)
{
	int	flag;
	int	j;
	int	q;

	flag = 0;
	j = *i;
	q = is_quote(str[j]);
	j++;
	while (str[j] && q != is_quote(str[j]))
	{
		if (str[j] != c)
			flag = 1;
		j++;
	}
	if (flag && is_quote(str[j]) == q)
		(*count)++;
	(*i) = j + 1;
}

int	ft_count_words(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
		{
			i++;
			if (s[i] == '\0')
				return (count);
		}
		if (is_quote(s[i]))
			count_in_quote(s, &i, c, &count);
		else
		{
			while (s[i] && s[i] != c)
				i++;
			count++;
		}
	}
	return (count);
}

int	len_between_quotes(char *s, int i, int *flag, int q)
{
	if (q == is_quote(s[i]))
	{
		*flag = 1;
		return (i);
	}
	if (s[i] == ' ')
	{
		i++;
		while (s[i] && s[i] == ' ')
			i++;
		if (s[i] && q == is_quote(s[i]))
		{
			*flag = 1;
			return (i);
		}
	}
	while (s[i] && q != is_quote(s[i]))
		i++;
	return (i);
}

int	word_len(const char *s, char c, int *flag)
{
	int	i;
	int	q;

	i = 0;
	q = is_quote(s[i++]);
	if (q)
		i += len_between_quotes((char *)s, i, flag, q);
	else
	{
		while (s[i] && s[i] != c)
			i++;
	}
	return (i);
}
