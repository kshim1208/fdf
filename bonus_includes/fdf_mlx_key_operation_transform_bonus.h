/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx_key_operation_transform_bonus.h            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:47:38 by kshim             #+#    #+#             */
/*   Updated: 2022/11/03 11:57:51 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_MLX_KEY_OPERATION_TRANSFORM_BONUS_H
# define FDF_MLX_KEY_OPERATION_TRANSFORM_BONUS_H

void	ft_cam_rotate_xyz(t_fdf_rend_val *rend_val,
			t_fdf_matrix_buf *matrix_buf, t_tf_matrix *cam_tf,
			int rotate_axis);
void	ft_cam_rotate_set_rotation_matrix(
			t_fdf_matrix_buf *matrix_buf, int rotate_axis);
void	ft_set_cam_vec_xyz(t_fdf_rend_val *rend_val, float new_cam_vec[4][4]);

void	ft_cam_translate(t_fdf_rend_val *rend_val,
			t_fdf_matrix_buf *matrix_buf, t_tf_matrix *cam_tf,
			int direction);
void	ft_set_translate_direction_vector(float tmp[4], int direction);
int		ft_check_cam_can_be_translated(
			float translate[3], float tmp_translate_vec[4]);

void	ft_scene_obj_rotate_xyz(t_fdf_matrix_buf *matrix_buf,
			t_fdf_scene_obj *scene_obj, int rotate_axis);
void	ft_scene_obj_translate_xyz(t_fdf_scene_obj *scene_obj, int direction);
void	ft_scene_obj_scale_xyz(t_fdf_scene_obj *scene_obj, int scale_axis);

#endif