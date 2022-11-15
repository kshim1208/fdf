/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_transform_struct_bonus.h                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:28:20 by kshim             #+#    #+#             */
/*   Updated: 2022/11/03 11:58:26 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_TRANSFORM_STRUCT_BONUS_H
# define FDF_TRANSFORM_STRUCT_BONUS_H

typedef struct s_transform_matrix{
	float		scale[4][4];
	float		rotate[4][4];
	float		translate[4][4];
}			t_tf_matrix;

typedef struct s_projetion_transform_datas{
	float	rtn[4];
	float	lbf[4];
	float	orth_scale;
	float	pers_scale;
}			t_project_tf_data;

typedef struct s_transform_matrix_data_group{
	t_tf_matrix			*obj_tf;
	t_tf_matrix			*cam_tf;
	t_project_tf_data	*prj_tf_data;
}			t_tf_data_group;	

typedef struct s_transform_matrix_all_group{
	float		obj_tf_all[4][4];
	float		cam_tf_all[4][4];
	float		prj_tf_all[4][4];
	float		viewpt_tf_all[4][4];
	float		tf_all[4][4];
}			t_tf_all_group;

#endif