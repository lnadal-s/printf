/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnadal-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 10:21:44 by lnadal-s          #+#    #+#             */
/*   Updated: 2019/11/26 17:13:13 by lnadal-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			count_w(const char *s, char c)
{
	int k;
	int count;

	k = 0;
	count = 0;
	while (s[k])
	{
		while (s[k] == c)
		{
			k++;
			if (!(s[k]))
				return (count);
		}
		count++;
		while (s[k] != c && s[k])
			k++;
	}
	return (count);
}

static char			*make_w(const char *s, char c, int *i)
{
	char		*word;
	size_t		size;
	int			k;

	size = 0;
	k = *i;
	while (s[*i] != c && s[*i])
	{
		(*i)++;
		size++;
	}
	if (!(word = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	size = 0;
	while (s[k] != c && s[k])
		word[size++] = s[k++];
	word[size] = 0;
	return (word);
}

char				**ft_split(char const *s, char c)
{
	int		j;
	int		k;
	char	**words;

	j = 0;
	k = 0;
	if (!s)
		return (NULL);
	if (!(words = (char **)malloc(sizeof(char *) * (count_w(s, c) + 1))))
		return (NULL);
	while (s[j])
	{
		if (s[j] && s[j] != c)
			words[k++] = make_w(s, c, &j);
		while (s[j] && s[j] == c)
			j++;
	}
	words[k] = 0;
	return (words);
}
