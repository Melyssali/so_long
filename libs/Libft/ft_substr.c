/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlesein <mlesein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:29:56 by mlesein           #+#    #+#             */
/*   Updated: 2023/11/29 17:21:48 by mlesein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*empty_string(void)
{
	char	*new_string;

	new_string = malloc(1);
	if (new_string == NULL)
		return (0);
	new_string[0] = '\0';
	return (new_string);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*new_string;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		return (empty_string());
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	new_string = malloc(sizeof(char) * (len + 1));
	if (new_string == NULL)
		return (0);
	new_string[0] = '\0';
	while (s[start] != '\0' && i < len)
	{
		new_string[i] = s[start];
		i++;
		start++;
	}
	new_string[i] = '\0';
	return (new_string);
}

// int	main(void)
// {
// 	char			str[33] = "ceci est une phrase qu'on écrit";
// 	unsigned int	start_int = 8;
// 	char *result = ft_substr(str, start_int, 10);
// 	printf("%s \n", result);
// 	return (0);
// }
