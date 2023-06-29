/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhomche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:25:21 by akhomche          #+#    #+#             */
/*   Updated: 2023/06/27 16:28:42 by akhomche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions_lib.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

char	*ft_numtostr(int num)
{
	int		i;
	int		j;
	int		n[16];
	char	*res;

	i = 0;
	j = 0;
	while (num)
	{
		n[i++] = num % 10;
		num /= 10;
	}
	res = (char *)malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	while (--i >= 0)
	{
		res[j++] = n[i] + 48;
	}
	res[j] = '\0';
	return (res);
}

int	find_min(int a, int b, int c)
{
	int	min;

	min = 2147483647;
	if (b <= a && b <= c)
		min = b;
	if (a <= b && a <= c)
		min = a;
	if (c <= b && c <= a)
		min = c;
	return (min);
}

int	**create_matrix(int rows, int cols)
{
	int	y;
	int	**matrix;

	y = 0;
	matrix = (int **)malloc(sizeof(int *) * rows);
	if (!matrix)
		return (NULL);
	while (y < rows)
	{
		matrix[y] = (int *)malloc(sizeof(int) * (cols));
		if (!matrix[y])
			return (NULL);
		y++;
	}
	return (matrix);
}
