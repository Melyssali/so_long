/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlesein <mlesein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:17:31 by mlesein           #+#    #+#             */
/*   Updated: 2023/11/29 18:10:47 by mlesein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	c_char;

	c_char = (char)c;
	if (s == NULL)
		return (0);
	i = ft_strlen(s);
	if (c_char == '\0')
		return ((char *)&s[i]);
	while (i != 0)
	{
		i--;
		if ((s)[i] == c_char)
			return ((char *)&s[i]);
	}
	return (0);
}

// int	main(void)
// {
// 	char strr[] = "ceci est un signer eee";
// 	char *dest = ft_strrchr(strr, 'i');
// 	printf("mienne, trouve a la position : %s %ld \n", dest, dest - strr);
// 	printf("vraie fonction : %s \n", strrchr(strr, 'i'));
// 	return (0);
// }
