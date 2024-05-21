/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_command_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:16:00 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/05/17 22:56:01 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	_count_words(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (quote_number(s) % 2 != 0)
		return (-1);
	while (s[i])
	{
		while (s[i] == c)
		{
			i++;
			if (s[i] == '\0')
				return (count);
		}
		if (s[i] && is_quote(s[i]))
			count_in_quote(s, &count, &i);
		else
		{
			while (s[i] && s[i] != c)
				i++;
			count++;
		}
	}
	return (count);
}

static void	free_res(char **array, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		free(array[j]);
		j++;
	}
	free(array);
}

size_t	word_len(const char *s, char c)
{
	size_t	i;

	i = 0;
	if (is_quote(s[i]))
	{
		i++;
		while (!is_quote(s[i]))
			i++;
	}
	else
	{
		while (s[i] && s[i] != c)
			i++;
	}
	return (i);
}

static char	**ft_result1(char **res, const char *s, char c, size_t words)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	while (j < words)
	{
		skip_sapces(s, &i, c);
		if (s[i] && is_quote(s[i]))
			res[j] = between_q(s, &i, c);
		else
		{
			res[j] = ft_substr(s, i, word_len((s + i), c));
			while (s[i] && s[i] != c)
				i++;
		}
		if (!res[j])
		{
			free_res(res, j);
			return (NULL);
		}
		j++;
	}
	res[j] = NULL;
	return (res);
}

char	**ft_split_command(const char *s, char c)
{
	char	**res;
	int		words;

	if (!s)
		return (NULL);
	words = _count_words(s, c);
	if (words == -1)
	{
		res = malloc(2 * sizeof(char *));
		res[0] = ft_strdup(s);
		res[1] = NULL;
		return (res);
	}
	res = (char **)malloc((words + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	res = ft_result1(res, s, c, words);
	return (res);
}
