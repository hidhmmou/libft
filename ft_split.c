/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 16:01:30 by hidhmmou          #+#    #+#             */
/*   Updated: 2022/10/09 20:16:43 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**m_error(char	**arr)
{
	unsigned int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	return (NULL);
}

int	ft_count_words(char const *str, char charset)
{
	int	i;
	int	nbr_w;

	nbr_w = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == charset))
			i++;
		if (str[i])
			nbr_w++;
		while (str[i] && !(str[i] == charset))
			i++;
	}
	return (nbr_w);
}

int	ft_word_len(char const *str, char charset)
{
	int	i;

	i = 0;
	while (str[i] && !(str[i] == charset))
		i++;
	return (i);
}

char	*ft_word_grep(char const *str, char charset)
{
	int		len_w;
	int		i;
	char	*word;

	i = 0;
	len_w = ft_word_len(str, charset);
	word = malloc(sizeof(char) * (len_w + 1));
	if (!word)
		return (NULL);
	while (i < len_w)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = 0;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int			i;
	char		**splited;

	if (!s)
		return (NULL);
	i = 0;
	splited = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!splited)
		return (NULL);
	while (*s)
	{
		while (*s && (*s == c))
			s++;
		if (*s)
		{
			splited[i] = ft_word_grep(s, c);
			if (!splited[i])
				return (m_error(splited));
			i++;
		}
		while (*s && !(*s == c))
			s++;
	}
	splited[i] = 0;
	return (splited);
}
