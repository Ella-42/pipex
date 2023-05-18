/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:16:40 by lpeeters          #+#    #+#             */
/*   Updated: 2023/05/17 19:23:08 by lpeeters         ###   ########.fr       */
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

void	memerr(char **array, int type, int error)
{
	if (type == EXECVE_MEM)
		free_arr(array);
	if (err == EXIT)
		exit(EXIT_FAILURE);
	else if (error == EXECVE_ERR)
		err(EXECVE_ERR);
}
