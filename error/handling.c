/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:16:40 by lpeeters          #+#    #+#             */
/*   Updated: 2023/05/16 21:01:26 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

/*error handling*/

void	err(int type)
{
	if (type == INPUT_ERR)
		ft_printf("input: Incorrect number of arguments\n");
	else if (type == OPEN_ERR)
		perror("open");
	else if (type == PIPE_ERR)
		perror("pipe");
	else if (type == FORK_ERR)
		perror("fork");
	else if (type == PATH_ENV_ERR)
		ft_printf("environment: Missing path\n");
	else if (type == CMD_ERR)
		perror("command");
	else if (type == EXECVE_ERR)
		perror("execve");
	else
		ft_printf("unkown error type\n");
	exit(EXIT_FAILURE);
}

/*memory handling*/

void	mem(char **array, int type)
{
	if (type == DIRS_MEM)
		free_arr(array);
	exit(EXIT_FAILURE);
}
