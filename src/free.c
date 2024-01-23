/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:32:01 by manufern          #+#    #+#             */
/*   Updated: 2024/01/23 18:58:11 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "../inc/fdf.h"
#include "../inc/get_next_line.h"

void	ft_free_s_map(t_map **map)
{
	t_map	*aux;
	t_map	*dulp;

	if (map == NULL)
	{
		return ;
	}
	dulp = *map;
	while (dulp)
	{
		aux = dulp->next;
		free(dulp);
		dulp = aux;
	}
	*map = NULL;
}
