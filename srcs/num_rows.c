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

#include <stdlib.h>

int	ft_atoi(char *str)
{
	int	number;
	int	i;
	int	mult;

	i = 0;
	number = 0;
	mult = 1;
	while (str[i] < '0' || str[i] > '9')
	{
		if (str[i] == '-')
			mult = mult * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + str[i] - '0';
		i++;
	}
	return (number * mult);
}

int	num_rows(char *temp, int size)
{
	int		res;
	char	*str;
	int		x;

	x = 0;
	str = (char *) malloc(sizeof(char ) * (size + 1));
	if (!str)
		return (0);
	while (temp[x] && temp[x] >= '0' && temp[x] <= '9' && (size - 3) > x)
	{
		str[x] = temp[x];
		x++;
	}
	str[x] = '\0';
	res = ft_atoi(str);
	free (str);
	return (res);
}
