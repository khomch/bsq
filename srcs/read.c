/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhomche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 22:51:22 by akhomche          #+#    #+#             */
/*   Updated: 2023/06/28 22:51:28 by akhomche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions_lib.h"

void	ft_check_infinity(int *size, char *str, int buf)
{
	if (*size == buf)
	{
		if (ft_strlen_mod(str) == 0)
		{
			ft_putstr("");
			*size = -1;
		}
	}
}

char	*ft_read(int fd, int buff_size, char *buff)
{
	char	*str;
	char	*temp;
	int		size;

	size = 0;
	buff = (char *)malloc(sizeof(char) * (buff_size + 1));
	str = (char *)malloc(sizeof(*str) * (size + 1));
	temp = (char *)malloc(sizeof(*str) * (size + 1));
	str[0] = 0;
	temp[0] = 0;
	while (read(fd, buff, buff_size) && str && temp && size >= 0)
	{
		size += buff_size;
		ft_strcpy(temp, str);
		free(str);
		str = (char *)malloc(sizeof(*str) * (size + 1));
		ft_strcpy(str, temp);
		ft_strconcat(str, buff, &size, buff_size);
		str[size] = '\0';
		free(temp);
		temp = (char *)malloc(sizeof(*temp) * (size + 1));
		ft_check_infinity(&size, str, buff_size);
	}
	free(temp);
	return (str);
}
