/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_operations_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:35:02 by kshim             #+#    #+#             */
/*   Updated: 2022/11/03 12:10:48 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../bonus_includes/fdf_mlx_key_operation_struct_bonus.h"
#include "../../bonus_includes/fdf_rendering_value_struct_bonus.h"
#include "../../bonus_includes/fdf_matrix_buffer_struct_bonus.h"
#include "../../bonus_includes/fdf_transform_struct_bonus.h"
#include "../../bonus_includes/fdf_scene_object_struct_bonus.h"

#include "../../bonus_includes/fdf_mlx_key_define_bonus.h"
#include "../../bonus_includes/fdf_mlx_key_operation_bonus.h"
#include "../../bonus_includes/fdf_mlx_key_operation_transform_bonus.h"

void	ft_mlx_key_ortho_scale_cam_transform_keycode(int keycode,
			t_fdf_rend_val *rend_val,
			t_fdf_matrix_buf *matrix_buf, t_tf_data_group *tf_matrices)
{
	if (keycode == KEY_Q || keycode == KEY_E)
		ft_mlx_key_orthographic_scale(keycode, rend_val,
			tf_matrices -> prj_tf_data);
	else if (keycode == KEY_W || keycode == KEY_S || keycode == KEY_A
		|| keycode == KEY_D || keycode == KEY_R || keycode == KEY_F)
		ft_mlx_key_cam_rotate(keycode, rend_val,
			matrix_buf, tf_matrices -> cam_tf);
	else if (keycode == KEY_UP || keycode == KEY_DOWN
		|| keycode == KEY_LEFT || keycode == KEY_RIGHT)
		ft_mlx_key_cam_translate(keycode, rend_val,
			matrix_buf, tf_matrices -> cam_tf);
	return ;
}

void	ft_mlx_key_orthographic_scale(
		int keycode, t_fdf_rend_val *rend_val, t_project_tf_data *prj_tf_data)
{
	if (keycode == KEY_Q)
	{
		if (rend_val -> ortho_persp == 0 && prj_tf_data -> orth_scale > 0.01)
			prj_tf_data -> orth_scale = prj_tf_data -> orth_scale * 0.9;
		else if (rend_val -> ortho_persp == 1 && prj_tf_data -> pers_scale < 10)
			prj_tf_data -> pers_scale = prj_tf_data -> pers_scale * 1.1;
	}
	else if (keycode == KEY_E)
	{
		if (rend_val -> ortho_persp == 0 && prj_tf_data -> orth_scale < 10)
			prj_tf_data -> orth_scale = prj_tf_data -> orth_scale * 1.1;
		else if (rend_val -> ortho_persp == 1
			&& prj_tf_data -> pers_scale > 0.1)
			prj_tf_data -> pers_scale = prj_tf_data -> pers_scale * 0.9;
	}
	rend_val -> display = 1;
	return ;
}

void	ft_mlx_key_cam_rotate(int keycode, t_fdf_rend_val *rend_val,
			t_fdf_matrix_buf *matrix_buf, t_tf_matrix *cam_tf)
{
	if (keycode == KEY_W)
		ft_cam_rotate_xyz(rend_val, matrix_buf, cam_tf, AXIS_X_MINUS);
	else if (keycode == KEY_S)
		ft_cam_rotate_xyz(rend_val, matrix_buf, cam_tf, AXIS_X_PLUS);
	else if (keycode == KEY_R)
		ft_cam_rotate_xyz(rend_val, matrix_buf, cam_tf, AXIS_Y_MINUS);
	else if (keycode == KEY_F)
		ft_cam_rotate_xyz(rend_val, matrix_buf, cam_tf, AXIS_Y_PLUS);
	else if (keycode == KEY_A)
		ft_cam_rotate_xyz(rend_val, matrix_buf, cam_tf, AXIS_Z_MINUS);
	else if (keycode == KEY_D)
		ft_cam_rotate_xyz(rend_val, matrix_buf, cam_tf, AXIS_Z_PLUS);
	rend_val -> display = 1;
	return ;
}

void	ft_mlx_key_cam_translate(int keycode, t_fdf_rend_val *rend_val,
			t_fdf_matrix_buf *matrix_buf, t_tf_matrix *cam_tf)
{
	if (keycode == KEY_UP)
		ft_cam_translate(rend_val, matrix_buf, cam_tf, UP);
	else if (keycode == KEY_DOWN)
		ft_cam_translate(rend_val, matrix_buf, cam_tf, DOWN);
	else if (keycode == KEY_LEFT)
		ft_cam_translate(rend_val, matrix_buf, cam_tf, LEFT);
	else if (keycode == KEY_RIGHT)
		ft_cam_translate(rend_val, matrix_buf, cam_tf, RIGHT);
	rend_val -> display = 1;
	return ;
}
