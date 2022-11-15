/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:21:17 by kshim             #+#    #+#             */
/*   Updated: 2022/11/03 12:10:01 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../bonus_includes/fdf_matrix_buffer_struct_bonus.h"
#include "../../bonus_includes/fdf_transform_struct_bonus.h"
#include "../../bonus_includes/fdf_scene_object_struct_bonus.h"
#include "../../bonus_includes/fdf_mlx_struct_bonus.h"
#include "../../bonus_includes/fdf_rendering_value_struct_bonus.h"
#include "../../bonus_includes/fdf_univ_struct_bonus.h"

#include "../../bonus_includes/fdf_mlx_key_operation_struct_bonus.h"

#include "../../bonus_includes/fdf_mlx_key_define_bonus.h"
#include "../../bonus_includes/fdf_mlx_key_operation_transform_bonus.h"
#include "../../bonus_includes/fdf_transform_rotate_bonus.h"
#include "../../bonus_includes/fdf_transform_translate_bonus.h"
#include "../../bonus_includes/fdf_transform_util_bonus.h"

#include <math.h>

void	ft_cam_rotate_xyz(t_fdf_rend_val *rend_val,
			t_fdf_matrix_buf *matrix_buf, t_tf_matrix *cam_tf,
				int rotate_axis)
{
	float	tmp_cam_vec[4][4];
	float	new_cam_vec[4][4];

	ft_set_translate_matrix_invert(
		rend_val -> look_pnt, matrix_buf -> matrix_buf_4x4);
	ft_multiply_matrix_44_14(matrix_buf -> matrix_buf_4x4,
		rend_val -> cam_pivot, matrix_buf -> matrix_buf_1x4);
	ft_multiply_matrix_44_14(cam_tf -> rotate,
		matrix_buf -> matrix_buf_1x4, rend_val -> cam_pivot);
	ft_cam_rotate_set_rotation_matrix(matrix_buf, rotate_axis);
	ft_matrix_copy_44(matrix_buf -> matrix_buf_4x4, tmp_cam_vec);
	ft_multiply_matrix_44_14(matrix_buf -> matrix_buf_4x4,
		rend_val -> cam_pivot, matrix_buf -> matrix_buf_1x4);
	ft_set_transpose_matrix(cam_tf -> rotate, matrix_buf -> matrix_buf_4x4);
	ft_multiply_matrix_44_14(matrix_buf -> matrix_buf_4x4,
		matrix_buf -> matrix_buf_1x4, rend_val -> cam_pivot);
	ft_multiply_matrix_44_44(matrix_buf -> matrix_buf_4x4,
		tmp_cam_vec, new_cam_vec);
	ft_set_translate_matrix(rend_val -> look_pnt, matrix_buf -> matrix_buf_4x4);
	ft_matrix_copy_14(rend_val -> cam_pivot, matrix_buf -> matrix_buf_1x4);
	ft_multiply_matrix_44_14(matrix_buf -> matrix_buf_4x4,
		matrix_buf -> matrix_buf_1x4, rend_val -> cam_pivot);
	ft_set_cam_vec_xyz(rend_val, new_cam_vec);
	return ;
}

void	ft_cam_rotate_set_rotation_matrix(
			t_fdf_matrix_buf *matrix_buf, int rotate_axis)
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
	return ;
}

void	ft_cam_translate(t_fdf_rend_val *rend_val,
			t_fdf_matrix_buf *matrix_buf, t_tf_matrix *cam_tf,
				int direction)
{
	float	tmp_translate_vec[4];

	ft_set_translate_direction_vector(tmp_translate_vec, direction);
	ft_matrix_copy_14(tmp_translate_vec, matrix_buf -> matrix_buf_1x4);
	ft_set_transpose_matrix(cam_tf -> rotate, matrix_buf -> matrix_buf_4x4);
	ft_multiply_matrix_44_14(matrix_buf -> matrix_buf_4x4,
		matrix_buf -> matrix_buf_1x4, tmp_translate_vec);
	if (ft_check_cam_can_be_translated(
			rend_val -> cam_translate, tmp_translate_vec) == 0)
		return ;
	rend_val -> look_pnt[0] += tmp_translate_vec[0];
	rend_val -> look_pnt[1] += tmp_translate_vec[1];
	rend_val -> look_pnt[2] += tmp_translate_vec[2];
	rend_val -> cam_pivot[0] += tmp_translate_vec[0];
	rend_val -> cam_pivot[1] += tmp_translate_vec[1];
	rend_val -> cam_pivot[2] += tmp_translate_vec[2];
	return ;
}
