/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_drow_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:30:38 by manufern          #+#    #+#             */
/*   Updated: 2024/02/03 14:03:38 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "../inc/fdf.h"
#include "../inc/get_next_line.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_drow_map(t_map *map, float center_x, float center_y, t_data *img)
{
	t_map	*line1;
	t_map	*line2;

	line1 = map;
	line2 = map;
	while (line2 != NULL && line2->y != 1)
		line2 = line2->next;
	while (line1 && (line2 || line1->next))
	{
		if (line1->next && line1->y == line1->next->y)
			ft_dda(img, set_dda_params(line1, line1->next, center_x, center_y),
				line1->color, line1->next->color);
		if (line2)
			ft_dda(img, set_dda_params(line1, line2, center_x, center_y),
				line1->color, line2->color);
		line1 = line1->next;
		if (line2)
			line2 = line2->next;
	}
}

int	close_program(int param)
{
	(void)param;
	exit(0);
	return (0);
}

int	press_key(int keycode)
{
	if (keycode == 53)
	{
		exit(0);
	}
	return (0);
}

void	ft_drow(t_map *map, float center_x, float center_y)
{
	void	*mlx;
	void	*mlx_win;
	void	*logo;
	t_data	img;
	int		width;
	int		height;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "FDF");
	if (mlx_win == NULL)
	{
		return ;
	}

	// Carga la imagen del logo
	logo = mlx_xpm_file_to_image(mlx, "Logo.xpm", &width, &height);
	if (logo == NULL)
	{
		mlx_destroy_window(mlx, mlx_win);
		return ;
	}

	// Dibuja la imagen del logo en la ventana
	
	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (img.img == NULL)
	{
		mlx_destroy_window(mlx, mlx_win);
		return ;
	}
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.exit_flag);
	ft_drow_map(map, center_x, center_y, &img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_put_image_to_window(mlx, mlx_win, logo, 0, 0);
	mlx_hook(mlx_win, 2, 0, press_key, &img);
	mlx_hook(mlx_win, 17, 0, close_program, NULL);
	mlx_loop(mlx);
}
