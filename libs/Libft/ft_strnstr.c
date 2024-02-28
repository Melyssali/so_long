/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlesein <mlesein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:44:56 by mlesein           #+#    #+#             */
/*   Updated: 2023/11/28 16:03:05 by mlesein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (needle == NULL || haystack == NULL)
		return (0);
	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		while (needle[j] != '\0' && haystack[i + j] != '\0' && (i + j) < len
			&& haystack[i + j] == needle[j])
		{
			j++;
		}
		if (needle[j] == '\0')
		{
			return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}

// int main(void)
// {
// 	char botte[23] = "tu dois trouver ce mot";
// 	char aiguille[5] = "ce";
// 	char *resultat = ft_strnstr(botte, aiguille, 2);
// 	printf("ma fonction : %s\n", resultat);
// 	resultat = strnstr(botte, aiguille, 2);
// 	printf("la vraie fonction : %s\n", resultat);

// 	return (0);
// }
