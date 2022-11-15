/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx_key_operation_bonus.h                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:54:04 by kshim             #+#    #+#             */
/*   Updated: 2022/11/03 11:57:39 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_MLX_KEY_OPERATION_BONUS_H
# define FDF_MLX_KEY_OPERATION_BONUS_H

void	ft_mlx_key_ortho_scale_cam_transform_keycode(int keycode,
			t_fdf_rend_val *rend_val,
			t_fdf_matrix_buf *matrix_buf, t_tf_data_group *tf_matrices);
void	ft_mlx_key_orthographic_scale(int keycode,
			t_fdf_rend_val *rend_val, t_project_tf_data *prj_tf_data);
void	ft_mlx_key_cam_rotate(int keycode, t_fdf_rend_val *rend_val,
			t_fdf_matrix_buf *matrix_buf, t_tf_matrix *cam_tf);
void	ft_mlx_key_cam_translate(int keycode, t_fdf_rend_val *rend_val,
			t_fdf_matrix_buf *matrix_buf, t_tf_matrix *cam_tf);

void	ft_mlx_key_scene_obj_transform_keycode(int keycode,
			t_fdf_rend_val *rend_val,
			t_fdf_matrix_buf *matrix_buf, t_fdf_scene_obj *scene_obj);
void	ft_mlx_key_scene_obj_rotate(int keycode, t_fdf_rend_val *rend_val,
			t_fdf_matrix_buf *matrix_buf, t_fdf_scene_obj *scene_obj);
void	ft_mlx_key_scene_obj_scale_x_y(int keycode,
			t_fdf_rend_val *rend_val, t_fdf_scene_obj *scene_obj);
void	ft_mlx_key_scene_obj_scale_z_translate_xyz(int keycode,
			t_fdf_rend_val *rend_val, t_fdf_scene_obj *scene_obj);

#endif