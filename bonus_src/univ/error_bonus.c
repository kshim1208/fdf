/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:47:26 by kshim             #+#    #+#             */
/*   Updated: 2022/11/03 12:08:54 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"

#include "../../bonus_includes/fdf_error_bonus.h"

#include <stdio.h>

void	ft_fdf_exit(char *func_name, int msg_index)
{
	char	*message[12];
	char	*err_msg;

	ft_px_set_error_message(message);
	err_msg = ft_strjoin(func_name, message[msg_index]);
	if (err_msg == 0)
	{
		perror("ft_fdf_exit");
		exit(1);
	}
	perror(err_msg);
	free(err_msg);
	exit(1);
}

void	ft_px_set_error_message(char *message[])
{
	message[FAIL_INPUT] = " : fail to input file";
	message[FAIL_OPEN_FILE] = " : fail to open()";
	message[FAIL_MEMORY_ALLOC] = " : fail to allocate memory";
	message[FAIL_GNL] = " : fail to get_next_line";
	message[FAIL_INVAL_VALUE] = " : invalid value in input file";
	message[FAIL_INPUT_LEN] = " : invalid input line length)";
	message[FAIL_ATOI] = " : fail to atoi";
	message[FAIL_HEX_ATOI] = " : fail to hex atoi";
	message[FAIL_TO_LARGE_INPUT] = " :  invalide input size";
	return ;
}
