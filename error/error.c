/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:16:40 by lpeeters          #+#    #+#             */
/*   Updated: 2023/05/11 21:03:39 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

/*error handling*/
void	err(int type)
{
	if (type == INPUT_ERR)
		ft_printf("input: Incorrect number of arguments\n");
	if (type == OPEN_ERR)
		perror("open");
	if (type == PIPE_ERR)
		perror("pipe");
	if (type == FORK_ERR)
		perror("fork");
	if (type == PATH_ENV_ERR)
		ft_printf("environment: Missing path\n");
	if (type == CMD_ERR)
		ft_printf("command: Command not found\n");
	if (type == EXECVE_ERR)
		perror("execve");
	exit(EXIT_FAILURE);
}
