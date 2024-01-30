/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:01:57 by manufern          #+#    #+#             */
/*   Updated: 2024/01/23 19:22:56 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "../inc/fdf.h"
#include "../inc/get_next_line.h"

int	ft_atoi_hexa(char *str)
{
	int		nbr;
	char	todecimal;

	nbr = 0;
	if (*str == '0')
		str++;
	if (*str == 'x')
		str++;
	while (*str)
	{
		todecimal = ft_toupper(*str);
		if (ft_isdigit(todecimal))
			nbr = nbr * 16 + (todecimal - '0');
		else if (ft_isalpha(todecimal))
			nbr = nbr * 16 + (todecimal - 'A' + 10);
		str++;
	}
	return (nbr);
}
