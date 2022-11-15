/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:33:10 by kshim             #+#    #+#             */
/*   Updated: 2022/11/03 12:18:31 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf_transform_struct.h"
#include "../../includes/fdf_matrix_buffer_struct.h"
#include "../../includes/fdf_scene_object_struct.h"
#include "../../includes/fdf_mlx_struct.h"
#include "../../includes/fdf_rendering_value_struct.h"
#include "../../includes/fdf_univ_struct.h"

#include "../../includes/fdf_mlx.h"
#include "../../includes/fdf_draw.h"
#include "../../includes/fdf_transform_util.h"

void	ft_put_object_to_mlx_img(t_fdf_univ *univ,
			int row, int col, void ft_put_func(t_fdf_univ *, int, int))
{
	int				i;
	int				j;

	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			ft_put_func(univ, i, j);
			j++;
		}
		i++;
	}
	return ;
}

void	ft_put_world_guide(
			t_fdf_univ *univ, int row, int col)
{
	ft_set_world_guide_transformed(univ, &(univ -> world_guide[row][col]));
	if (row != 0)
		ft_draw_line(
			&(univ -> world_guide[row - 1][col]),
			&(univ -> world_guide[row][col]), univ);
	if (col != 0)
		ft_draw_line(
			&(univ -> world_guide[row][col - 1]),
			&(univ -> world_guide[row][col]), univ);
	return ;
}

void	ft_put_scene_object(t_fdf_univ *univ, int row, int col)
{
	ft_set_scene_object_transformed(univ, &(univ -> pnt_2_arr[row][col]));
	if (row != 0)
		ft_draw_line(
			&(univ -> pnt_2_arr[row - 1][col]),
			&(univ -> pnt_2_arr[row][col]), univ);
	if (col != 0)
		ft_draw_line(
			&(univ -> pnt_2_arr[row][col - 1]),
			&(univ -> pnt_2_arr[row][col]), univ);
	return ;
}

void	ft_set_world_guide_transformed(
			t_fdf_univ *univ, t_fdf_pnt *pnt)
{
	ft_matrix_copy_14(pnt -> vertex,
		pnt -> vertex_tfmed);
	ft_multiply_matrix_44_14(univ -> tf_all_matrices -> tf_all,
		pnt -> vertex_tfmed,
		univ -> matrix_buf -> matrix_buf_1x4);
	ft_matrix_copy_14(univ -> matrix_buf -> matrix_buf_1x4,
		pnt -> vertex_tfmed);
	return ;
}

void	ft_set_scene_object_transformed(
			t_fdf_univ *univ, t_fdf_pnt *pnt)
{
	ft_multiply_matrix_44_14(univ -> tf_all_matrices -> obj_tf_all,
		pnt -> vertex,
		univ -> matrix_buf -> matrix_buf_1x4);
	ft_matrix_copy_14(univ -> matrix_buf -> matrix_buf_1x4,
		pnt ->vertex_tfmed);
	ft_multiply_matrix_44_14(univ -> tf_all_matrices -> tf_all,
		pnt -> vertex_tfmed,
		univ -> matrix_buf -> matrix_buf_1x4);
	ft_matrix_copy_14(univ -> matrix_buf -> matrix_buf_1x4,
		pnt -> vertex_tfmed);
	return ;
}
