/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhomche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:44:14 by akhomche          #+#    #+#             */
/*   Updated: 2023/06/28 13:44:16 by akhomche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions_lib.h"

int				valid_map(struct s_Legend legend, char *temp);

int	stl(char *temp)
{
	int	i;

	i = 0;
	while (temp[i] != '\n')
		i++;
	return (i);
}

char	**create_map(int rows, int cols, char *temp, int head_size)
{
	char	**map;
	int		x;
	int		y;
	int		k;

	map = (char **) malloc(sizeof(char *) * (rows + 1));
	if (!map)
		return (NULL);
	y = -1;
	k = head_size + 1;
	while (++y < rows)
	{
		x = -1;
		map[y] = (char *) malloc(sizeof(char ) * (cols + 1));
		if (!map[y])
			return (NULL);
		while (++x < cols)
		{
			if (temp[k] == '\n')
				k++;
			map[y][x] = temp[k];
			k++;
		}
	}
	return (map);
}

struct	s_Legend	fill_default(void)
{
	struct s_Legend	legend;

	legend.full = '\0';
	legend.obstacle = '\0';
	legend.empty = '\0';
	legend.rows = 0;
	legend.cols = 0;
	legend.map = NULL;
	return (legend);
}

int	find_cols(char *temp)
{
	int	x;
	int	c;

	x = 0;
	c = 1;
	while (temp[x] != '\n' && temp[x])
		x++;
	while (temp[x + c] != '\0' && temp[x + c] != '\n')
		c++;
	return (c);
}

struct	s_Legend	read_map(int size, int f)
{
	char			*temp;
	struct s_Legend	legend;

	legend = fill_default();
	temp = (char *) malloc(sizeof(char) * (size + 1));
	if (!temp)
		return (legend);
	read(f, temp, size);
	legend.head_size = stl(temp);
	legend.full = temp[legend.head_size - 1];
	legend.obstacle = temp[legend.head_size - 2];
	legend.empty = temp[legend.head_size - 3];
	legend.rows = num_rows(temp, legend.head_size);
	legend.cols = find_cols(temp) - 1;
	close(f);
	legend.map = create_map(legend.rows, legend.cols, temp, legend.head_size);
	free(temp);
	return (legend);
}
