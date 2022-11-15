/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_transform_matrix2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:03:04 by kshim             #+#    #+#             */
/*   Updated: 2022/11/03 12:20:44 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf_transform_struct.h"
#include "../../includes/fdf_matrix_buffer_struct.h"
#include "../../includes/fdf_scene_object_struct.h"
#include "../../includes/fdf_mlx_struct.h"
#include "../../includes/fdf_rendering_value_struct.h"
#include "../../includes/fdf_univ_struct.h"

#include "../../includes/fdf_transform.h"
#include "../../includes/fdf_transform_util.h"

#include <math.h>

void	ft_set_ortho_projection_transform_matrix(t_fdf_rend_val *rend_val,
			t_project_tf_data *prj_tf_data, float prj_tf_all[4][4])
{
	float	tmp_cvv[4];

	ft_set_rtnlbf_from_cvv(
		rend_val, prj_tf_data, tmp_cvv, prj_tf_data -> orth_scale);
	prj_tf_all[0][0] = 2 / (prj_tf_data -> rtn[0] - prj_tf_data -> lbf[0]);
	prj_tf_all[0][2] = 0;
	prj_tf_all[1][1] = 2 / (prj_tf_data -> rtn[1] - prj_tf_data -> lbf[1]);
	prj_tf_all[1][2] = 0;
	prj_tf_all[2][2] = -2 / (prj_tf_data -> lbf[2] - prj_tf_data -> rtn[2]);
	prj_tf_all[0][3] = -1 * (((prj_tf_data -> rtn[0] + prj_tf_data -> lbf[0]))
			/ (prj_tf_data -> rtn[0] - prj_tf_data -> lbf[0]));
	prj_tf_all[1][3] = -1 * (((prj_tf_data -> rtn[1] + prj_tf_data -> lbf[1]))
			/ (prj_tf_data -> rtn[1] - prj_tf_data -> lbf[1]));
	prj_tf_all[2][3] = -1 * (((prj_tf_data -> rtn[2] + prj_tf_data -> lbf[2]))
			/ (prj_tf_data -> lbf[2] - prj_tf_data -> rtn[2]));
	prj_tf_all[3][2] = 0;
	prj_tf_all[3][3] = 1;
	return ;
}

void	ft_set_rtnlbf_from_cvv(t_fdf_rend_val *rend_val,
			t_project_tf_data *prj_tf_data, float tmp_cvv[4], float scale)
{
	tmp_cvv[0] = rend_val -> cvv_x_y_vec[0] * scale;
	tmp_cvv[1] = rend_val -> cvv_x_y_vec[1] * scale;
	tmp_cvv[2] = rend_val -> cvv_x_y_vec[2];
	tmp_cvv[3] = 0;
	prj_tf_data -> rtn[0] = rend_val -> look_pnt_cam[0] + tmp_cvv[0];
	prj_tf_data -> rtn[1] = rend_val -> look_pnt_cam[1] + tmp_cvv[1];
	prj_tf_data -> rtn[2] = ft_calc_perspective_near_far
		(rend_val -> look_pnt_cam, tmp_cvv[2], 0);
	prj_tf_data -> rtn[3] = 1;
	prj_tf_data -> lbf[0] = rend_val -> look_pnt_cam[0] - tmp_cvv[0];
	prj_tf_data -> lbf[1] = rend_val -> look_pnt_cam[1] - tmp_cvv[1];
	prj_tf_data -> lbf[2] = ft_calc_perspective_near_far
		(rend_val -> look_pnt_cam, tmp_cvv[2], 1);
	prj_tf_data -> lbf[3] = 1;
	return ;
}

float	ft_calc_perspective_near_far(float look_pnt_cam[4],
			float cvv_z, int near_far)
{
	float	tmp[4];

	tmp[0] = look_pnt_cam[0];
	tmp[1] = look_pnt_cam[1];
	if (near_far == 0)
		tmp[2] = look_pnt_cam[2] + cvv_z;
	else
		tmp[2] = look_pnt_cam[2] - cvv_z;
	tmp[3] = 1;
	return (sqrt(pow(tmp[0], 2)
			+ pow(tmp[1], 2) + pow(tmp[2], 2)));
}
