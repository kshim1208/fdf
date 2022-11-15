/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:55:09 by kshim             #+#    #+#             */
/*   Updated: 2022/11/03 12:11:36 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../bonus_includes/fdf_transform_struct_bonus.h"
#include "../../bonus_includes/fdf_matrix_buffer_struct_bonus.h"
#include "../../bonus_includes/fdf_scene_object_struct_bonus.h"
#include "../../bonus_includes/fdf_mlx_struct_bonus.h"
#include "../../bonus_includes/fdf_rendering_value_struct_bonus.h"
#include "../../bonus_includes/fdf_univ_struct_bonus.h"

#include "../../bonus_includes/fdf_mlx_bonus.h"
#include "../../bonus_includes/fdf_draw_bonus.h"
#include "../../bonus_includes/fdf_transform_util_bonus.h"

#include <math.h>

void	ft_draw_line(t_fdf_pnt *pnt1, t_fdf_pnt *pnt2,
	t_fdf_univ *univ)
{
	if (pnt1 -> vertex_tfmed[3] <= 0 || pnt2 -> vertex_tfmed[3] <= 0)
		return ;
	if (fabs(pnt2 -> vertex_tfmed[0] - pnt1 -> vertex_tfmed[0])
		> fabs(pnt2 -> vertex_tfmed[1] - pnt1 -> vertex_tfmed[1]))
	{
		if (pnt1 -> vertex_tfmed[0] < pnt2 -> vertex_tfmed[0])
			ft_draw_line_low(pnt1, pnt2, univ, univ -> draw_var);
		else
			ft_draw_line_low(pnt2, pnt1, univ, univ -> draw_var);
	}
	else
	{
		if (pnt1 -> vertex_tfmed[1] < pnt2 -> vertex_tfmed[1])
			ft_draw_line_high(pnt1, pnt2, univ, univ -> draw_var);
		else
			ft_draw_line_high(pnt2, pnt1, univ, univ -> draw_var);
	}
	return ;
}

void	ft_draw_line_low(t_fdf_pnt *pnt1, t_fdf_pnt *pnt2,
	t_fdf_univ *univ, t_fdf_draw_var *draw_var)
{
	ft_set_draw_line_variable(draw_var, pnt1, pnt2);
	if (draw_var -> height < 0)
	{
		draw_var -> sign = -1;
		draw_var -> height = -draw_var -> height;
	}
	draw_var -> baseline = draw_var -> length;
	draw_var -> mid = (2 * draw_var -> height) - draw_var -> length;
	while (draw_var -> draw_vert[0] < pnt2 -> vertex_tfmed[0])
	{
		ft_set_pixel_data_with_z_buffer(univ, pnt1, pnt2, draw_var);
		if (draw_var -> mid < 0)
			draw_var -> mid = draw_var -> mid + (2 * draw_var -> height);
		else
		{
			draw_var -> mid = draw_var -> mid
				+ (2 * draw_var -> height) - (2 * draw_var -> length);
			draw_var -> draw_vert[1] = draw_var -> draw_vert[1]
				+ draw_var -> sign;
		}
		draw_var -> draw_vert[0] = draw_var -> draw_vert[0] + 1;
	}
	return ;
}

void	ft_draw_line_high(t_fdf_pnt *pnt1, t_fdf_pnt *pnt2,
	t_fdf_univ *univ, t_fdf_draw_var *draw_var)
{
	ft_set_draw_line_variable(draw_var, pnt1, pnt2);
	if (draw_var -> length < 0)
	{
		draw_var -> sign = -1;
		draw_var -> length = -draw_var -> length;
	}
	draw_var -> baseline = draw_var -> height;
	draw_var -> mid = (2 * draw_var -> length) - draw_var -> height;
	while (draw_var -> draw_vert[1] < pnt2 -> vertex_tfmed[1])
	{
		ft_set_pixel_data_with_z_buffer(univ, pnt1, pnt2, draw_var);
		if (draw_var -> mid < 0)
			draw_var -> mid = draw_var -> mid + (2 * draw_var -> length);
		else
		{
			draw_var -> mid = draw_var -> mid
				+ (2 * draw_var -> length) - (2 * draw_var -> height);
			draw_var -> draw_vert[0] = draw_var -> draw_vert[0]
				+ draw_var -> sign;
		}
		draw_var -> draw_vert[1] = draw_var -> draw_vert[1] + 1;
	}
	return ;
}
