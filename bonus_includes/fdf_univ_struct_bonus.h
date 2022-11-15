/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_univ_struct_bonus.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:42:04 by kshim             #+#    #+#             */
/*   Updated: 2022/11/03 11:58:44 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_UNIV_STRUCT_BONUS_H
# define FDF_UNIV_STRUCT_BONUS_H

// camera_pos_tf는 따로 두고, obj_tf, camera_tf proj_tf, viewport_tf는 묶는게 나을 것 같다.
// tf_all들은 tf_matrices들에 정의됨.
typedef struct s_fdf_universal_datas{
	t_fdf_mlx			*mlx_data;
	t_fdf_rend_val		*rend_val;
	t_fdf_scene_obj		*scene_obj;
	t_fdf_pnt			**pnt_2_arr;
	t_fdf_pnt			**world_guide;
	t_tf_all_group		*tf_all_matrices;
	t_tf_data_group		*tf_matrices;
	t_tf_matrix			*cam_pos_tf;
	t_fdf_matrix_buf	*matrix_buf;
	t_fdf_draw_var		*draw_var;
}		t_fdf_univ;

#endif