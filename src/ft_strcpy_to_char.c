/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_to_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:08:41 by manufern          #+#    #+#             */
/*   Updated: 2024/01/23 19:25:02 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "../inc/fdf.h"
#include "../inc/get_next_line.h"

char	*ft_strcpy_to_char(char*str, char c)
{
	char	*aux;
	int		i;

	i = 0;
	aux = malloc(sizeof(char) *(ft_strlen(str) + 1));
	if (aux == NULL)
		return (NULL);
	while (str[i] != c && str[i] != '\0')
	{
		aux[i] = str[i];
		i++;
	}
	aux[i] = '\0';
	return (aux);
}
