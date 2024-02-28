/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlesein <mlesein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:29:56 by mlesein           #+#    #+#             */
/*   Updated: 2023/11/29 17:23:25 by mlesein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*empty_string1(void)
{
	char	*new_string;

	new_string = malloc(1);
	if (new_string == NULL)
		return (0);
	new_string[0] = '\0';
	return (new_string);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int		start;
	int		end;
	char	*new_string;

	if (s1 == NULL || set == NULL)
		return (0);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[start]) && start <= end)
		start++;
	if (start > end)
		return (empty_string1());
	while (ft_strchr(set, s1[end]) && end >= start)
		end--;
	new_string = malloc(sizeof(char) * (end - start + 2));
	if (new_string == NULL)
		return (0);
	new_string[0] = '\0';
	ft_strlcpy(new_string, &s1[start], (end - start + 2));
	return (new_string);
}

// int	main(void)
// {
// 	char	*str1 = 	", :.:ceci est une string: /";
// 	char	*set_char = "./ ;,";
// 	char	*result = ft_strtrim(str1, set_char);
// 	char	*set_char = "./;,";
// printf("%s", result);
// 	convertir un char pointer to une valeur ascii
// 	return (0);
// }