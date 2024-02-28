/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlesein <mlesein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:29:56 by mlesein           #+#    #+#             */
/*   Updated: 2024/02/13 12:48:48 by mlesein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_libft(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*new_string;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	new_string = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (new_string == NULL)
		return (0);
	new_string[0] = '\0';
	while (s1[i])
	{
		new_string[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		new_string[i] = s2[j];
		i++;
		j++;
	}
	new_string[i] = '\0';
	return (new_string);
}

// int	main(void)
// {
// 	char	*str1 = "ceci est ";
// 	char	*str2 = "une phrase";
// 	char	*result = ft_strjoin(str1, str2);
// 	printf("%s", result);
// 	return (0);
// }