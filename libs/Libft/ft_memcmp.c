/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlesein <mlesein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:44:36 by mlesein           #+#    #+#             */
/*   Updated: 2023/11/29 17:56:53 by mlesein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			i;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (i < n && ptr1[i] == ptr2[i])
	{
		i++;
	}
	if (i == n)
		return (0);
	return ((int)ptr1[i] - (int)ptr2[i]);
}

// int	main(void)
// {
// 	char	str1[25] = "";
// 	char	str2[25] = "";
// 	size_t	size = 7;

// 	int result = ft_memcmp(str1, str2, size);
// 	int result2 = memcmp(str1, str2, size);

// 	printf("ma fonction donne : %d \n", result);
// 	printf("la vraie fonction donne : %d \n", result2);
// 	return (0);
// }
