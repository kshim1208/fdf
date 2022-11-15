/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_util_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:08:49 by kshim             #+#    #+#             */
/*   Updated: 2022/11/03 12:09:54 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../bonus_includes/fdf_rendering_value_struct_bonus.h"

#include "../../bonus_includes/fdf_mlx_key_operation_struct_bonus.h"

void	ft_set_cam_vec_xyz(t_fdf_rend_val *rend_val, float new_cam_vec[4][4])
{
	rend_val -> cam_vec_x[0] = new_cam_vec[0][0];
	rend_val -> cam_vec_x[1] = new_cam_vec[1][0];
	rend_val -> cam_vec_x[2] = new_cam_vec[2][0];
	rend_val -> cam_vec_y[0] = new_cam_vec[0][1];
	rend_val -> cam_vec_y[1] = new_cam_vec[1][1];
	rend_val -> cam_vec_y[2] = new_cam_vec[2][1];
	rend_val -> cam_vec_z[0] = new_cam_vec[0][2];
	rend_val -> cam_vec_z[1] = new_cam_vec[1][2];
	rend_val -> cam_vec_z[2] = new_cam_vec[2][2];
	return ;
}

void	ft_set_translate_direction_vector(float tmp[4], int direction)
{
	tmp[0] = 0;
	tmp[1] = 0;
	if (direction == UP)
		tmp[1] = 5;
	else if (direction == DOWN)
		tmp[1] = -5;
	else if (direction == LEFT)
		tmp[0] = -5;
	else if (direction == RIGHT)
		tmp[0] = 5;
	tmp[2] = 0;
	tmp[3] = 0;
	return ;
}

int	ft_check_cam_can_be_translated(
		float translate[3], float tmp_translate_vec[4])
{
	translate[0] += tmp_translate_vec[0];
	translate[1] += tmp_translate_vec[1];
	translate[2] += tmp_translate_vec[2];
	if (translate[0] < -1000
		|| translate[0] > 1000
		|| translate[1] < -1000
		|| translate[1] > 1000
		|| translate[2] < -1000
		|| translate[2] > 1000)
	{
		translate[0] -= tmp_translate_vec[0];
		translate[1] -= tmp_translate_vec[1];
		translate[2] -= tmp_translate_vec[2];
		return (0);
	}
	return (1);
}
