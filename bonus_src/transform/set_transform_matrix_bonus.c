/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_transform_matrix_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 09:21:43 by kshim             #+#    #+#             */
/*   Updated: 2022/11/03 12:09:14 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../bonus_includes/fdf_transform_struct_bonus.h"
#include "../../bonus_includes/fdf_matrix_buffer_struct_bonus.h"
#include "../../bonus_includes/fdf_scene_object_struct_bonus.h"
#include "../../bonus_includes/fdf_mlx_struct_bonus.h"
#include "../../bonus_includes/fdf_rendering_value_struct_bonus.h"
#include "../../bonus_includes/fdf_univ_struct_bonus.h"

#include "../../bonus_includes/fdf_transform_bonus.h"
#include "../../bonus_includes/fdf_transform_util_bonus.h"

void	ft_set_object_transform_matrix(t_fdf_scene_obj *scene_obj,
			t_fdf_matrix_buf *matrix_buf,
			t_tf_matrix *obj_tf, float obj_tf_all[4][4])
{
	obj_tf -> translate[0][3] = scene_obj -> scene_obj_translate[0];
	obj_tf -> translate[1][3] = scene_obj -> scene_obj_translate[1];
	obj_tf -> translate[2][3] = scene_obj -> scene_obj_translate[2];
	obj_tf -> rotate[0][0] = scene_obj -> scene_obj_vec_x[0];
	obj_tf -> rotate[1][0] = scene_obj -> scene_obj_vec_x[1];
	obj_tf -> rotate[2][0] = scene_obj -> scene_obj_vec_x[2];
	obj_tf -> rotate[0][1] = scene_obj -> scene_obj_vec_y[0];
	obj_tf -> rotate[1][1] = scene_obj -> scene_obj_vec_y[1];
	obj_tf -> rotate[2][1] = scene_obj -> scene_obj_vec_y[2];
	obj_tf -> rotate[0][2] = scene_obj -> scene_obj_vec_z[0];
	obj_tf -> rotate[1][2] = scene_obj -> scene_obj_vec_z[1];
	obj_tf -> rotate[2][2] = scene_obj -> scene_obj_vec_z[2];
	obj_tf -> scale[0][0] = scene_obj -> scene_obj_scale[0];
	obj_tf -> scale[1][1] = scene_obj -> scene_obj_scale[1];
	obj_tf -> scale[2][2] = scene_obj -> scene_obj_scale[2];
	ft_multiply_matrix_44_44(obj_tf -> translate,
		obj_tf -> rotate, matrix_buf -> matrix_buf_4x4);
	ft_multiply_matrix_44_44(matrix_buf -> matrix_buf_4x4,
		obj_tf -> scale, obj_tf_all);
	return ;
}

void	ft_set_camera_transform_matrix(t_fdf_rend_val *rend_val,
	t_tf_matrix *cam_tf, float cam_tf_all[4][4])
{
	cam_tf -> translate[0][3] = -1 * rend_val -> cam_pivot[0];
	cam_tf -> translate[1][3] = -1 * rend_val -> cam_pivot[1];
	cam_tf -> translate[2][3] = -1 * rend_val -> cam_pivot[2];
	cam_tf -> translate[3][3] = 1;
	cam_tf -> rotate[0][0] = rend_val -> cam_vec_x[0];
	cam_tf -> rotate[0][1] = rend_val -> cam_vec_x[1];
	cam_tf -> rotate[0][2] = rend_val -> cam_vec_x[2];
	cam_tf -> rotate[1][0] = rend_val -> cam_vec_y[0];
	cam_tf -> rotate[1][1] = rend_val -> cam_vec_y[1];
	cam_tf -> rotate[1][2] = rend_val -> cam_vec_y[2];
	cam_tf -> rotate[2][0] = rend_val -> cam_vec_z[0];
	cam_tf -> rotate[2][1] = rend_val -> cam_vec_z[1];
	cam_tf -> rotate[2][2] = rend_val -> cam_vec_z[2];
	ft_multiply_matrix_44_44(cam_tf -> rotate, cam_tf -> translate, cam_tf_all);
	ft_multiply_matrix_44_14(cam_tf_all,
		rend_val -> look_pnt, rend_val -> look_pnt_cam);
	return ;
}

void	ft_set_viewport_transform_matrix(t_fdf_rend_val *rend_val,
			float viewpt_tf_all[4][4])
{
	int		scale_x;
	int		scale_y;

	scale_x = (rend_val -> win_xy[0] - 0) / 2;
	scale_y = (rend_val -> win_xy[1] - 0) / 2;
	viewpt_tf_all[0][0] = scale_x;
	viewpt_tf_all[0][3] = 0 - (-1 * scale_x);
	viewpt_tf_all[1][1] = -1 * scale_y;
	viewpt_tf_all[1][3] = 0 - (-1 * scale_y);
	viewpt_tf_all[2][2] = 0.5;
	viewpt_tf_all[2][3] = 0.5;
	viewpt_tf_all[3][3] = 1;
	return ;
}

void	ft_join_tranform_matrices(t_fdf_univ *univ)
{
	if (univ -> rend_val -> ortho_persp == 0)
	{
		ft_multiply_matrix_44_44(univ -> tf_all_matrices -> viewpt_tf_all,
			univ -> tf_all_matrices -> prj_tf_all,
			univ -> matrix_buf -> matrix_buf_4x4);
		ft_multiply_matrix_44_44(univ -> matrix_buf -> matrix_buf_4x4,
			univ -> tf_all_matrices -> cam_tf_all,
			univ -> tf_all_matrices -> tf_all);
	}
	else
	{
		ft_multiply_matrix_44_44(univ -> tf_all_matrices -> prj_tf_all,
			univ -> tf_all_matrices -> cam_tf_all,
			univ -> tf_all_matrices -> tf_all);
	}
	return ;
}

void	ft_set_tf_matrix(t_fdf_univ *univ)
{
	ft_set_object_transform_matrix(univ -> scene_obj, univ -> matrix_buf,
		univ -> tf_matrices -> obj_tf, univ -> tf_all_matrices -> obj_tf_all);
	ft_set_camera_transform_matrix(univ -> rend_val,
		univ -> tf_matrices -> cam_tf,
		univ -> tf_all_matrices -> cam_tf_all);
	if (univ -> rend_val -> ortho_persp == 0)
	{
		ft_set_ortho_projection_transform_matrix(univ -> rend_val,
			univ -> tf_matrices -> prj_tf_data,
			univ -> tf_all_matrices -> prj_tf_all);
	}
	else
	{
		ft_set_pers_projection_transform_matrix(univ -> rend_val,
			univ -> tf_matrices -> prj_tf_data,
			univ -> tf_all_matrices -> prj_tf_all);
	}
	ft_set_viewport_transform_matrix(univ -> rend_val,
		univ -> tf_all_matrices -> viewpt_tf_all);
	return ;
}
