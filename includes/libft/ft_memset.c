/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahbibe <bahbibe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:17:44 by bahbibe           #+#    #+#             */
/*   Updated: 2022/12/26 07:17:13 by bahbibe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char			*s;
	unsigned char	u;
	size_t			i;

	s = (char *) b;
	u = (unsigned char) c;
	i = 0;
	while (i < len)
	{
		s[i] = u ;
		i++;
	}
	return (b);
}
