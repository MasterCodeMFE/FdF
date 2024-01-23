/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:44:04 by manufern          #+#    #+#             */
/*   Updated: 2024/01/23 19:47:47 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifndef WIDTH
#  define WIDTH 2560
# endif

# ifndef HEIGHT
#  define HEIGHT 1200
# endif

# ifndef ANGULE
#  define ANGULE 0.523599
# endif

# ifndef SCALE_FACTOR
#  define SCALE_FACTOR 1
# endif

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include "mlx.h"
# include "math.h"
# include "get_next_line.h"

typedef struct s_map
{
	int				x;
	int				y;
	int				z;
	float			x_rotate;
	float			y_rotate;
	int				color;
	struct s_map	*last;
	struct s_map	*next;
}	t_map;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	t_map	*map;
	int		bits_per_pixel;
	int		line_length;
	int		center_x;
	int		center_y;
	int		exit_flag;
}	t_data;

typedef struct s_dda_params
{
	float	dx;
	float	dy;
	int		steps;
	float	x;
	float	y;
	float	incx;
	float	incy;
}	t_dda_params;

int				main(int argc, char **argv);
int				ft_has_color(char *map_line);
void			ft_send_coord(int x, int y, int z, char *map_line);
void			ft_div_line(char const *line);
int				ft_get_line_map(char *argv);
t_map			*new_map_node(int x, int y, int z, char *color);
void			ft_lstadd_back_map(t_map **lst, t_map const *new);
void			create_list(int x, int y, int z, char *color);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			ft_drow_map(t_map *map, float center_x,
					float center_y, t_data *img);
int				close_window(int keycode, void *param);
void			ft_drow(t_map *map, float center_x, float center_y);
int				ft_atoi_hexa(char *str);
void			ft_free_s_map(t_map **map);
int				ft_atoi(const char *str);
t_dda_params	set_dda_params(t_map *p1, t_map *p2,
					float center_x, float center_y);
void			ft_dda(t_data *img, t_dda_params params,
					int color1, int color2);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_string_count(char const *s, char c);
int				ft_word_count(char const *s, char c, int i);
char			**ft_free(char **aux, int j);
char			**ft_matrix(char **aux, char const *s, char c, int i);
char			**ft_split(char const *s, char c);
char			*ft_strcpy_to_char(char *str, char c);
size_t			ft_strlen(const char *s);
int				ft_toupper(int c);

#endif
