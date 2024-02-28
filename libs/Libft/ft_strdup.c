/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlesein <mlesein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 19:37:16 by mlesein           #+#    #+#             */
/*   Updated: 2023/11/29 17:23:56 by mlesein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*string;
	int		i;
	int		x;

	i = 0;
	x = 0;
	if (src == NULL)
		return (0);
	while (src[i] != '\0')
		i++;
	string = malloc(sizeof(char) * (i + 1));
	if (string == NULL)
		return (0);
	while (src[x] != '\0')
	{
		string[x] = src[x];
		x++;
	}
	string[x] = '\0';
	return (string);
}

// int	main(void)
// {
// 	char	str[] = "ceci est une string";
// 	printf("%s", ft_strdup(str));
//	return (0);
// }
