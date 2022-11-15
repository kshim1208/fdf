/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_scene_obj_coordinate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 12:55:01 by kshim             #+#    #+#             */
/*   Updated: 2022/11/03 12:22:15 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf_scene_object_struct.h"
#include "../../includes/fdf_matrix_buffer_struct.h"
#include "../../includes/fdf_rendering_value_struct.h"
#include "../../includes/fdf_transform_struct.h"

#include "../../includes/fdf_mlx_key_define.h"

#include "../../includes/fdf_transform_rotate.h"
#include "../../includes/fdf_transform_util.h"
#include "../../includes/fdf_scene_object.h"

void	ft_set_scene_obj_pnt(t_fdf_rend_val *rend_val, t_fdf_pnt **pnt_2_arr)
{
	int	base_x;
	int	base_y;
	int	i;
	int	j;

	ft_calc_base_xy_for_scene_object(rend_val, &base_x, &base_y);
	i = 0;
	while (i < rend_val -> row)
	{
		j = 0;
		while (j < rend_val -> col)
		{
			pnt_2_arr[i][j].vertex[0] = base_x + (j * rend_val -> btw_vertex);
			pnt_2_arr[i][j].vertex[1] = base_y - (i * rend_val -> btw_vertex);
			j++;
		}
		i++;
	}
	return ;
}

void	ft_calc_base_xy_for_scene_object(t_fdf_rend_val *rend_val,
			int *base_x, int *base_y)
{
	if (rend_val -> col % 2 == 1)
		*base_x = -1 * (rend_val -> btw_vertex * (rend_val -> col - 1) / 2);
	else
		*base_x = -1 * ((rend_val -> btw_vertex * (rend_val -> col / 2))
				- (rend_val -> btw_vertex / 2));
	if (rend_val -> row % 2 == 1)
		*base_y = (rend_val -> btw_vertex * (rend_val -> row - 1) / 2);
	else
		*base_y = ((rend_val -> btw_vertex * (rend_val -> row / 2))
				- (rend_val -> btw_vertex / 2));
	return ;
}
