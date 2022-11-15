/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:06:02 by kshim             #+#    #+#             */
/*   Updated: 2022/10/28 12:16:01 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_set_translate_matrix(float org[4], float translated[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			translated[i][j] = 0;
			j++;
		}
		i++;
	}
	translated[0][0] = 1;
	translated[1][1] = 1;
	translated[2][2] = 1;
	translated[3][3] = 1;
	translated[0][3] = org[0];
	translated[1][3] = org[1];
	translated[2][3] = org[2];
	return ;
}

void	ft_set_translate_matrix_invert(float org[4], float inverted[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			inverted[i][j] = 0;
			j++;
		}
		i++;
	}
	inverted[0][0] = 1;
	inverted[1][1] = 1;
	inverted[2][2] = 1;
	inverted[3][3] = 1;
	inverted[0][3] = -1 * org[0];
	inverted[1][3] = -1 * org[1];
	inverted[2][3] = -1 * org[2];
	return ;
}

void	ft_set_transpose_matrix(float org[4][4], float transposed[4][4])
{
	transposed[0][0] = org[0][0];
	transposed[0][1] = org[1][0];
	transposed[0][2] = org[2][0];
	transposed[0][3] = org[3][0];
	transposed[1][0] = org[0][1];
	transposed[1][1] = org[1][1];
	transposed[1][2] = org[2][1];
	transposed[1][3] = org[3][1];
	transposed[2][0] = org[0][2];
	transposed[2][1] = org[1][2];
	transposed[2][2] = org[2][2];
	transposed[2][3] = org[3][2];
	transposed[3][0] = org[0][3];
	transposed[3][1] = org[1][3];
	transposed[3][2] = org[2][3];
	transposed[3][3] = org[3][3];
	return ;
}
