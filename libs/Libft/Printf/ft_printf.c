/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlesein <mlesein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:42:22 by mlesein           #+#    #+#             */
/*   Updated: 2024/02/28 15:39:02 by mlesein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_format(const char format, va_list args)
{
	int	count;

	count = 0;
	if (format == 's')
		return (count += ft_putstr(va_arg(args, const char *), 1));
	else if (format == 'c')
		return (count += ft_putchar_p(va_arg(args, int), 1));
	else if (format == 'd' || format == 'i')
		return (count += ft_putnbr_p(va_arg(args, int), 1));
	else if (format == '%')
		return (count += ft_putchar_p('%', 1));
	else if (format == 'u')
		return (count += ft_putnbr_hexa(va_arg(args, unsigned int), 10, 'u'));
	else if (format == 'x')
		return (count += ft_putnbr_hexa(va_arg(args, unsigned int), 16, 'x'));
	else if (format == 'p')
	{
		count += write(1, "0x", 2);
		return (count += ft_putnbr_hexa(va_arg(args, unsigned long), 16, 'p'));
	}
	else if (format == 'X')
		return (count += ft_putnbr_hexa(va_arg(args, unsigned int), 16, 'X'));
	else
		return (count += write(1, &format, 1));
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, s);
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '%')
		{
			count += ft_check_format(s[i + 1], args);
			i++;
		}
		else
			count += write(1, &s[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}

// int	main(void)
// {
// 	ft_printf(NULL);
// 	int nbr = -3735;
// 	// int num = 0;
// 	char test[] = "";
// 	int ret1;
// 	int ret2;
// 	printf("----------test pour %%c----------\n");
// 	ret1 = printf("%c\n", '0');
// 	ret2 = ft_printf("%c\n", '0');
// 	printf("compteur de printf : %d\n", ret1);
// 	ft_printf("compteur de ft_printf : %d\n", ret2);
// 	printf("\n");
// 	printf("----------test pour %%s----------\n");
// 	ret1 = printf("%s\n", "une belle String");
// 	ret2 = ft_printf("%s\n", "une belle String");
// 	printf("compteur de printf : %d\n", ret1);
//   	ft_printf("compteur de ft_printf : %d\n", ret2);
// 	printf("\n");
// 	printf("----------test pour %%d----------\n");
// 	ret1 = printf("%d\n", 45);
// 	ret2 = ft_printf("%d\n", 45);
// 	printf("compteur de printf : %d\n", ret1);
// 	ft_printf("compteur de ft_printf : %d\n", ret2);
// 	printf("\n");
// 	printf("----------test pour %%i----------\n");
// 	ret1 = printf("%i\n", 9);
// 	ret2 = ft_printf("%i\n", 9);
// 	printf("compteur de printf : %i\n", ret1);
// 	ft_printf("compteur de ft_printf : %i\n", ret2);
// 	printf("\n");
// 	printf("----------test pour %%u----------\n");
// 	ret1 = printf("%u\n", UINT_MAX);
// 	ret2 = ft_printf("%u\n", UINT_MAX);
// 	printf("compteur de printf : %u\n", ret1);
// 	ft_printf("compteur de ft_printf : %u\n", ret2);
// 	printf("\n");
// 	printf("----------test pour %%p----------\n");
// 	ret1 = printf("%p %p\n", test, test);
// 	ret2 = ft_printf("%p %p\n", test, test);
// 	printf("compteur de printf : %d\n", ret1);
// 	ft_printf("compteur de ft_printf : %d\n", ret1);
// 	printf("\n");
// 	printf("----------test pour %%x----------\n");
// 	ret1 = printf("%x\n %x\n", 0, -42);
// 	ret2 = ft_printf("%x\n %x\n", 0, -42);
// 	printf("compteur de printf : %d\n", ret1);
// 	ft_printf("compteur de ft_printf : %d\n", ret2);
// 	printf("\n");
// 	printf("----------test pour %%X----------\n");
// 	ret1 = printf("%X\n", nbr);
// 	ret2 = ft_printf("%X\n", nbr);
// 	printf("compteur de printf : %d\n", ret1);
// 	ft_printf("compteur de ft_printf : %d\n", ret2);
// 	printf("\n");
// char s[] = "une phrase";
// int c = 'a';
// int num = 0;
// unsigned int unsign = -2;
// printf("vraie fonction : \n");
// printf("voici %s et un chiffre %d et un char :
// %c et un signe pourcentage
// %%, %u\n", s, num, c, unsign);
// printf("ma fonction : \n");
// ft_printf("voici %s et un chiffre %d et un char :
// %c et un signe pourcentage
// %%, %u", s, num, c, unsign);
// printf("\n");
// int	count;

// count = ft_printf("Hello %s\n", "John");
// ft_printf("%d chars\n", count);//, fflush(stdout);
// count = ft_printf("Char-> %c\n", 'a');
// ft_printf("%d chars\n", count);//, fflush(stdout);
// count = ft_printf("Nbr-> %d\n", -42);
// ft_printf("%d chars\n", count);//, fflush(stdout);
// count = ft_printf("Hex-> %u\n", -1);
// ft_printf("%d chars\n", count);//, fflush(stdout);
// count = ft_printf("Hex-> %x\n", 28);
// ft_printf("%d chars\n", count);//, fflush(stdout);
// count = ft_printf("Hex-> address %p\n", &count);
// ft_printf("%d chars\n", count);//, fflush(stdout);

// 	return (0);
// }