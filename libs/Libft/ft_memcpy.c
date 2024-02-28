/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlesein <mlesein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:22:47 by mlesein           #+#    #+#             */
/*   Updated: 2023/11/27 18:18:21 by mlesein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (src == NULL || dst == NULL)
		return (dst);
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}

// int	main(void)
// {
// char	source[20] = "ceci est une string";
// char	destination[20] = "test";

// printf("la vraie fonction : %s \n", memcpy(((void *)0), "test", 17));
// printf("ma fonction : %s \n", ft_memcpy(((void *)0), "test", 17));
// return (0);
// }