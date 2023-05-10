/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:51:03 by lpeeters          #+#    #+#             */
/*   Updated: 2023/05/10 19:42:15 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	int	fd0;
	int	fd1;

	if (ac < 5)
		exit(-1);
	fd0 = open(av[1], O_RDONLY);
	fd1 = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd0 < 0 || fd1 < 0)
		return (-1);
	close(fd0);
	close(fd1);
	return (0);
}
