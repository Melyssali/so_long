/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlesein <mlesein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:33:25 by mlesein           #+#    #+#             */
/*   Updated: 2023/11/27 18:18:14 by mlesein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_uc;

	i = 0;
	s_uc = (unsigned char *)s;
	if (s == NULL)
		return (0);
	while (i < n)
	{
		if (s_uc[i] == (unsigned char)c)
		{
			return ((void *)(s_uc + i));
		}
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char strr[] = "";
// 	char *dest = ft_memchr(strr, 'i', 2);
// 	printf("mienne, trouve a la position : %s %ld \n", dest, dest - strr);
// 	printf("vraie fonction : %s \n", strrchr(strr, 'i'));
// 	return (0);
// }