/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlesein <mlesein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:59:52 by mlesein           #+#    #+#             */
/*   Updated: 2023/11/29 17:23:43 by mlesein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (dest == NULL || src == NULL)
		return (0);
	if (dstsize == 0)
		return (src_len);
	while (src[i] && i < (dstsize - 1))
	{
		dest[i] = src[i];
		i++;
	}
	if (dstsize != 0)
		dest[i] = '\0';
	return (src_len);
}

// int main()
// {
// 	char source[7] = "copyme";
// 	char destination[21] = "i am the destination";
//	size_t destination_len = ft_strlen(destination) + 1;
// 	printf("%d \n", ft_strlcpy(destination, source, destination_len));
// 	return (0);
// }
