/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlesein <mlesein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:23:15 by mlesein           #+#    #+#             */
/*   Updated: 2023/11/29 17:24:00 by mlesein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	c_char;
	int		i;

	i = 0;
	c_char = (char)c;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == c_char)
			return ((char *)&s[i]);
		i++;
	}
	if (c_char == '\0')
	{
		if (s[i] == c_char)
			return ((char *)&s[i]);
	}
	return (0);
}

// int	main(void)
// {
// 	char string[] = "Moi j'aime le code";
// 	char *resultat = ft_strchr(string, '\0');
// 	char *resultat2 = strchr(string, '\0');
// 	ft_strchr(string, 'i');
// 	printf("mienne, trouve a la position : %ld\n", resultat - string );
// 	printf("vraie fonction : %ld\n", resultat2 - string);
// 	return (0);
// }
