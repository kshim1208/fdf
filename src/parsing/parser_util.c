/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:56:51 by kshim             #+#    #+#             */
/*   Updated: 2022/10/30 16:52:42 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"

#include "../../includes/fdf_rendering_value_struct.h"
#include "../../includes/fdf_parser_struct.h"
#include "../../includes/fdf_parser.h"
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
