/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_util_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:56:51 by kshim             #+#    #+#             */
/*   Updated: 2022/11/03 12:10:15 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"

#include "../../bonus_includes/fdf_rendering_value_struct_bonus.h"
#include "../../bonus_includes/fdf_parser_struct_bonus.h"
#include "../../bonus_includes/fdf_parser_bonus.h"

#include <stdlib.h>

void	ft_fdf_free_pnt_2_arr(t_fdf_rend_val *rend_val,
	t_fdf_pnt **pnt_2_arr)
{
	int	i;

	i = 0;
	while (i < rend_val -> row)
	{
		free(pnt_2_arr[i]);
		pnt_2_arr[i] = 0;
		i++;
	}
	free(pnt_2_arr);
	pnt_2_arr = 0;
	return ;
}

void	ft_fdf_del_value_ptr(void *content)
{
	int	*value;

	value = (int *)content;
	free(value);
	return ;
}
