/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlesein <mlesein@student.42quebec.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:29:56 by mlesein           #+#    #+#             */
/*   Updated: 2023/11/213 19:29:59 by mlesein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_numbers(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	if (n == 0)
		i++;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	write_ptr(char *ptr, int n, int len)
{
	int	i;

	i = len - 1;
	if (n == 0)
	{
		ptr[0] = '0';
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		ptr[0] = '-';
	}
	while (n > 0)
	{
		ptr[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = count_numbers(n);
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (0);
	write_ptr(ptr, n, len);
	ptr[len] = '\0';
	return (ptr);
}

// int	main(void)
// {
// 	char	*result;

// 	result = ft_itoa(INT_MIN);
// 	printf("voici le chiffre: %s \n", result);
// 	printf("%d %d", INT_MIN, INT_MAX);
// 	return (0);
// }
