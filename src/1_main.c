/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 19:58:38 by manufern          #+#    #+#             */
/*   Updated: 2024/01/27 10:16:52 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "../inc/fdf.h"

int	terminatefdf(const char *str)
{
	int	longi;
	int	i;

	longi = 0;
	while (str[longi] != '\0')
	{
		longi++;
	}
	if (longi < 5)
	{
		return (0);
	}
	i = longi - 4;
	if (str[i] == '.' && str[i + 1] == 'f' && str[i + 2] == 'd'
		&& str[i + 3] == 'f')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		return (-1);
	}
	if (terminatefdf(argv[1]) == 1)
		ft_get_line_map(argv[1]);
	return (0);
}
