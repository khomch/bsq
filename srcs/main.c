/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhomche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:55:03 by akhomche          #+#    #+#             */
/*   Updated: 2023/06/27 16:55:07 by akhomche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions_lib.h"

struct s_Legend	read_map(int size, int f);
struct s_Square	find_biggest_square(int **matrix, int rows, int cols);
int				**create_matrix(int rows, int cols);
void			print_matrix(int **matrix, int rows, int cols);
void			print_char_matrix(char **matrix, int rows, int cols);
void			convert_legend_to_matrix(struct s_Legend legend, int **matrix);
void			fill_map(struct s_Legend legend, struct s_Square square);
char			*ft_read(int fd, int buff_size, char *buff);

char	**create_char_matrix(int rows, int cols)
{
	int		y;
	char	**matrix;

	y = 0;
	matrix = (char **)malloc(sizeof(char *) * (rows));
	if (!matrix)
		return (NULL);
	while (y < rows)
	{
		matrix[y] = (char *)malloc(sizeof(char) * (cols));
		if (!matrix[y])
			return (NULL);
		y++;
	}
	return (matrix);
}

void	destroy(char **map, int **matrix, int rows)
{
	while (--rows)
	{
		free(map[rows]);
		free(matrix[rows]);
	}
	free(map[rows]);
	free(matrix[rows]);
	free(map);
	free(matrix);
}

void	find_bsq(struct s_Legend legend, int **matrix)
{
	matrix = create_matrix(legend.rows, legend.cols);
	convert_legend_to_matrix(legend, matrix);
	fill_map(legend, find_biggest_square(matrix, legend.rows, legend.cols));
	print_char_matrix(legend.map, legend.rows, legend.cols);
	destroy(legend.map, matrix, legend.rows);
	ft_putchar('\n');
}

int	start_process(char *str)
{
	int				f;
	int				size;
	int				**matrix;
	char			c;
	struct s_Legend	legend;

	matrix = NULL;
	size = 0;
	f = open(str, O_RDONLY);
	while (read(f, &c, 1))
		size++;
	close(f);
	f = open(str, O_RDONLY);
	legend = read_map(size, f);
	close(f);
	if (legend.map == NULL)
	{
		ft_putstr("ERROR");
		return (0);
	}
	find_bsq(legend, matrix);
	return (1);
}

int	main(int argc, char **argv)
{
	int		i;
	int		size;
	char	*str;
	char	*buff;

	size = 0;
	buff = (char *)malloc(sizeof(char) * 1);
	if (argc > 1)
	{
		i = 0;
		while (++i < argc)
			start_process(argv[i]);
	}
	else if (argc == 1)
	{
		str = ft_read(size, 10000, buff);
		start_process(str);
	}
	else
	{
		ft_putstr("No arguments");
		return (0);
	}
	return (1);
}
