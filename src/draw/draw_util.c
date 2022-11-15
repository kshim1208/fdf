/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:26:56 by kshim             #+#    #+#             */
/*   Updated: 2022/11/03 12:19:11 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf_transform_struct.h"
#include "../../includes/fdf_matrix_buffer_struct.h"
#include "../../includes/fdf_scene_object_struct.h"
#include "../../includes/fdf_mlx_struct.h"
#include "../../includes/fdf_rendering_value_struct.h"
#include "../../includes/fdf_univ_struct.h"

#include "../../includes/fdf_draw.h"
#include "../../includes/fdf_mlx.h"
#include "../../includes/fdf_transform_util.h"

#include <math.h>

void	ft_set_draw_line_variable(t_fdf_draw_var *draw_var,
			t_fdf_pnt *pnt1, t_fdf_pnt *pnt2)
{
	draw_var -> low_high = 0;
	draw_var -> length = pnt2 -> vertex_tfmed[0] - pnt1 -> vertex_tfmed[0];
	draw_var -> height = pnt2 -> vertex_tfmed[1] - pnt1 -> vertex_tfmed[1];
	draw_var -> sign = 1;
	draw_var -> draw_vert[0] = pnt1 -> vertex_tfmed[0];
	draw_var -> draw_vert[1] = pnt1 -> vertex_tfmed[1];
	return ;
}

void	ft_set_pixel_data_with_z_buffer(t_fdf_univ *univ,
	t_fdf_pnt *pnt1, t_fdf_pnt *pnt2, t_fdf_draw_var *draw_var)
{
	float	ratio;
	float	now_z;

	if ((draw_var -> draw_vert[0] > univ -> rend_val -> win_xy[0]
			|| draw_var -> draw_vert[0] < 0)
		|| (draw_var -> draw_vert[1] > univ -> rend_val -> win_xy[1]
			|| draw_var -> draw_vert[1] < 0))
		return ;
	ratio = fabsf((float)(draw_var -> draw_vert[draw_var -> low_high]
				- pnt1 -> vertex_tfmed[draw_var -> low_high])
			/ (float)draw_var -> baseline);
	now_z = ((1.0 - ratio) * pnt1 -> vertex_tfmed[2])
		+ (ratio * pnt2 -> vertex_tfmed[2]);
	if (draw_var -> z_buffer[draw_var -> draw_vert[0]][draw_var -> draw_vert[1]]
		< now_z)
		return ;
	draw_var
		-> z_buffer[draw_var -> draw_vert[0]][draw_var -> draw_vert[1]] = now_z;
	ft_mlx_img_pixel(univ -> mlx_data -> img,
		draw_var -> draw_vert[0], draw_var -> draw_vert[1],
		ft_set_draw_line_color(pnt1 -> color, pnt2 -> color, ratio));
	return ;
}

int	ft_set_draw_line_color(int col1, int col2, float ratio)
{
	int		color;
	float	r_ratio;

	color = 0;
	r_ratio = 1.0 - ratio;
	color += (int)((r_ratio * (col1 >> 24 & 0xFF))
			+ (ratio * (col2 >> 24 & 0xFF))) << 24;
	color += (int)((r_ratio * (col1 >> 16 & 0xFF))
			+ (ratio * (col2 >> 16 & 0xFF))) << 16;
	color += (int)((r_ratio * (col1 >> 8 & 0xFF))
			+ (ratio * (col2 >> 8 & 0xFF))) << 8;
	color += (int)((r_ratio * (col1 & 0xFF))
			+ (ratio * (col2 & 0xFF)));
	return (color);
}

void	ft_set_fdf_z_buffer_initial_value(
			float **z_buffer, int window_x, int window_y)
{
	int	i;
	int	j;

	i = 0;
	while (i < (window_x + 1))
	{
		j = 0;
		while (j < (window_y + 1))
		{
			z_buffer[i][j] = 2.0;
			j++;
		}
		i++;
	}
	return ;
}
