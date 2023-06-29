/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_lib.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhomche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:27:11 by akhomche          #+#    #+#             */
/*   Updated: 2023/06/27 16:28:25 by akhomche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_LIB_H
# define FUNCTIONS_LIB_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

void		ft_putchar(char c);
void		ft_putstr(char *str);
void		print_matrix(int **matrix, int rows, int cols);
void		print_char_matrix(char **matrix, int rows, int cols);
char		*ft_numtostr(int num);
int			find_min(int a, int b, int c);
int			**create_matrix(int rows, int cols);
long int	a_toi(char *str);
long int	num_rows(char *temp, int size);
int			ft_strlen_mod(char *str);
void		ft_strconcat(char *dest, char *src, int *size, int buff_size);
void		ft_strcpy(char *dest, char *src);

struct s_Square
{
	int	size;
	int	y;
	int	x;
};

struct s_Legend
{
	char	**map;
	int		cols;
	int		rows;
	int		head_size;
	char	empty;
	char	obstacle;
	char	full;
};

#endif
