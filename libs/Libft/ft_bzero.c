/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlesein <mlesein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:02:17 by mlesein           #+#    #+#             */
/*   Updated: 2023/11/27 18:17:20 by mlesein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return ;
	if (n == 0)
		return ;
	while (i < n)
	{
		((unsigned char *)s)[i] = 0;
		i++;
	}
}

// int	main(void)
// {
// 	int x;
// 	x = 0;
// 	char	string[50] = "ceci est un testtttttttt";
// 	while (string[x] != '\0')
// 		x++;
// 	ft_bzero(string, 7);
// 	for(int i = 0; i < x; i++)
// 	{
// 		if(string[i] == '\0')
// 			printf("\\0");
// 		else
// 			printf("%c", string[i]);
// 	}
// 	printf("\n");
// 	bzero(string, 7);
// 	for(int i = 0; i < x; i++)
// 	{
// 		if(string[i] == '\0')
// 			printf("\\0");
// 		else
// 			printf("%c", string[i]);
// 	}

// 	// for (size_t i = 0; i < size; i++)
// 	//     printf("ma fonction: %c", string[i]);
// 	// bzero(string, size);
// 	// for (int i = 0; i < size; i++)
// 	//     printf("ma fonction: %c", string[i]);

// 	return (0);

// }
