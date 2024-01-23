/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dda.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 10:55:10 by manuel            #+#    #+#             */
/*   Updated: 2024/01/23 19:21:46 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "../inc/fdf.h"
#include "../inc/get_next_line.h"

t_dda_params	set_dda_params(t_map *p1, t_map *p2,
			float center_x, float center_y)
{
	t_dda_params	params;

	params.dx = p2->x_rotate - p1->x_rotate;
	params.dy = p2->y_rotate - p1->y_rotate;
	if (fabs(params.dx) > fabs(params.dy))
		params.steps = fabs(params.dx);
	else
		params.steps = fabs(params.dy);
	params.incx = params.dx / params.steps;
	params.incy = params.dy / params.steps;
	params.x = p1->x_rotate + center_x;
	params.y = p1->y_rotate + center_y;
	return (params);
}

void	ft_dda(t_data *img, t_dda_params params, int color1, int color2)
{
	int		i;
	int		x_rounded;
	int		y_rounded;
	double	color_step;
	int		color;

	i = 0;
	if (params.steps != 0)
		color_step = (double)(color2 - color1) / params.steps;
	color = color1;
	while (i <= params.steps)
	{
		x_rounded = (int) params.x;
		y_rounded = (int) params.y;
		if (x_rounded >= 0 && x_rounded < WIDTH && y_rounded >= 0
			&& y_rounded < HEIGHT)
			my_mlx_pixel_put(img, x_rounded, y_rounded, color);
		params.x += params.incx;
		params.y += params.incy;
		color = color1 + (int)(color_step * i);
		i++;
	}
}
