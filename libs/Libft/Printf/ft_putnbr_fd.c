/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlesein <mlesein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 20:19:54 by mlesein           #+#    #+#             */
/*   Updated: 2023/11/27 20:39:49 by mlesein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_p(int n, int fd)
{
	int		count;
	char	c;

	count = 0;
	if (n == 0)
	{
		return (count += write(fd, "0", 1));
	}
	if (n == -2147483648)
	{
		return (count += write(fd, "-2147483648", 11));
	}
	if (n < 0)
	{
		count += write(fd, "-", 1);
		n *= -1;
	}
	if (n >= 10)
		count += ft_putnbr_p(n / 10, fd);
	c = (n % 10) + '0';
	count += write(fd, &c, 1);
	return (count);
}

// int	main(void)
// {
// 	ft_putnr_fd(122, 1);
// 	return (0);
// }
