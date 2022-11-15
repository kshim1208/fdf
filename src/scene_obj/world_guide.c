/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_guide.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:06:26 by kshim             #+#    #+#             */
/*   Updated: 2022/11/03 11:27:01 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"

#include "../../includes/fdf_rendering_value_struct.h"

#include "../../includes/fdf_error.h"
#include "../../includes/fdf_transform_util.h"

void	ft_init_world_guide(t_fdf_pnt ***world_guide, t_fdf_rend_val *rend_val)
{
	int	i;

	*world_guide = (t_fdf_pnt **)malloc(sizeof(
				t_fdf_pnt *) * rend_val -> guide_row);
	if (*world_guide == 0)
		ft_fdf_exit("ft_init_world_guide", FAIL_MEMORY_ALLOC);
	i = 0;
	while (i < rend_val -> guide_row)
	{
		(*world_guide)[i] = (
				t_fdf_pnt *)malloc(sizeof(
					t_fdf_pnt) * rend_val -> guide_col);
		if ((*world_guide)[i] == 0)
			ft_fdf_exit("ft_init_world_guide", FAIL_MEMORY_ALLOC);
		ft_memset((*world_guide)[i], 0, sizeof(
				t_fdf_pnt) * rend_val -> guide_col);
		i++;
	}
	return ;
}

void	ft_set_world_guide_pnt(
			t_fdf_pnt **world_guide, t_fdf_rend_val *rend_val)
{
	int	base_x;
	int	base_y;
	int	i;
	int	j;

	base_x = -1 * (rend_val -> btw_vertex * ((rend_val -> guide_col - 1) / 2));
	base_y = (rend_val -> btw_vertex * ((rend_val -> guide_row - 1) / 2));
	i = 0;
	while (i < rend_val -> guide_row)
	{
		j = 0;
		while (j < rend_val -> guide_col)
		{
			world_guide[i][j].vertex[0] = base_x + (
					j * rend_val -> btw_vertex);
			world_guide[i][j].vertex[1] = base_y - (
					i * rend_val -> btw_vertex);
			world_guide[i][j].vertex[3] = 1;
			world_guide[i][j].color = 0xFFFFFFFF;
			j++;
		}
		i++;
	}
	return ;
}
