/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_biggest_square.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhomche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:24:57 by akhomche          #+#    #+#             */
/*   Updated: 2023/06/27 16:25:00 by akhomche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions_lib.h"
#include <stdio.h>

int	**copy_matrix(int **src, int rows, int cols)
{
	int	x;
	int	y;
	int	**matrix;

	y = 0;
	matrix = (int **)malloc(sizeof(int *) * rows);
	if (!matrix)
		return (NULL);
	while (y < rows)
	{
		x = 0;
		matrix[y] = (int *)malloc(sizeof(int) * cols);
		if (!matrix[y])
			return (NULL);
		while (x < cols)
		{
			matrix[y][x] = src[y][x];
			x++;
		}
		y++;
	}
	return (matrix);
}

void	process_cols(int **cache, int **matrix, int x, int y)
{
	if (y == 0 || x == 0)
	{
		cache[y][x] = matrix[y][x];
	}
	else if (matrix[y][x] > 0)
	{
		cache[y][x] = 1 + find_min(cache[y][x - 1],
				cache[y - 1][x], cache[y - 1][x - 1]);
	}
}

struct s_Square	process_matrix(int **cache, int	**matrix, int rows, int cols)
{
	struct s_Square	sq;
	int				y;
	int				x;

	sq.size = 0;
	y = 0;
	while (y < rows)
	{
		x = 0;
		while (x < cols)
		{
			process_cols(cache, matrix, x, y);
			if (cache[y][x] > sq.size)
			{
				sq.size = cache[y][x];
				sq.y = y;
				sq.x = x;
			}
			x++;
		}
		y++;
	}
	return (sq);
}

struct s_Square	find_biggest_square(int	**matrix, int rows, int cols)
{
	int				**cache;
	struct s_Square	square;

	cache = copy_matrix(matrix, rows, cols);
	square = process_matrix(cache, matrix, rows, cols);
	while (--rows)
		free(cache[rows]);
	free(cache[rows]);
	free(cache);
	return (square);
}
