/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_scene_obj_coordinate_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 12:55:01 by kshim             #+#    #+#             */
/*   Updated: 2022/11/03 12:09:32 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../bonus_includes/fdf_mlx_key_operation_struct_bonus.h"
#include "../../bonus_includes/fdf_scene_object_struct_bonus.h"
#include "../../bonus_includes/fdf_matrix_buffer_struct_bonus.h"
#include "../../bonus_includes/fdf_rendering_value_struct_bonus.h"
#include "../../bonus_includes/fdf_transform_struct_bonus.h"

#include "../../bonus_includes/fdf_mlx_key_define_bonus.h"

#include "../../bonus_includes/fdf_transform_rotate_bonus.h"
#include "../../bonus_includes/fdf_transform_util_bonus.h"
#include "../../bonus_includes/fdf_scene_object_bonus.h"

void	ft_set_scene_obj_pnt(t_fdf_rend_val *rend_val, t_fdf_pnt **pnt_2_arr)
{
	int	base_x;
	int	base_y;
	int	i;
	int	j;

	ft_calc_base_xy_for_scene_object(rend_val, &base_x, &base_y);
	i = 0;
	while (i < rend_val -> row)
	{
		j = 0;
		while (j < rend_val -> col)
		{
			pnt_2_arr[i][j].vertex[0] = base_x + (j * rend_val -> btw_vertex);
			pnt_2_arr[i][j].vertex[1] = base_y - (i * rend_val -> btw_vertex);
			j++;
		}
		i++;
	}
	return ;
}

void	ft_calc_base_xy_for_scene_object(t_fdf_rend_val *rend_val,
			int *base_x, int *base_y)
{
	if (rend_val -> col % 2 == 1)
		*base_x = -1 * (rend_val -> btw_vertex * (rend_val -> col - 1) / 2);
	else
		*base_x = -1 * ((rend_val -> btw_vertex * (rend_val -> col / 2))
				- (rend_val -> btw_vertex / 2));
	if (rend_val -> row % 2 == 1)
		*base_y = (rend_val -> btw_vertex * (rend_val -> row - 1) / 2);
	else
		*base_y = ((rend_val -> btw_vertex * (rend_val -> row / 2))
				- (rend_val -> btw_vertex / 2));
	return ;
}

void	ft_scene_obj_rotate_xyz(t_fdf_matrix_buf *matrix_buf,
			t_fdf_scene_obj *scene_obj, int rotate_axis)
{
	if (rotate_axis == AXIS_X_PLUS)
		ft_rotate_axis_x(matrix_buf -> matrix_buf_4x4, 3);
	else if (rotate_axis == AXIS_X_MINUS)
		ft_rotate_axis_x(matrix_buf -> matrix_buf_4x4, -3);
	else if (rotate_axis == AXIS_Y_PLUS)
		ft_rotate_axis_y(matrix_buf -> matrix_buf_4x4, 3);
	else if (rotate_axis == AXIS_Y_MINUS)
		ft_rotate_axis_y(matrix_buf -> matrix_buf_4x4, -3);
	else if (rotate_axis == AXIS_Z_PLUS)
		ft_rotate_axis_z(matrix_buf -> matrix_buf_4x4, 3);
	else if (rotate_axis == AXIS_Z_MINUS)
		ft_rotate_axis_z(matrix_buf -> matrix_buf_4x4, -3);
	ft_matrix_copy_14(scene_obj -> scene_obj_vec_x,
		matrix_buf -> matrix_buf_1x4);
	ft_multiply_matrix_44_14(matrix_buf -> matrix_buf_4x4,
		matrix_buf -> matrix_buf_1x4, scene_obj -> scene_obj_vec_x);
	ft_matrix_copy_14(scene_obj -> scene_obj_vec_y,
		matrix_buf -> matrix_buf_1x4);
	ft_multiply_matrix_44_14(matrix_buf -> matrix_buf_4x4,
		matrix_buf -> matrix_buf_1x4, scene_obj -> scene_obj_vec_y);
	ft_matrix_copy_14(scene_obj -> scene_obj_vec_z,
		matrix_buf -> matrix_buf_1x4);
	ft_multiply_matrix_44_14(matrix_buf -> matrix_buf_4x4,
		matrix_buf -> matrix_buf_1x4, scene_obj -> scene_obj_vec_z);
	return ;
}

void	ft_scene_obj_scale_xyz(t_fdf_scene_obj *scene_obj, int scale_axis)
{
	if (scale_axis == AXIS_X_PLUS)
		scene_obj -> scene_obj_scale[0]
			= scene_obj -> scene_obj_scale[0] + 0.1;
	if (scale_axis == AXIS_X_MINUS)
		scene_obj -> scene_obj_scale[0]
			= scene_obj -> scene_obj_scale[0] - 0.1;
	else if (scale_axis == AXIS_Y_PLUS)
		scene_obj -> scene_obj_scale[1]
			= scene_obj -> scene_obj_scale[1] + 0.1;
	else if (scale_axis == AXIS_Y_MINUS)
		scene_obj -> scene_obj_scale[1]
			= scene_obj -> scene_obj_scale[1] - 0.1;
	else if (scale_axis == AXIS_Z_PLUS)
		scene_obj -> scene_obj_scale[2]
			= scene_obj -> scene_obj_scale[2] + 0.1;
	else if (scale_axis == AXIS_Z_MINUS)
		scene_obj -> scene_obj_scale[2]
			= scene_obj -> scene_obj_scale[2] - 0.1;
	return ;
}

void	ft_scene_obj_translate_xyz(t_fdf_scene_obj *scene_obj, int direction)
{
	int	vector_index;

	if (direction == UP)
		vector_index = 0;
	else if (direction == DOWN)
		vector_index = 0;
	else if (direction == LEFT)
		vector_index = 1;
	else if (direction == RIGHT)
		vector_index = 1;
	else if (direction == ASCEND)
		vector_index = 2;
	else if (direction == DESCEND)
		vector_index = 2;
	if (direction == UP || direction == LEFT || direction == ASCEND)
	{
		if (scene_obj -> scene_obj_translate[vector_index] < 1000)
			scene_obj -> scene_obj_translate[vector_index] += 3;
	}
	else if (direction == DOWN || direction == RIGHT || direction == DESCEND)
	{
		if (scene_obj -> scene_obj_translate[vector_index] > -1000)
			scene_obj -> scene_obj_translate[vector_index] -= 3;
	}
	return ;
}
