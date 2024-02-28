/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlesein <mlesein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:06:22 by mlesein           #+#    #+#             */
/*   Updated: 2023/11/27 18:16:49 by mlesein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (src == NULL || dst == NULL)
		return (0);
	if (dst == src)
		return (dst);
	else if (src > dst)
	{
		while (i < len)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i++;
		}
	}
	else if (src < dst)
	{
		while (len > 0)
		{
			((char *)dst)[len - 1] = ((char *)src)[len - 1];
			len--;
		}
	}
	return (dst);
}

// int	main(void)
// {
// 	char str[50] = "HelloWorld";
//     char *src = str + 2; // Commence à 'l'
//     char *dst = str;     // Destination au début

//     // Copie avec chevauchement où src > dst
//     ft_memmove(dst, src, 5); // 'lloWo' sera copié à 'Hello'
//     printf("Après memmove avec src > dst: %s\n", str);

//     // Réinitialiser la chaîne
//     strcpy(str, "HelloWorld");

//     // Copie sans chevauchement où src < dst
//     src = str;               // Source au début
//     dst = str + 2;           // Décalage pour la destination
//     ft_memmove(dst, src, 5); // 'Hello' sera copié à 'lloWo'
//     printf("Après memmove avec src < dst: %s\n", str);

//     return 0;
// }
