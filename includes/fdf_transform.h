/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_transform.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:53:47 by kshim             #+#    #+#             */
/*   Updated: 2022/11/03 12:16:45 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_TRANSFORM_H
# define FDF_TRANSFORM_H

void				ft_init_transform_matrices_group(t_fdf_univ *univ);
t_tf_matrix			*ft_allocate_transform_matrix(void);
t_fdf_matrix_buf	*ft_allocate_matrix_buffer(void);
t_project_tf_data	*ft_init_projection_transform_matrix(void);

void				ft_set_object_transform_matrix(t_fdf_scene_obj *scene_obj,
						t_fdf_matrix_buf *matrix_buf,
						t_tf_matrix *obj_tf, float obj_tf_all[4][4]);
void				ft_set_camera_transform_matrix(t_fdf_rend_val *rend_val,
						t_tf_matrix *cam_tf,
						float cam_tf_all[4][4]);
void				ft_set_ortho_projection_transform_matrix(
						t_fdf_rend_val *rend_val,
						t_project_tf_data *prj_tf_data,
						float prj_tf_all[4][4]);
void				ft_set_rtnlbf_from_cvv(t_fdf_rend_val *rend_val,
						t_project_tf_data *prj_tf_data,
						float tmp_cvv[4], float scale);
float				ft_calc_perspective_near_far(
						float look_pnt_cam[4], float cvv_z,
						int near_far);

void				ft_set_viewport_transform_matrix(t_fdf_rend_val *rend_val,
						float viewpt_tf_all[4][4]);
void				ft_join_tranform_matrices(
						t_fdf_univ *univ);

void				ft_set_tf_matrix(t_fdf_univ *univ);

#endif 