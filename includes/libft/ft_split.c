/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahbibe <bahbibe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:01:24 by bahbibe           #+#    #+#             */
/*   Updated: 2022/12/26 07:17:01 by bahbibe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "libft.h"

static int	ft_word(char *str, char c)
{
	int	len;
	int	word;
	int	i;
	int	count;

	len = 0;
	word = 1;
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			word = 1;
		else
		{
			if (word == 1)
				count++;
			word = 0;
		}
		i++;
	}
	return (count);
}

static char	*ft_worddup(char *str, char c, int *index)
{
	char	*ptr;
	int		count;
	int		pos;
	int		i;

	count = 0;
	i = 0;
	while (str[*index] == c && str[*index])
		(*index)++;
	pos = *index;
	while (str[*index] != c && str[*index])
	{
		count++;
		(*index)++;
	}
	ptr = malloc(count + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, str + pos, count + 1);
	return (ptr);
}

static char	**ft_free(char **ptr, int i)
{
	while (i >= 0)
		free(ptr[i--]);
	free(ptr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		count;
	int		i;
	int		index;

	index = 0;
	i = 0;
	if (!s)
		return (NULL);
	count = ft_word((char *)s, c);
	ptr = malloc(sizeof(char *) * (count + 1));
	if (!ptr)
		return (NULL);
	while (i < count)
	{
		ptr[i] = ft_worddup((char *)s, c, &index);
		if (!ptr[i])
			return (ft_free(ptr, i));
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}
