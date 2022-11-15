/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_cam.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:11:55 by kshim             #+#    #+#             */
/*   Updated: 2022/10/31 18:16:53 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_CAM_H
# define FDF_CAM_H

void	ft_set_right_camera(
			t_fdf_rend_val *rend_val, t_fdf_scene_obj *scene_obj);
void	ft_calc_coordinate_vector(t_fdf_rend_val *rend_val);
void	ft_calc_unit_vector_2_pnt(float from_pnt[4],
			float to_pnt[4], float u_vector[4]);
void	ft_calc_unit_vector_1_vector(float vec[4]);
void	ft_calc_cross_product(float vec1[4],
			float vec2[4], float cross_product[4]);
void	ft_is_up_vector_reversed(float prev_vec_z_z,
			float cam_vec_z_z, float cam_vec_up[4]);

#endif