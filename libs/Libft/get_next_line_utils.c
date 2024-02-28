/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlesein <mlesein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:40:28 by mlesein           #+#    #+#             */
/*   Updated: 2024/02/28 15:38:18 by mlesein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	char	c_char;
	int		i;

	i = 0;
	c_char = (char)c;
	if (!s)
		return (0);
	while (s[i])
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

char	*ft_strjoin_gnl(char const *s1, char const *s2, int bytes_read)
{
	size_t	i;
	size_t	j;
	char	*new_string;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	new_string = malloc(sizeof(char) * ((ft_strlen_gnl(s1)
					+ ft_strlen_gnl(s2)) + 1));
	if (!new_string)
		return (0);
	new_string[0] = '\0';
	while (s1[i])
	{
		new_string[i] = s1[i];
		i++;
	}
	while (s2[j] && j < (size_t)bytes_read)
		new_string[i++] = s2[j++];
	new_string[i] = '\0';
	return (new_string);
}

size_t	ft_strlcpy_gnl(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen_gnl(src);
	if (dest == NULL || src == NULL)
		return (0);
	if (dstsize == 0)
		return (src_len);
	while (src[i] && i < dstsize)
	{
		dest[i] = src[i];
		i++;
	}
	if (dstsize != 0)
		dest[i] = '\0';
	return (src_len);
}
