/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cam_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:06:46 by kshim             #+#    #+#             */
/*   Updated: 2022/11/03 12:09:49 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../bonus_includes/fdf_rendering_value_struct_bonus.h"
#include "../../bonus_includes/fdf_scene_object_struct_bonus.h"
#include "../../bonus_includes/fdf_cam_bonus.h"

#include <math.h>

void	ft_set_right_camera(
		t_fdf_rend_val *rend_val, t_fdf_scene_obj *scene_obj)
{
	rend_val -> look_pnt[0] = scene_obj -> scene_obj_pivot[0];
	rend_val -> look_pnt[1] = scene_obj -> scene_obj_pivot[1];
	rend_val -> look_pnt[2] = scene_obj -> scene_obj_pivot[2];
	rend_val -> look_pnt[3] = 1;
	rend_val -> cam_pivot[0] = (
			scene_obj -> scene_obj_pivot[0] + rend_val -> cvv_x_y_vec[0]) * 5;
	rend_val -> cam_pivot[1] = scene_obj -> scene_obj_pivot[1];
	rend_val -> cam_pivot[2] = scene_obj -> scene_obj_pivot[2];
	rend_val -> cam_pivot[3] = 1;
	rend_val -> cam_vec_up[0] = 0;
	rend_val -> cam_vec_up[1] = 0;
	rend_val -> cam_vec_up[2] = 1;
	rend_val -> cam_vec_up[3] = 0;
	rend_val -> prev_vec_z[0] = 0;
	rend_val -> prev_vec_z[1] = 0;
	rend_val -> prev_vec_z[2] = 0;
	rend_val -> prev_vec_z[3] = 0;
	ft_calc_coordinate_vector(rend_val);
	return ;
}

void	ft_calc_coordinate_vector(t_fdf_rend_val *rend_val)
{
	ft_calc_unit_vector_2_pnt(rend_val -> look_pnt,
		rend_val -> cam_pivot, rend_val -> cam_vec_z);
	ft_calc_cross_product(rend_val -> cam_vec_up, rend_val -> cam_vec_z,
		rend_val -> cam_vec_x);
	ft_calc_unit_vector_1_vector(rend_val -> cam_vec_x);
	ft_calc_cross_product(rend_val -> cam_vec_z,
		rend_val -> cam_vec_x, rend_val -> cam_vec_y);
	ft_calc_unit_vector_1_vector(rend_val -> cam_vec_y);
	return ;
}

void	ft_calc_unit_vector_2_pnt(float from_pnt[4],
		float to_pnt[4], float u_vector[4])
{
	float	vector_len;
	float	tmp[3];

	tmp[0] = to_pnt[0] - from_pnt[0];
	tmp[1] = to_pnt[1] - from_pnt[1];
	tmp[2] = to_pnt[2] - from_pnt[2];
	vector_len = sqrt(pow(tmp[0], 2) + pow(tmp[1], 2) + pow(tmp[2], 2));
	u_vector[0] = tmp[0] / vector_len;
	u_vector[1] = tmp[1] / vector_len;
	u_vector[2] = tmp[2] / vector_len;
	u_vector[3] = 0;
	return ;
}

void	ft_calc_unit_vector_1_vector(float vec[4])
{
	float	vector_len;
	float	tmp[3];

	tmp[0] = vec[0];
	tmp[1] = vec[1];
	tmp[2] = vec[2];
	vector_len = sqrt(pow(tmp[0], 2) + pow(tmp[1], 2) + pow(tmp[2], 2));
	vec[0] = tmp[0] / vector_len;
	vec[1] = tmp[1] / vector_len;
	vec[2] = tmp[2] / vector_len;
	vec[3] = 0;
}

void	ft_calc_cross_product(float vec1[4],
		float vec2[4], float cross_product[4])
{
	cross_product[0] = (vec1[1] * vec2[2]) - (vec1[2] * vec2[1]);
	cross_product[1] = (vec1[2] * vec2[0]) - (vec1[0] * vec2[2]);
	cross_product[2] = (vec1[0] * vec2[1]) - (vec1[1] * vec2[0]);
	cross_product[3] = 0;
	return ;
}
