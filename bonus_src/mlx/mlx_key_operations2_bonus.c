/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_operations2_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:35:02 by kshim             #+#    #+#             */
/*   Updated: 2022/11/03 12:10:43 by kshim            ###   ########.fr       */
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

void	ft_mlx_key_scene_obj_transform_keycode(int keycode,
			t_fdf_rend_val *rend_val,
			t_fdf_matrix_buf *matrix_buf, t_fdf_scene_obj *scene_obj)
{
	if (keycode == KEY_U || keycode == KEY_J || keycode == KEY_O
		|| keycode == KEY_L || keycode == KEY_H || keycode == KEY_K)
		ft_mlx_key_scene_obj_rotate(keycode, rend_val,
			matrix_buf, scene_obj);
	else if (keycode == KEY_Y || keycode == KEY_I
		|| keycode == KEY_C || keycode == KEY_V)
		ft_mlx_key_scene_obj_scale_x_y(keycode, rend_val,
			scene_obj);
	else if (keycode == KEY_B || keycode == KEY_N || keycode == KEY_EIGHT
		|| keycode == KEY_FIVE || keycode == KEY_FOUR || keycode == KEY_SIX
		|| keycode == KEY_NINE || keycode == KEY_THREE)
		ft_mlx_key_scene_obj_scale_z_translate_xyz(
			keycode, rend_val, scene_obj);
	return ;
}

void	ft_mlx_key_scene_obj_rotate(int keycode, t_fdf_rend_val *rend_val,
			t_fdf_matrix_buf *matrix_buf, t_fdf_scene_obj *scene_obj)
{
	if (keycode == KEY_U)
		ft_scene_obj_rotate_xyz(matrix_buf, scene_obj, AXIS_X_PLUS);
	else if (keycode == KEY_J)
		ft_scene_obj_rotate_xyz(matrix_buf, scene_obj, AXIS_X_MINUS);
	else if (keycode == KEY_O)
		ft_scene_obj_rotate_xyz(matrix_buf, scene_obj, AXIS_Y_PLUS);
	else if (keycode == KEY_L)
		ft_scene_obj_rotate_xyz(matrix_buf, scene_obj, AXIS_Y_MINUS);
	else if (keycode == KEY_H)
		ft_scene_obj_rotate_xyz(matrix_buf, scene_obj, AXIS_Z_PLUS);
	else if (keycode == KEY_K)
		ft_scene_obj_rotate_xyz(matrix_buf, scene_obj, AXIS_Z_MINUS);
	rend_val -> display = 1;
	return ;
}

void	ft_mlx_key_scene_obj_scale_x_y(int keycode,
		t_fdf_rend_val *rend_val, t_fdf_scene_obj *scene_obj)
{
	if (keycode == KEY_Y)
	{
		if (scene_obj -> scene_obj_scale[0] > 0.01)
			ft_scene_obj_scale_xyz(scene_obj, AXIS_X_MINUS);
	}
	else if (keycode == KEY_I)
	{
		if (scene_obj -> scene_obj_scale[0] < 10)
			ft_scene_obj_scale_xyz(scene_obj, AXIS_X_PLUS);
	}
	else if (keycode == KEY_C)
	{
		if (scene_obj -> scene_obj_scale[1] < 10)
			ft_scene_obj_scale_xyz(scene_obj, AXIS_Y_PLUS);
	}
	else if (keycode == KEY_V)
	{
		if (scene_obj -> scene_obj_scale[1] > 0.01)
			ft_scene_obj_scale_xyz(scene_obj, AXIS_Y_MINUS);
	}
	rend_val -> display = 1;
	return ;
}

// translate 최대거리 예외처리
void	ft_mlx_key_scene_obj_scale_z_translate_xyz(int keycode,
		t_fdf_rend_val *rend_val, t_fdf_scene_obj *scene_obj)
{
	if (keycode == KEY_B)
	{
		if (scene_obj -> scene_obj_scale[2] < 10)
			ft_scene_obj_scale_xyz(scene_obj, AXIS_Z_PLUS);
	}
	else if (keycode == KEY_N)
	{
		if (scene_obj -> scene_obj_scale[2] > 0.01)
			ft_scene_obj_scale_xyz(scene_obj, AXIS_Z_MINUS);
	}
	else if (keycode == KEY_EIGHT)
		ft_scene_obj_translate_xyz(scene_obj, UP);
	else if (keycode == KEY_FIVE)
		ft_scene_obj_translate_xyz(scene_obj, DOWN);
	else if (keycode == KEY_FOUR)
		ft_scene_obj_translate_xyz(scene_obj, LEFT);
	else if (keycode == KEY_SIX)
		ft_scene_obj_translate_xyz(scene_obj, RIGHT);
	else if (keycode == KEY_NINE)
		ft_scene_obj_translate_xyz(scene_obj, ASCEND);
	else if (keycode == KEY_THREE)
		ft_scene_obj_translate_xyz(scene_obj, DESCEND);
	rend_val -> display = 1;
	return ;
}
