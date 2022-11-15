/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:08:22 by kshim             #+#    #+#             */
/*   Updated: 2022/10/31 15:59:12 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

void	ft_rotate_axis_x(float rotate_x[4][4], float degree)
{
	rotate_x[0][0] = 1;
	rotate_x[0][1] = 0;
	rotate_x[0][2] = 0;
	rotate_x[0][3] = 0;
	rotate_x[1][0] = 0;
	rotate_x[1][1] = cos((M_PI / 180) * degree);
	rotate_x[1][2] = sin((M_PI / 180) * degree);
	rotate_x[1][3] = 0;
	rotate_x[2][0] = 0;
	rotate_x[2][1] = -1 * sin((M_PI / 180) * degree);
	rotate_x[2][2] = cos((M_PI / 180) * degree);
	rotate_x[2][3] = 0;
	rotate_x[3][0] = 0;
	rotate_x[3][1] = 0;
	rotate_x[3][2] = 0;
	rotate_x[3][3] = 1;
	return ;
}

void	ft_rotate_axis_y(float rotate_y[4][4], float degree)
{
	rotate_y[0][0] = cos((M_PI / 180) * degree);
	rotate_y[0][1] = 0;
	rotate_y[0][2] = -1 * sin((M_PI / 180) * degree);
	rotate_y[0][3] = 0;
	rotate_y[1][0] = 0;
	rotate_y[1][1] = 1;
	rotate_y[1][2] = 0;
	rotate_y[1][3] = 0;
	rotate_y[2][0] = sin((M_PI / 180) * degree);
	rotate_y[2][1] = 0;
	rotate_y[2][2] = cos((M_PI / 180) * degree);
	rotate_y[2][3] = 0;
	rotate_y[3][0] = 0;
	rotate_y[3][1] = 0;
	rotate_y[3][2] = 0;
	rotate_y[3][3] = 1;
	return ;
}

void	ft_rotate_axis_z(float rotate_z[4][4], float degree)
{
	rotate_z[0][0] = cos((M_PI / 180) * degree);
	rotate_z[0][1] = sin((M_PI / 180) * degree);
	rotate_z[0][2] = 0;
	rotate_z[0][3] = 0;
	rotate_z[1][0] = -1 * sin((M_PI / 180) * degree);
	rotate_z[1][1] = cos((M_PI / 180) * degree);
	rotate_z[1][2] = 0;
	rotate_z[1][3] = 0;
	rotate_z[2][0] = 0;
	rotate_z[2][1] = 0;
	rotate_z[2][2] = 1;
	rotate_z[2][3] = 0;
	rotate_z[3][0] = 0;
	rotate_z[3][1] = 0;
	rotate_z[3][2] = 0;
	rotate_z[3][3] = 1;
	return ;
}
