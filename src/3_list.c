/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_list.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:17:27 by manufern          #+#    #+#             */
/*   Updated: 2024/01/23 18:22:14 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "../inc/fdf.h"
#include "../inc/get_next_line.h"

t_map	*new_map_node(int x, int y, int z, char *color)
{
	t_map	*new_node;

	new_node = malloc(sizeof(t_map));
	if (new_node == NULL)
	{
		return (NULL);
	}
	new_node->x = x;
	new_node->y = y;
	new_node->z = z / 3;
	new_node->color = ft_atoi_hexa(color);
	new_node->next = NULL;
	new_node->x_rotate = (((x - y) * cos(ANGULE))) * SCALE_FACTOR;
	new_node->y_rotate = ((x + y) * sin(ANGULE) - (z / 3)) * SCALE_FACTOR;
	new_node->last = NULL;
	return (new_node);
}

void	set_scale(t_map *map, float x_max, float y_max)
{
	t_map	*aux;
	float	scale;

	if (x_max > y_max)
		scale = ((HEIGHT / 2) - 40) / x_max;
	else
		scale = ((HEIGHT / 2) - 40) / y_max;
	aux = map;
	while (aux != NULL)
	{
		aux ->x_rotate = aux ->x_rotate * scale;
		aux ->y_rotate = aux ->y_rotate * scale;
		aux = aux->next;
	}
}

void	get_scale(t_map *map)
{
	float	x_max;
	float	y_max;
	t_map	*aux;

	aux = map;
	x_max = 0;
	y_max = 0;
	while (aux != NULL)
	{
		if (aux->x_rotate > x_max)
		{
			x_max = aux->x_rotate;
		}
		if (aux->y_rotate > y_max)
		{
			y_max = aux->y_rotate;
		}
		aux = aux->next;
	}
	set_scale(map, x_max, y_max);
}

void	ft_lstadd_back_map(t_map **lst, t_map const *new)
{
	t_map			*tmp;
	static t_map	*last = NULL;

	if (*lst == NULL)
	{
		*lst = (t_map *)new;
		last = *lst;
	}
	else
	{
		tmp = last;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = (t_map *)new;
		last = tmp->next;
		last->last = tmp;
	}
}

void	create_list(int x, int y, int z, char *color)
{
	static t_map	*map = NULL;
	t_map			*new_node;

	if (x == 234345 && y == 234345 && z == 234345)
	{
		get_scale(map);
		ft_drow(map, WIDTH / 2, HEIGHT / 2);
	}
	else
	{
		new_node = new_map_node(x, y, z, color);
		ft_lstadd_back_map(&map, new_node);
		return ;
	}
}
