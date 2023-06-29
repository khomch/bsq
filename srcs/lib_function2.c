/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_function2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhomche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:43:16 by akhomche          #+#    #+#             */
/*   Updated: 2023/06/28 13:43:45 by akhomche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions_lib.h"

void	print_matrix(int **matrix, int rows, int cols)
{
	int	x;
	int	y;

	y = 0;
	while (y < rows)
	{
		x = 0;
		while (x < cols)
		{
			ft_putchar((matrix[y][x] + 48));
			ft_putchar(' ');
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}

void	print_char_matrix(char **matrix, int rows, int cols)
{
	int	x;
	int	y;

	y = 0;
	while (y < rows)
	{
		x = 0;
		while (x < cols)
		{
			ft_putchar((matrix[y][x]));
			x++;
		}
		y++;
		ft_putchar('\n');
	}
}

int	ft_strlen_mod(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (i > 16)
			return (0);
		i++;
		if (str[i] == '\n')
			return (i + 1);
	}
	return (i);
}

void	ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (*(src + i))
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = src[i];
}

void	ft_strconcat(char *dest, char *src, int *size, int buff_size)
{
	int		i;
	int		c;

	i = 0;
	if ((*size) > buff_size && (*size) % buff_size == 0)
	{
		if (dest[*size - buff_size])
			i = *size - buff_size;
	}
	c = 0;
	while (dest[i])
		i++;
	while (src[c] && c < buff_size)
	{
		dest[i] = src[c];
		i++;
		c++;
	}
	while (c >= 0)
	{
		src[c] = '\0';
		c--;
	}
	dest[i] = '\0';
}
