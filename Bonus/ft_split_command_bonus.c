/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_command_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:16:00 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/05/25 15:34:53 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ffree(char **array, size_t i)
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

char	*split_between_quotes(const char *s, int *i, char c, int *flag)
{
	int		len;
	char	*res;

	res = NULL;
	len = word_len(s + (*i), c, flag);
	if (*flag != 1)
		res = ft_substr(s, (*i) + 1, len - 2);
	(*i) += len + 1;
	return (res);
}

char	*normal_split(const char *s, int *i, char c, int *flag)
{
	int		len;
	char	*res;

	res = NULL;
	len = word_len(s + (*i), c, flag);
	res = ft_substr(s, *i, len);
	(*i) += len;
	return (res);
}

char	**split(char **res, const char *s, char c, int words)
{
	int		i;
	int		j;
	int		flag;

	i = 0;
	j = 0;
	while (j < words)
	{
		while (s[i] == c)
			i++;
		flag = 0;
		if (is_quote(s[i]))
			res[j] = split_between_quotes(s, &i, c, &flag);
		else
			res[j] = normal_split(s, &i, c, &flag);
		if (flag != 1)
		{
			if (!res[j] && flag != 1)
				return (ffree(res, j), NULL);
			j++;
		}
	}
	res[j] = NULL;
	return (res);
}

char	**ft_split_command(char *s, char c)
{
	char	**res;
	int		words;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	res = (char **)malloc((words + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	res = split(res, s, c, words);
	return (res);
}
