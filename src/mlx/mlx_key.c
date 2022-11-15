/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 13:32:18 by kshim             #+#    #+#             */
/*   Updated: 2022/11/03 12:23:17 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf_matrix_buffer_struct.h"
#include "../../includes/fdf_rendering_value_struct.h"
#include "../../includes/fdf_transform_struct.h"
#include "../../includes/fdf_scene_object_struct.h"
#include "../../includes/fdf_mlx_struct.h"
#include "../../includes/fdf_univ_struct.h"

#include "../../includes/fdf_mlx_key_define.h"
#include "../../includes/fdf_mlx_key.h"

#include "../../includes/fdf_projection.h"
#include "../../mlx/mlx.h"
#include "../../includes/fdf_draw.h"
#include "../../includes/fdf_transform.h"
#include "../../includes/fdf_mlx.h"
#include "../../includes/fdf_univ.h"
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
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(
			fdf_data -> mlx_data -> mlx_ptr, fdf_data -> mlx_data -> mlx_win);
		exit(0);
	}
	if (fdf_data -> rend_val -> display == 1)
	{
		ft_mlx_rebuild_img(fdf_data);
		fdf_data -> rend_val -> display = 0;
	}
	return (0);
}

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
