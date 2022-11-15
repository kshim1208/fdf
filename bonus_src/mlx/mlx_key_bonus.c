/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 13:32:18 by kshim             #+#    #+#             */
/*   Updated: 2022/11/03 12:11:06 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mlx/mlx.h"

#include "../../bonus_includes/fdf_mlx_key_operation_struct_bonus.h"
#include "../../bonus_includes/fdf_matrix_buffer_struct_bonus.h"
#include "../../bonus_includes/fdf_rendering_value_struct_bonus.h"
#include "../../bonus_includes/fdf_transform_struct_bonus.h"
#include "../../bonus_includes/fdf_scene_object_struct_bonus.h"
#include "../../bonus_includes/fdf_mlx_struct_bonus.h"
#include "../../bonus_includes/fdf_univ_struct_bonus.h"

#include "../../bonus_includes/fdf_mlx_key_define_bonus.h"
#include "../../bonus_includes/fdf_mlx_key_bonus.h"
#include "../../bonus_includes/fdf_mlx_key_operation_bonus.h"

#include "../../bonus_includes/fdf_projection_bonus.h"
#include "../../bonus_includes/fdf_mlx_key_operation_transform_bonus.h"
#include "../../bonus_includes/fdf_draw_bonus.h"
#include "../../bonus_includes/fdf_transform_bonus.h"
#include "../../bonus_includes/fdf_mlx_bonus.h"
#include "../../bonus_includes/fdf_univ_bonus.h"
#include <stdlib.h>

void	ft_mlx_loop(t_fdf_univ *fdf_data)
{
	mlx_put_image_to_window(fdf_data -> mlx_data -> mlx_ptr,
		fdf_data -> mlx_data -> mlx_win,
		fdf_data -> mlx_data -> img -> img_ptr, 0, 0);
	mlx_hook(fdf_data -> mlx_data -> mlx_win, X_EVENT_KEY_PRESS,
		0, &ft_key_press, fdf_data);
	mlx_loop(fdf_data -> mlx_data -> mlx_ptr);
	return ;
}

int	ft_key_press(int keycode, t_fdf_univ *fdf_data)
{
	if (keycode == KEY_ESC || keycode == KEY_Z
		|| keycode == KEY_X || keycode == KEY_M)
		ft_mlx_key_window_destroy_projection_change(keycode, fdf_data);
	else if (keycode == KEY_W || keycode == KEY_S || keycode == KEY_A
		|| keycode == KEY_D || keycode == KEY_R || keycode == KEY_F
		|| keycode == KEY_UP || keycode == KEY_DOWN || keycode == KEY_E
		|| keycode == KEY_LEFT || keycode == KEY_RIGHT || keycode == KEY_Q)
		ft_mlx_key_ortho_scale_cam_transform_keycode(keycode,
			fdf_data -> rend_val,
			fdf_data -> matrix_buf, fdf_data -> tf_matrices);
	else if (keycode == KEY_U || keycode == KEY_J || keycode == KEY_O
		|| keycode == KEY_L || keycode == KEY_H || keycode == KEY_K
		|| keycode == KEY_Y || keycode == KEY_I || keycode == KEY_C
		|| keycode == KEY_V || keycode == KEY_B || keycode == KEY_N
		|| keycode == KEY_EIGHT || keycode == KEY_FIVE || keycode == KEY_FOUR
		|| keycode == KEY_SIX || keycode == KEY_NINE || keycode == KEY_THREE)
		ft_mlx_key_scene_obj_transform_keycode(keycode,
			fdf_data -> rend_val,
			fdf_data -> matrix_buf, fdf_data -> scene_obj);
	if (fdf_data -> rend_val -> display == 1)
	{
		ft_mlx_rebuild_img(fdf_data);
		fdf_data -> rend_val -> display = 0;
	}
	return (0);
}

void	ft_mlx_key_window_destroy_projection_change(
			int keycode, t_fdf_univ *univ)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(
			univ -> mlx_data -> mlx_ptr, univ -> mlx_data -> mlx_win);
		exit(0);
	}
	else if (keycode == KEY_Z && univ -> rend_val -> ortho_persp == 0)
		ft_isometric_projection(univ -> rend_val, univ -> scene_obj,
			univ -> matrix_buf, univ -> cam_pos_tf);
	else if (keycode == KEY_X)
	{
		if (univ -> rend_val -> ortho_persp == 0)
			univ -> rend_val -> ortho_persp = 1;
		else
			univ -> rend_val -> ortho_persp = 0;
	}
	else if (keycode == KEY_M)
	{
		if (univ -> rend_val -> guide_on == 0)
			univ -> rend_val -> guide_on = 1;
		else
			univ -> rend_val -> guide_on = 0;
	}
	univ -> rend_val -> display = 1;
	return ;
}

// img 리빌드 순서 - 새로운 img 만든 다음에 이전 img 제거하게 만드는게 더 안전할 듯
void	ft_mlx_rebuild_img(t_fdf_univ *fdf_data)
{
	t_fdf_img	*tmp;

	tmp = fdf_data -> mlx_data -> img;
	ft_mlx_new_img(fdf_data -> mlx_data,
		fdf_data -> rend_val -> win_xy[0], fdf_data -> rend_val -> win_xy[1]);
	ft_set_fdf_z_buffer_initial_value(fdf_data -> draw_var -> z_buffer,
		fdf_data -> rend_val -> win_xy[0], fdf_data -> rend_val -> win_xy[1]);
	ft_set_tf_matrix(fdf_data);
	ft_join_tranform_matrices(fdf_data);
	if (fdf_data -> rend_val -> guide_on == 1)
		ft_put_object_to_mlx_img(fdf_data,
			(fdf_data -> rend_val -> row) * 2 + 1,
			(fdf_data -> rend_val -> col) * 2 + 1,
			ft_put_world_guide);
	ft_put_object_to_mlx_img(fdf_data,
		fdf_data -> rend_val -> row, fdf_data -> rend_val -> col,
		ft_put_scene_object);
	mlx_clear_window(fdf_data -> mlx_data -> mlx_ptr,
		fdf_data -> mlx_data -> mlx_win);
	mlx_destroy_image(
		fdf_data -> mlx_data -> mlx_ptr, tmp);
	mlx_put_image_to_window(fdf_data -> mlx_data -> mlx_ptr,
		fdf_data -> mlx_data -> mlx_win,
		fdf_data -> mlx_data -> img -> img_ptr, 0, 0);
	return ;
}
