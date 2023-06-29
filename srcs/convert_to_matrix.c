/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_matrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhomche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 19:12:50 by akhomche          #+#    #+#             */
/*   Updated: 2023/06/27 19:12:55 by akhomche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions_lib.h"

void	convert_legend_to_matrix(struct s_Legend legend, int **matrix)
{
	int	y;
	int	x;

	y = 0;
	while (y < legend.rows)
	{
		x = 0;
		while (x < legend.cols)
		{
			if (legend.map[y][x] == legend.obstacle)
				matrix[y][x] = 0;
			if (legend.map[y][x] == legend.empty)
				matrix[y][x] = 1;
			x++;
		}
		y++;
	}
}

void	fill_map(struct s_Legend legend, struct s_Square square)
{
	int	y;
	int	x;
	int	size_x;
	int	size_y;

	y = square.y;
	size_y = square.size;
	while (size_y)
	{
		size_x = square.size;
		x = square.x;
		while (size_x)
		{
			legend.map[y][x] = legend.full;
			x--;
			size_x--;
		}
		size_y--;
		y--;
	}
}
