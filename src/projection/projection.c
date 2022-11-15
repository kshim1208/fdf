/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:57:35 by kshim             #+#    #+#             */
/*   Updated: 2022/10/31 16:00:10 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"

#include "../../includes/fdf_mlx_struct.h"
#include "../../includes/fdf_matrix_buffer_struct.h"
#include "../../includes/fdf_transform_struct.h"
#include "../../includes/fdf_scene_object_struct.h"
#include "../../includes/fdf_rendering_value_struct.h"
#include "../../includes/fdf_univ_struct.h"

#include "../../includes/fdf_transform_rotate.h"
#include "../../includes/fdf_transform_translate.h"
#include "../../includes/fdf_transform_util.h"
#include "../../includes/fdf_cam.h"

#include <math.h>

void	ft_isometric_projection(t_fdf_rend_val *rend_val,
			t_fdf_scene_obj *scene_obj, t_fdf_matrix_buf *matrix_buf,
			t_tf_matrix *cam_pos_tf)
{
	float	rotate_z[4][4];
	float	rotate_x[4][4];

	ft_set_right_camera(rend_val, scene_obj);
	ft_rotate_axis_z(rotate_z, 45);
	ft_rotate_axis_x(rotate_x, 35.264);
	ft_multiply_matrix_44_44(rotate_x, rotate_z, cam_pos_tf -> rotate);
	ft_set_translate_matrix(rend_val -> cam_pivot, cam_pos_tf -> translate);
	ft_set_translate_matrix_invert(
		rend_val -> look_pnt, matrix_buf -> matrix_buf_4x4);
	ft_multiply_matrix_44_14(matrix_buf -> matrix_buf_4x4,
		rend_val -> cam_pivot, matrix_buf -> matrix_buf_1x4);
	ft_multiply_matrix_44_14(cam_pos_tf -> rotate,
		matrix_buf -> matrix_buf_1x4, rend_val -> cam_pivot);
	ft_set_translate_matrix(rend_val -> look_pnt, matrix_buf -> matrix_buf_4x4);
	ft_matrix_copy_14(rend_val -> cam_pivot, matrix_buf -> matrix_buf_1x4);
	ft_multiply_matrix_44_14(matrix_buf -> matrix_buf_4x4,
		matrix_buf -> matrix_buf_1x4, rend_val -> cam_pivot);
	ft_calc_coordinate_vector(rend_val);
	return ;
}
