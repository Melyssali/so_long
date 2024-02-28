/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                       	:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlesein <mlesein@student.42quebec.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:29:56 by mlesein           #+#    #+#             */
/*   Updated: 2023/11/213 19:29:59 by mlesein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	how_many_c(const char *s, char c)
{
	int	num;
	int	i;

	i = 0;
	num = 0;
	while (s[i] != '\0')
	{
		if ((s[i] == c || i == 0) && s[i + 1] != c && s[i + 1] != '\0')
			num++;
		i++;
	}
	return (num);
}

static void	free_split(char **arr)
{
	int	j;

	j = 0;
	while (arr[j] != NULL)
	{
		free(arr[j]);
		j++;
	}
	free(arr);
}

static char	**fill_arr(char **arr, char const *s, char c)
{
	int	i;
	int	j;
	int	start_string;

	i = 0;
	j = 0;
	while (j < how_many_c(s, c))
	{
		while (s[i] == c)
			i++;
		start_string = i;
		while (s[i] && s[i] != c)
			i++;
		arr[j] = malloc(i - start_string + 1);
		if (arr[j] == NULL)
		{
			free_split(arr);
			return (0);
		}
		ft_strlcpy(arr[j], s + start_string, i - start_string + 1);
		arr[j][i - start_string] = '\0';
		j++;
	}
	arr[j] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	if (!s)
		return (0);
	arr = NULL;
	arr = malloc(sizeof(char *) * (how_many_c(s, c) + 1));
	if (arr == NULL)
		return (0);
	return (fill_arr(arr, s, c));
}

// int main(void)
// {
// 	char **result;
//     char *test_string = "Bonjour le monde";
//     char delimiter = 'o';

//     result = ft_split(test_string, delimiter);

//     Afficher les résultats
//     if (result != NULL) {
//         int i = 0;
//         while (result[i] != NULL) {
//             printf("Segment %d: %s\n", i, result[i]);
//             i++;
//         }
//     }
//     return 0;
// }