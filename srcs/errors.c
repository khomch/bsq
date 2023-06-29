/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_rows.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoore <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:03:05 by samoore           #+#    #+#             */
/*   Updated: 2023/06/28 11:32:03 by samoore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions_lib.h"

int	empty_space(struct s_Legend legend, char *temp)
{
	int	x;
	int	y;
	int	c;

	x = 0;
	y = 0;
	c = 0;
	while (y < legend.rows)
	{
		while (x < legend.cols)
		{
			if (temp[c] == legend.empty)
				return (0);
			x++;
			c++;
		}
		x = 0;
		y++;
	}
	return (1);
}

int	map_chars(struct s_Legend legend, char *temp)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (!temp)
		return (0);
	while (y < legend.rows)
	{
		while (x < legend.cols)
		{
			if (legend.map[x][y] != legend.empty
				&& legend.map[x][y] != legend.full)
			{
				return (2);
			}
			x++;
		}
		x = 0;
		y++;
	}
	if (legend.empty < 32 || legend.full < 32 || legend.obstacle < 32)
		return (3);
	return (0);
}

int	lines_and_rows(struct s_Legend legend, char *temp)
{
	int	x;
	int	y;
	int	c;

	x = 0;
	y = 0;
	c = legend.head_size + 1;
	while (y < legend.rows)
	{
		while (x < legend.cols)
		{
			x++;
			c++;
		}
		if (temp[c] != '\n')
		{
			return (4);
		}
		x = 0;
		y++;
	}
	if (y < legend.rows)
		return (4);
	return (0);
}

int	check_header(struct s_Legend legend, char *temp)
{
	int	x;

	x = 0;
	while (x < legend.head_size - 3)
	{
		if (temp[x] < '0' || temp[x] > '9')
			return (5);
	}
	return (0);
}

int	valid_map(struct s_Legend legend, char *temp)
{
	int	error;

	error = 0;
	error = lines_and_rows(legend, temp);
	if (error > 0)
		error = map_chars(legend, temp);
	if (error > 0)
		error = legend.head_size < 4;
	if (legend.empty == legend.full || legend.empty == legend.obstacle)
		error = 7;
	if (legend.full == legend.obstacle || legend.rows < 1)
		error = 8;
	return (error);
}
